#ifndef MAIN_TIMER_HPP
#define MAIN_TIMER_HPP

#include <chrono>
#include <QString>

using c_nanosec = std::chrono::nanoseconds;

class MainTimer {
    public:
        MainTimer();
        void start();
        void stop();
        void update();
        void reset();
        QString current_time_string() const;
        bool is_started = false;

    private:
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        c_nanosec elapsed_time;
};

c_nanosec c_zero();
QString to_2digit_string(const int time_value);
QString nanoseconds_to_time_string(const c_nanosec& nanoseconds);

#endif // MAIN_TIMER_HPP
