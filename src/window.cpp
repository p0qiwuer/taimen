#include "window.hpp"
#include <QTimer>

Window::Window() {
    constexpr int screen_width = 480;
    constexpr int screen_height = 640;

    setFixedSize(screen_width, screen_height);

    scene = new QGraphicsScene(10, 10, screen_width - 20, screen_height - 20);
    scene->setBackgroundBrush(Qt::black);

    QGraphicsTextItem* title = new QGraphicsTextItem("Hello there");
    title->setDefaultTextColor(Qt::white);
    qreal title_width = title->boundingRect().width();
    title->setPos(screen_width / 2 - title_width / 2, 0); // Center the title

    main_timer_display = new QGraphicsTextItem("00:00:00.00");
    main_timer_display->setDefaultTextColor(Qt::white);
    main_timer_display->setPos(0, 70);

    scene->addItem(title);
    scene->addItem(main_timer_display);
    setScene(scene);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    timer->start(1);
}

void Window::update_timer() {
    if (main_timer.started) {
        main_timer.update();
        main_timer_display->setPlainText(main_timer.current_time_string());
    }
}

void Window::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return) {
        main_timer.start();
    } else {
        QGraphicsView::keyPressEvent(event);
    }
}
