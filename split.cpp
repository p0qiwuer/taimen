#include "split.hpp"

Split::Split(const QString& other_name, const c_nanosec& other_best_time) : 
    name(other_name),
    best_time(other_best_time),
    current_time(c_zero())
{}

SplitDisplay::SplitDisplay(
    const QString& name,
    const c_nanosec& time,
    const c_nanosec& difference
) {
    name_label = new QLabel(name);
    time_label = new QLabel(nanoseconds_to_time_string(time));
    difference_label = new QLabel(nanoseconds_to_time_string(difference));

    name_label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    time_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    difference_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}
