#ifndef TAIMEN_HPP
#define TAIMEN_HPP

#include "split.hpp"
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
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
        void keyPressEvent(QKeyEvent* event);
        std::vector<Split> splits;
        MainTimer main_timer;
        QLabel* main_timer_display;
        QTimer timer_updater;
};

#endif // TAIMEN_HPP
