#include <gtkmm.h>
#include <iostream>
#include <chrono>
#include <thread>

class MyWindow : public Gtk::Window {
    public:
        MyWindow();
};

MyWindow::MyWindow() {
    set_title("Taimen");
    set_default_size(640, 480);
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
