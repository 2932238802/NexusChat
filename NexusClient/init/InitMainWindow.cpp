#include"../ClientWindow.h"
#include "QHBoxLayout"

void ClientWindow::InitMainWindow()
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);

    // 边缘部分 导航栏部分
    // 中间部分
    // 右边部分 分别三个
    navigation_bar = new QWidget();
    contacts_column = new QWidget();
    forchat = new QWidget();

    // 设置大小和宽度
    // 最后一个设置是固定的
    //
    navigation_bar->setFixedWidth(70);
    contacts_column->setFixedWidth(310);
    forchat->setMinimumWidth(500); // 设置一个最小的宽度

    // 设置一下颜色
    navigation_bar->setStyleSheet("QWidget{background-color:rgb(46,46,46)}");
    contacts_column->setStyleSheet("QWidget{background-color:rgb(247,247,247)}");
    forchat->setStyleSheet("QWidget{background-color:rgb(225,225,225)}");

    //
    layout->addWidget(navigation_bar);
    layout->addWidget(contacts_column);
    layout->addWidget(forchat);
    layout->setSpacing(0); // 设置一下间距
    layout->setContentsMargins(0,0,0,0); // 四个边距的距离
}
