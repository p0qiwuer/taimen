#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setBackgroundBrush(Qt::black);
    QGraphicsTextItem* text1 = scene.addText("Hello");
    QGraphicsTextItem* text2 = scene.addText("Hello again");

    text1->setDefaultTextColor(Qt::white);

    text2->setPos(10, 10);

    QGraphicsView view(&scene);
    
//    const static int width = QCoreApplication::arguments().at(1).toInt();
//    const static int height = QCoreApplication::arguments().at(2).toInt();
//    window.setFixedSize(width, height);

    view.show();

    return app.exec();
}
