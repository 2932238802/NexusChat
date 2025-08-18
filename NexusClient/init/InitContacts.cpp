
#include"../ClientWindow.h"
#include"../style/LineEditStyle.h"
#include"../style/ButtonStyle.h"
#include"qgridlayout.h"
#include"../component/MidSessionFriendAread.h"
#include"../common/MyLog.h"

/**
 * @brief ClientWindow::InitContacts
 * 1. 中间布局
 * 2. 好友申请列表
 */
void ClientWindow::InitContacts()
{
    // 这个是网状布局
    QGridLayout* layout = new QGridLayout();

    // 设置边距
    layout->setContentsMargins(0,20,0,20);
    layout->setVerticalSpacing(10);
    layout->setHorizontalSpacing(0);
    contacts_column->setLayout(layout);

    // QPushButton*add_friend; // 增加好友按钮
    // QLineEdit* search_edit; // 搜索框
    search_edit = new QLineEdit();
    search_edit->setFixedHeight(30);
    search_edit->setPlaceholderText("搜索...");
    search_edit->setStyleSheet(style::LINE_EDIT_STYLE);

    // 对按钮样式进行配置
    add_friend = new QPushButton();
    add_friend->setFixedSize(30, 30);
    add_friend->setIcon(QIcon(":/resource/image/addfriend.png"));
    add_friend->setStyleSheet(style::ADDFRIEND_BUTTON);

    // 下面几个 头像 和 聊天的窗口 中间部分
    MidSessionFriendAread* midsessionfriend = new MidSessionFriendAread();

    // 增加一些空的 widght 当作间隔
    QWidget* spacer1 = new QWidget();
    QWidget* spacer2 = new QWidget();
    QWidget* spacer3 = new QWidget();
    spacer1->setFixedWidth(10);
    spacer2->setFixedWidth(10);
    spacer3->setFixedWidth(10);

    // 添加到布局
    // addWidget 第三个参数是占据几行 第四个参数是占据几列
    layout->addWidget(spacer1,0,0);
    layout->addWidget(spacer2,0,2);
    layout->addWidget(spacer3,0,4);
    layout->addWidget(search_edit,0,1);
    layout->addWidget(add_friend,0,3);
    layout->addWidget(midsessionfriend,1,0,1,5);
}






















