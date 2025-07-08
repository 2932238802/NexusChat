#include "ClientWindow.h"

#include <QApplication>

#include"./Factory/MsgFac.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ClientWindow w;
    //w.show();
    ClientWindow* w= ClientWindow::Instance();
    w->show();
    return a.exec();
}
