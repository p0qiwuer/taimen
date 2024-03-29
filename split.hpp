#ifndef SPLIT_HPP
#define SPLIT_HPP

#include "main_timer.hpp"
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>

struct Split {
    Split(const QString& other_name, const c_nanosec& other_best_time, const c_nanosec& other_personal_best_run_time);
    const QString name;
    c_nanosec best_time;
    c_nanosec personal_best_run_time;
    c_nanosec current_time;
};

class SplitDisplay: public QWidget {
    public:
        SplitDisplay(
            const QString& name, 
            const c_nanosec& time, 
            const c_nanosec& difference,
            const bool is_current_split = false,
            QWidget* parent = nullptr
        );
        SplitDisplay(const SplitDisplay& other);
        ~SplitDisplay();
        SplitDisplay& operator=(const SplitDisplay& other);

    private:
        QLabel* name_label;
        QLabel* time_label;
        QLabel* difference_label;
        QGridLayout* grid;
};

#endif // SPLIT_HPP
