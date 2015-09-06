#ifndef TASKFILEREADER_H
#define TASKFILEREADER_H

#include <QString>
#include <stdio.h>
#include <stdint.h>

struct Task;

class TaskFileReader
{
public:
private:
    FILE* file;
    bool diffEndian;
public:
    TaskFileReader(const QString& path);

    struct Task& operator >>(struct Task& task);
};

#endif // TASKFILEREADER_H
