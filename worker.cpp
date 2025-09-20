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

    long long resultNum = 0;

    if (func == "Вычисление числа Фибоначчи") {
        int num  = static_cast<int>(value);


        if (num == 0 or num == 1) {
            emit progressUpdated(100);
            emit statusUpdated("Результат: " + QString::number(num));
            emit finished();
            return;
        }

        long long prev = 0, current = 1, next;

        for (int i = 2; i <= num; i++) {
            next = prev + current;
            prev = current;
            current = next;

            int progress = static_cast<int>((i - 1.0) / num * 100);
            emit progressUpdated(progress > 100 ? 100 : progress);
            msleep(50);


            if (stopped) {
                emit statusUpdated("Остановлен");
                break;
            }

            while (paused)
                msleep(1000);
        }
        resultNum = current;

    }
    else if (func == "Задержка 100мс") {
        for (int i = 0; i < 100; i++) {
            if (stopped) {
                emit statusUpdated("Остановлен");
                break;
            }

            while (paused)
                msleep(1000);

            msleep(100);

            emit progressUpdated(i + 1);
        }
    }

    if (!stopped) {
        emit statusUpdated("Результат: " + QString::number(resultNum));
        emit progressUpdated(100);
    }
    emit finished();
}
