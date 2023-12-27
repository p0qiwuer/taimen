#include <QApplication>
#include <iostream>
#include "taimen.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "ERROR: no split config file specified\n";
        return EXIT_FAILURE;
    }

    QApplication app(argc, argv);

    Taimen taimen;
    taimen.show();

    return app.exec();
}
