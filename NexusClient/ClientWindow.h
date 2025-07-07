#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>

class ClientWindow : public QWidget
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();
};
#endif 
