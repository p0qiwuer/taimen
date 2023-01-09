#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

class QMenu;
class QMenuBar;
class QGraphicsScene;
class QGraphicsView;
class mainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit mainWindow();
    private:
        QMenuBar* menuBar;
        QMenu* fileMenu;
        QGraphicsView* view;
        QGraphicsScene* scene;
};

#endif // MAIN_WINDOW_HPP
