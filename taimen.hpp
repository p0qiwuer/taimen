#ifndef TAIMEN_HPP
#define TAIMEN_HPP

#include "split.hpp"
#include "main_timer.hpp"
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
#include <QGridLayout>
#include <vector>

class Taimen: public QWidget { 
    Q_OBJECT
    public:
        explicit Taimen(QWidget* parent = nullptr);

    public slots:
        void update_timer();

    private:
        void start_timer();
        void stop_timer();
        void reset_timer();
        void update_splits();
        void handle_splitting();
        void finish_run();
        void keyPressEvent(QKeyEvent* event);
        std::vector<Split> splits;
        std::vector<SplitDisplay*> split_displays;
        std::vector<c_nanosec> cumulative_best_run_times;
        std::vector<c_nanosec> cumulative_run_times;
        MainTimer main_timer;
        QLabel* main_timer_display;
        QGridLayout* grid_layout;
        QGridLayout* split_layout;
        QTimer timer_updater;
        int current_split;
};

#endif // TAIMEN_HPP
