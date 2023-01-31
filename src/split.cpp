#include "split.hpp"

Split::Split(QString other_name, std::chrono::milliseconds other_best_time) : name(other_name), best_time(other_best_time) {}

void MainTimer::start() {
    start_time = std::chrono::steady_clock::now();    
    started = true;
}

void MainTimer::update() {
    auto diff = std::chrono::steady_clock::now() - start_time;
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
}

QString MainTimer::current_time_string() {
    int hours = elapsed_time.count() / 3600000; // 1 hour = 3 600 000 milliseconds, 1 minute = 60 000 milliseconds etc
    int remaining = elapsed_time.count() % 3600000;    
    int minutes = remaining / 60000;
    remaining = remaining % 60000;
    int seconds = remaining / 1000;
    remaining = remaining % 1000;
    return QString::number(hours) + ":" 
        + QString::number(minutes) + ":"
        + QString::number(seconds) + "."
        + QString::number(remaining);
}
