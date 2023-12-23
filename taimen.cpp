#include "taimen.hpp"
#include <QTimer>
#include <QApplication>
#include <QPalette>
#include <QGridLayout>

constexpr int screen_width = 480;
constexpr int screen_height = 640;
constexpr int first_split_index = 0;
constexpr int font_pixel_size = 20;
constexpr int title_height = 50;
constexpr int main_timer_height = 50;
constexpr int n_of_split_displays = 3;

Taimen::Taimen(QWidget* parent) 
    : QWidget(parent) {

    setFixedSize(screen_width, screen_height);

    setContentsMargins(0, 0, 0, 0);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    QFont font("Helvetica");
    font.setPixelSize(font_pixel_size);
    setFont(font);

    QGridLayout* grid_layout = new QGridLayout(this);

    QLabel* title = new QLabel("Hello there");
    title->setFixedHeight(title_height);
    grid_layout->addWidget(title, 0, 0, Qt::AlignCenter);

    main_timer_display = new QLabel(main_timer.current_time_string());
    main_timer_display->setFixedHeight(main_timer_height);
    grid_layout->addWidget(main_timer_display, 2, 0, Qt::AlignCenter);

    //QFrame* split_frame = new QFrame(this);
    //split_frame->setStyleSheet("background-color: rgb(50, 50, 50)");
    //split_frame->setGeometry(0, split_pixel_height, screen_width, split_pixel_height);

    current_split = first_split_index;
    Split split1(QString("Split 1"), std::chrono::nanoseconds(61000000000));
    splits.emplace_back(split1);
    Split split2(QString("Split 2"), std::chrono::nanoseconds(178000000000));
    splits.emplace_back(split2);
    Split split3(QString("Split 3"), std::chrono::nanoseconds(219000000000));
    splits.emplace_back(split3);

    QGridLayout* split_layout = new QGridLayout();
    grid_layout->setContentsMargins(0, 0, 0, 0);
    split_layout->setContentsMargins(0, 0, 0, 0);
    grid_layout->addLayout(split_layout, 1, 0);
    grid_layout->setRowStretch(1, 1);

    for (size_t i = 0; i < splits.size(); ++i) {
        SplitDisplay* split_display = new SplitDisplay(splits[i].name, splits[i].best_time, c_nanosec(-7875000000000), i == current_split);
        split_layout->addWidget(split_display, i, 0);
    }
    split_layout->setRowStretch(4, 1);

    connect(&timer_updater, SIGNAL(timeout()), this, SLOT(update_timer()));
}

void Taimen::start_timer() {
    main_timer.start();
    timer_updater.start(1);
}

void Taimen::stop_timer() {
    timer_updater.stop();
    main_timer.stop();
    main_timer_display->setText(main_timer.current_time_string());
}

void Taimen::update_timer() {
    main_timer.update();
    main_timer_display->setText(main_timer.current_time_string());
}

void Taimen::keyPressEvent(QKeyEvent* event) {
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
