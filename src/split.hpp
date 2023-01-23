#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <chrono>
#include <QString>

struct Split {
    Split(QString other_name, std::chrono::milliseconds other_best_time);
    const QString name;
    std::chrono::milliseconds best_time;
};

#endif // SPLIT_HPP
