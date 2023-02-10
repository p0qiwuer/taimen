#include "split.hpp"

Split::Split(QString other_name, std::chrono::milliseconds other_best_time) : name(other_name), best_time(other_best_time) {}

void MainTimer::start() {
    start_time = std::chrono::steady_clock::now() - elapsed_time;    
    is_started = true;
}

void MainTimer::stop() {
    update();
    is_started = false;
}

void MainTimer::update() {
    elapsed_time = std::chrono::steady_clock::now() - start_time;
}

void MainTimer::reset() {
    elapsed_time = std::chrono::nanoseconds::zero();
}

QString MainTimer::current_time_string() const {
    std::chrono::milliseconds elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time);
    int hours = elapsed_time_ms.count() / 3600000; // 1 hour = 3 600 000 milliseconds, 1 minute = 60 000 milliseconds etc
    int remaining = elapsed_time_ms.count() % 3600000;    
    int minutes = remaining / 60000;
    remaining = remaining % 60000;
    int seconds = remaining / 1000;
    remaining = (remaining % 1000) / 10; //centiseconds
    return to_2digit_string(hours) + ":" 
        + to_2digit_string(minutes) + ":"
        + to_2digit_string(seconds) + "."
        + to_2digit_string(remaining);
}

QString to_2digit_string(const int time_value) {
    if (time_value >= 10)
        return QString::number(time_value);
    else
        return "0" + QString::number(time_value);
}
