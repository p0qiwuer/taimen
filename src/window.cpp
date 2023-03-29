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

    QFont font("Helvetica");
    font.setPixelSize(20);
    std::cout << font.pixelSize() << "\n";
    setFont(font);

    QLabel* title = new QLabel("Hello there", this);
    title->setGeometry(0, 0, screen_width, 30);
    title->setAlignment(Qt::AlignCenter);

    main_timer_display = new QLabel(main_timer.current_time_string(), this);
    main_timer_display->setGeometry(0, screen_height - 30, screen_width, 30);
    main_timer_display->setAlignment(Qt::AlignCenter);

    QFrame* split_frame = new QFrame(this);
    split_frame->setStyleSheet("background-color: rgb(50, 50, 50)");
    split_frame->setGeometry(0, 30, screen_width, 30);

    Split split1(QString("Split 1"), std::chrono::nanoseconds(61000000000));
    splits.emplace_back(split1);
    Split split2(QString("Split 2"), std::chrono::nanoseconds(178000000000));
    splits.emplace_back(split2);
    for (size_t i = 0; i < splits.size(); ++i) {
        QLabel* split_name = new QLabel(splits[i].name, this);
        split_name->setGeometry(0, (i + 1) * 30, screen_width / 2, 30);
        split_name->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        QLabel* split_time = new QLabel(nanoseconds_to_time_string(splits[i].best_time), this);
        split_time->setGeometry(screen_width / 2, (i + 1) * 30, screen_width / 2, 30);
        split_time->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

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
            main_timer_display->setText(main_timer.current_time_string());
        }
    } else if (event->key() == Qt::Key_Escape) {
        QApplication::instance()->quit();
    } else {
        QWidget::keyPressEvent(event);
    }
}

