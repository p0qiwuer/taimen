#include "window.hpp"
#include <QTimer>
#include <QApplication>
#include <QPalette>
#include <iostream> // temp

Window::Window(QWidget* parent) 
    : QWidget(parent) {
    constexpr int screen_width = 480;
    constexpr int screen_height = 640;

    setFixedSize(screen_width, screen_height);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    QLabel* title = new QLabel("Hello there", this);
    title->setGeometry(0, 0, screen_width, 30);
    title->setAlignment(Qt::AlignCenter);

    main_timer_display = new QLabel("00:00:00.00", this);
    main_timer_display->setGeometry(0, 0, 100, 30);

    connect(&timer_updater, SIGNAL(timeout()), this, SLOT(update_timer()));

}

void Window::start_timer() {
    main_timer.start();
    timer_updater.start(1);
}

void Window::stop_timer() {
    timer_updater.stop();
    main_timer.stop();
    main_timer_display->setText(main_timer.current_time_string());
}

void Window::update_timer() {
    main_timer.update();
    main_timer_display->setText(main_timer.current_time_string());
}

void Window::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return) {
        if (main_timer.is_started)
            stop_timer();
        else
            start_timer();
    } else if (event->key() == Qt::Key_Space) {

    } else if (event->key() == Qt::Key_Backspace) {
        if (!main_timer.is_started) {
            main_timer.reset();
            main_timer_display->setText("00:00:00.00");
        }
    } else if (event->key() == Qt::Key_Escape) {
        QApplication::instance()->quit();
    } else {
        QWidget::keyPressEvent(event);
    }
}
