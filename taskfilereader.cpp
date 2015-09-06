#ifdef WIN32
    #include <WinSock2.h>
#else

#endif

#include "taskfilereader.h"
#include "task.h"

#include <stdint.h>
#include <exception>

#define MAGIC_NUMBER 0xa1b2c3d4
#define MAGIC_NUMBER_INVERTED 0xd4c3b2a1

static bool checkMagicNumber(FILE* file)
{
    uint32_t magicNumber;
    if(1 != ::fread(&magicNumber, sizeof(magicNumber), 1, file))
        throw std::exception("Error on reading file");
    if(magicNumber == MAGIC_NUMBER)
        return true;
    if(magicNumber == MAGIC_NUMBER_INVERTED)
        return false;
    throw std::exception("Bad Magic Number");
}

TaskFileReader::TaskFileReader(const QString& path)
{
    file = ::fopen(path.toUtf8().constData(), "rb");
    diffEndian = checkMagicNumber(file);
}

struct Task& TaskFileReader::operator >>(struct Task& task)
{
    static QDate dateStart(1970, 1, 1);

#pragma pack(push,1)
    struct
    {
        uint32_t id;
        uint16_t startDays;
        uint16_t finishDays;
        uint8_t type;

        void convert()
        {
            id = ntohl(id);
            startDays = ntohs(startDays);
            finishDays = ntohs(finishDays);
        }
    } hdr;

    static_assert(sizeof(hdr) == 9, "check struct size");
#pragma pack(pop)

    if (1 != ::fread(&hdr, sizeof(hdr), 1, file))
        throw std::exception("Error on reading file");

    if(diffEndian)
        hdr.convert();

    task.id = (int)hdr.id;
    task.type = (Task::Type)hdr.type;
    task.start = dateStart.addDays(hdr.startDays);
    task.finish = dateStart.addDays(hdr.finishDays);

    return task;
}

