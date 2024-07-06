#include <QApplication>

#include "QtApp/Window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qta::Window window;
    window.show();

    return QApplication::exec();
}