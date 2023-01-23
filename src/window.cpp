#include "window.hpp"

Window::Window() {
    setFixedSize(200, 100);

    scene = new QGraphicsScene(10, 10, 180, 80);
    title = new QGraphicsTextItem("Hello there");
    
    qreal width = title->boundingRect().width();

//    title->setPlainText(QString::number(width));

    scene->setBackgroundBrush(Qt::black);
    
    scene->addItem(title);
    title->setDefaultTextColor(Qt::white);
    title->setPos(100 - width / 2, 0);

    setScene(scene);
}
