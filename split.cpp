#include "split.hpp"
#include <QPalette>

Split::Split(const QString& other_name, const c_nanosec& other_best_time) : 
    name(other_name),
    best_time(other_best_time),
    current_time(c_zero())
{}

SplitDisplay::SplitDisplay(
    const QString& name,
    const c_nanosec& time,
    const c_nanosec& difference,
    const bool is_current_split, 
    QWidget* parent
) {
    if (is_current_split) {
        QPalette pal = QPalette();
        pal.setColor(QPalette::Window, QColor(50, 50, 50));
        setAutoFillBackground(true);
        setPalette(pal);
    }

    name_label = new QLabel(name);
    time_label = new QLabel(time_to_time_string(time));
    difference_label = new QLabel(time_difference_to_time_string(difference));

    name_label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    time_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    difference_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    grid = new QGridLayout();
    grid->addWidget(name_label, 0, 0);
    grid->addWidget(difference_label, 0, 1);
    grid->addWidget(time_label, 0, 2);

    setLayout(grid);
}
