#include "worker.h"

Worker::Worker(QString func, double value):
    func(func), value(value) {}


void Worker::pause(bool paused) {
    this->paused = paused;
}


void Worker::stop() {
    this->stopped = true;
}

// --------------------------------------------------------

void Worker::run() {
    emit statusUpdated("Запущен");

    for (int i = 0; i < 100; i++) {
        if (stopped) {
            emit statusUpdated("Остановлен");
            break;
        }

        while (paused)
            msleep(1000);


        if (func == "Факториал") {
            // тут функция факториала
            msleep(100);
        }
        else if (func == "Синус") {
            // тут функция факториала
            msleep(50);
        }

        emit progressUpdated(i + 1);
    }

    if (!stopped)
        emit statusUpdated("Выполнен");

    emit finished();
}
