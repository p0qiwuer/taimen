#include "taimen.hpp"
#include <QTimer>
#include <QApplication>
#include <QPalette>


Taimen::Taimen(QWidget* parent) 
    : QWidget(parent) {

    constexpr int screen_width = 480;
    constexpr int screen_height = 640;
    constexpr int font_pixel_size = 20;
    constexpr int title_height = 50;
    constexpr int main_timer_height = 50;

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

    grid_layout = new QGridLayout(this);

    QLabel* title = new QLabel("Hello there");
    title->setFixedHeight(title_height);
    grid_layout->addWidget(title, 0, 0, Qt::AlignCenter);

    main_timer_display = new QLabel(main_timer.current_time_string());
    main_timer_display->setFixedHeight(main_timer_height);
    grid_layout->addWidget(main_timer_display, 2, 0, Qt::AlignCenter);

    current_split = 0;
    Split split1(QString("Split 1"), c_nanosec(61000000000), c_nanosec(51000000000));
    splits.emplace_back(split1);
    Split split2(QString("Split 2"), c_nanosec(178000000000), c_nanosec(158000000000));
    splits.emplace_back(split2);
    Split split3(QString("Split 3"), c_nanosec(219000000000), c_nanosec(216000000000));
    splits.emplace_back(split3);

    c_nanosec cumulative_best_run_time = c_zero();
    for (size_t i = 0; i < splits.size(); ++i) {
        cumulative_best_run_time += splits[i].best_time;
        cumulative_best_run_times.emplace_back(cumulative_best_run_time);
        cumulative_run_times.emplace_back(cumulative_best_run_time);
    }

    split_layout = new QGridLayout();
    grid_layout->setContentsMargins(0, 0, 0, 0);
    split_layout->setContentsMargins(0, 0, 0, 0);
    grid_layout->addLayout(split_layout, 1, 0);
    grid_layout->setRowStretch(1, 1);

    update_splits();

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

void Taimen::reset_timer() {
    main_timer.reset();
    main_timer_display->setText(main_timer.current_time_string());
    current_split = 0;
    cumulative_run_times = std::vector<c_nanosec>(cumulative_best_run_times);
    update_splits();
}

void Taimen::update_splits() {
    for (size_t i = 0; i < split_displays.size(); ++i) {
        delete split_displays[i];
    }
    split_displays = {};
    for (size_t i = 0; i < splits.size(); ++i) {
        SplitDisplay* split_display = new SplitDisplay(
            splits[i].name, 
            cumulative_run_times[i], 
            cumulative_run_times[i] - cumulative_best_run_times[i], 
            i == current_split);
        split_displays.emplace_back(split_display);
        split_layout->addWidget(split_display, i, 0);
    }
    split_layout->setRowStretch(split_displays.size() + 1, 1);
}

void Taimen::handle_splitting() {
    const c_nanosec elapsed_time = main_timer.current_time();
    cumulative_run_times[current_split] = elapsed_time;
    if (current_split > 0)
        splits[current_split].current_time = elapsed_time - cumulative_run_times[current_split - 1];
    else
        splits[current_split].current_time = elapsed_time;
    ++current_split;
    update_splits();
    if (current_split == splits.size())
        finish_run();
}

void Taimen::finish_run() {
    stop_timer();
}

void Taimen::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return) {
        if (main_timer.is_started)
            stop_timer();
        else if (current_split != splits.size())
            start_timer();
    } else if (event->key() == Qt::Key_Space) {
        if (main_timer.is_started)
            handle_splitting();
    } else if (event->key() == Qt::Key_Backspace) {
        if (!main_timer.is_started) {
            reset_timer();
        }
    } else if (event->key() == Qt::Key_Escape) {
        QApplication::instance()->quit();
    } else {
        QWidget::keyPressEvent(event);
    }
}
