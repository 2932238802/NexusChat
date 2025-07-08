#include"../ClientWindow.h"
#include "QHBoxLayout"

void ClientWindow::InitMainWindow()
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);


    navigation_bar = new QWidget();
    contacts_column = new QWidget();
    forchat = new QWidget();

    navigation_bar->setFixedWidth(70);
    contacts_column->setFixedWidth(310);
    forchat->setMinimumWidth(500); // 设置一个最小的宽度

    // 设置一下颜色
    navigation_bar->setStyleSheet("QWidget{background-color:rgb(46,46,46)}");
    contacts_column->setStyleSheet("QWidget{background-color:rgb(247,247,247)}");
    forchat->setStyleSheet("QWidget{background-color:rgb(225,225,225)}");

    layout->addWidget(navigation_bar);
    layout->addWidget(contacts_column);
    layout->addWidget(forchat);
    layout->setSpacing(0); // 设置一下间距
    layout->setContentsMargins(0,0,0,0); // 四个边距的距离
}
