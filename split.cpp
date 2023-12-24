#include "split.hpp"
#include <QPalette>
#include <iostream>

Split::Split(const QString& other_name, const c_nanosec& other_best_time, const c_nanosec& other_personal_best_run_time) : 
    name(other_name),
    best_time(other_best_time),
    personal_best_run_time(other_personal_best_run_time),
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
    if (difference != c_zero())
        difference_label = new QLabel(time_difference_to_time_string(difference));
    else
        difference_label = new QLabel("");

    name_label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    time_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    difference_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    grid = new QGridLayout();
    grid->addWidget(name_label, 0, 0);
    grid->addWidget(time_label, 0, 2);
    grid->addWidget(difference_label, 0, 1);
    grid->setContentsMargins(0, 0, 0, 0);

    setLayout(grid);
}

SplitDisplay::SplitDisplay(const SplitDisplay& other) : 
    name_label(other.name_label),
    time_label(other.time_label),   
    difference_label(other.difference_label),
    grid(other.grid)
{}

SplitDisplay::~SplitDisplay() {
    delete name_label;
    delete time_label;
    delete difference_label;
    delete grid;
}

SplitDisplay& SplitDisplay::operator=(const SplitDisplay& other) {
    name_label = other.name_label;    
    time_label = other.time_label;    
    difference_label = other.difference_label;    
    grid = other.grid;
    return *this;
}
