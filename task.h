#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <QString>
#include <QDate>

struct Task
{
    friend class TaskFileReader;
public:
    enum Type : uint8_t{
        TASK,
        MILESTONE,
        SUMMARY
    };

private:
    int id;
    enum Type type;

    QString name;
    QDate start;
    QDate finish;

public:
    Task();
};

#endif // TASK_H
