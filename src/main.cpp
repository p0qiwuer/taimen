#include "main_window.hpp"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    mainWindow window;
    
//    const static int width = QCoreApplication::arguments().at(1).toInt();
//    const static int height = QCoreApplication::arguments().at(2).toInt();
//    window.setFixedSize(width, height);

    window.show();

    return app.exec();
}
