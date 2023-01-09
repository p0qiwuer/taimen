#include "main_window.hpp"

#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QGraphicsScene>
#include <QGraphicsView>

mainWindow::mainWindow() {
//    setDefaultSize(100, 50);
//    menuBar = new QMenuBar(this);
//    fileMenu = new QMenu(menuBar);
//    fileMenu = menuBar->addMenu(tr("&File"));
    scene = new QGraphicsScene();
    scene->addText("Hello World!");
    scene->addText("Saatana");
    view = new QGraphicsView(scene, this);
}

