#ifndef PROCESSINFO_H
#define PROCESSINFO_H

#include "worker.h"

struct ProcessInfo
{
    ProcessInfo(QString funcName, double value):
        funcName(funcName), value(value) {}

    QString funcName = "-";
    double value = 0;
    Worker* worker = nullptr;
    bool isPaused = false;
    bool isStopped = false;
    QString status = "Не начат";
};

#endif // PROCESSINFO_H
