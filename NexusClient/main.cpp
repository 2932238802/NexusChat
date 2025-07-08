#include "ClientWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWindow* w = ClientWindow::Instance();
    w->show();
    return a.exec();
}
