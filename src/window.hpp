#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "split.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <vector>

// The main window will be QGraphicsView object since it's the only window there will be
class Window : public QGraphicsView { 
    Q_OBJECT
    public:
        explicit Window();
    private:
        QGraphicsScene* scene;
        QGraphicsTextItem* title;
        std::vector<Split> splits;
};

#endif // WINDOW_HPP
