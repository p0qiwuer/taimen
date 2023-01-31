#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "split.hpp"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <vector>

// The main window will be QGraphicsView object since it's the only window there will be
class Window : public QGraphicsView { 
    Q_OBJECT
    public:
        explicit Window();
    private slots:
        void update_timer();
    private:
        void keyPressEvent(QKeyEvent* event);
        QGraphicsScene* scene;
        std::vector<Split> splits;
        MainTimer main_timer;
        QGraphicsTextItem* main_timer_display;
};

#endif // WINDOW_HPP
