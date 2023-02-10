#ifndef SPLIT_HPP
#define SPLIT_HPP

// Class defitions for Split and MainTimer

#include <chrono>
#include <QString>

struct Split {
    Split(QString other_name, std::chrono::milliseconds other_best_time);
    const QString name;
    std::chrono::milliseconds best_time;
};

class MainTimer {
    public:
        void start();
        void stop();
        void update();
        void reset();
        QString current_time_string() const;
        bool is_started = false;

    private:
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::nanoseconds elapsed_time = std::chrono::nanoseconds::zero();
};

QString to_2digit_string(const int time_value);

#endif // SPLIT_HPP
