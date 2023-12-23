#ifndef SPLIT_HPP
#define SPLIT_HPP

#include "main_timer.hpp"
#include <QString>
#include <QLabel>

struct Split {

    Split(const QString& other_name, const c_nanosec& other_best_time);
    const QString name;
    c_nanosec best_time;
    c_nanosec current_time;
};

class SplitDisplay {
    public:
        SplitDisplay(
            const QString& name, 
            const c_nanosec& time, 
            const c_nanosec& difference
        );

    private:
        QLabel* name_label;
        QLabel* time_label;
        QLabel* difference_label;
};

#endif // SPLIT_HPP
