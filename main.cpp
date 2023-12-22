#include <QApplication>
#include "taimen.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Taimen taimen;
    taimen.show();

    return app.exec();
}
