#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "split.hpp"
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
#include <vector>

// The main window will be QGraphicsView object since it's the only window there will be
class Window : public QWidget { 
    Q_OBJECT
    public:
        explicit Window(QWidget* parent = nullptr);

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

#endif // WINDOW_HPP
