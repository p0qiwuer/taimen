#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>

class QPushButton;
class Window : public QWidget {
    Q_OBJECT
    public:
        explicit Window(QWidget* parent = 0);
    private slots:
        void slotButtonClicked(bool checked);
    private:
        QPushButton *m_button;
};

#endif // WINDOW_HPP
