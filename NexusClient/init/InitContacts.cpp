
#include"../ClientWindow.h"
#include"../style/LineEditStyle.h"
#include"../style/ButtonStyle.h"
#include"qgridlayout.h"


void ClientWindow::InitContacts()
{
    // 这个是网状布局
    QGridLayout* layout = new QGridLayout();

    // 设置边距
    layout->setContentsMargins(0,20,0,0);
    layout->setSpacing(0);
    contacts_column->setLayout(layout);

    // QPushButton*add_friend; // 增加好友按钮
    // QLineEdit* search_edit; // 搜索框
    search_edit = new QLineEdit();
    search_edit->setFixedHeight(30);
    search_edit->setPlaceholderText("搜索...");
    search_edit->setStyleSheet(style::LINE_EDIT_STYLE);

    layout->addWidget(search_edit);

    // 对按钮样式进行配置
    add_friend = new QPushButton();
    add_friend->setFixedSize(30, 30);
    add_friend->setIcon(QIcon(":/resource/image/addfriend.png"));
    add_friend->setStyleSheet(style::ADDFRIEND_BUTTON);
    layout->addWidget(add_friend);


}
