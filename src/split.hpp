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
        void update();
        QString current_time_string();

        bool started = false;
    private:
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::milliseconds elapsed_time;
};

#endif // SPLIT_HPP
