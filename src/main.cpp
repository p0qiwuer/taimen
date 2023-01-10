#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTimer>
#include <chrono>

class Timer : public QGraphicsTextItem {
    public:
        Timer() {
            start_time = std::chrono::steady_clock::now();
        }
        void advance(int phase) {
            if (!phase)
                return;
            auto elapsed_time = std::chrono::steady_clock::now() - start_time;
            setPlainText(QString::number(elapsed_time.count()));
        }
    private:
        std::chrono::time_point<std::chrono::steady_clock> start_time;

};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene scene(10, 10, 180, 80);
    scene.setBackgroundBrush(Qt::black);
    Timer* text = new Timer;
    scene.addItem(text);

    text->setDefaultTextColor(Qt::white);
    text->setPos(0, 0);

    QGraphicsView view(&scene);
    view.setFixedSize(200, 100);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
    timer.start(1);

//    const static int width = QCoreApplication::arguments().at(1).toInt();
//    const static int height = QCoreApplication::arguments().at(2).toInt();
//    window.setFixedSize(width, height);

    view.show();

    return app.exec();
}
