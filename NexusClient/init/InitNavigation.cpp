#include"../ClientWindow.h"
#include "QHBoxLayout"
#include "../style/ButtonStyle.h"

void ClientWindow::InitNavigation()
{
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setSpacing(10);
    layout->setContentsMargins(0,30,0,0);
    navigation_bar->setLayout(layout);

    // QPushButton*user_avator; // 用户头像
    // QPushButton*chat_avator; // 会话按钮
    // QPushButton*friend_avator; // 好友列表按钮
    // QPushButton*access_avator; // 好友申请按钮

    // 用户头像
    user_avator = new QPushButton();
    user_avator->setFixedSize(45,45);
    user_avator->setIconSize(QSize(45,45));
    user_avator->setIcon(QIcon(":/resource/image/avator.png"));
    user_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    layout->addWidget(user_avator,1,Qt::AlignTop | Qt::AlignHCenter);

    // 添加会话标签按钮
    chat_avator = new QPushButton();
    chat_avator->setFixedSize(45,45);
    chat_avator->setIconSize(QSize(45,45));
    chat_avator->setIcon(QIcon(":/resource/image/conversationwindow.png"));
    chat_avator->setStyleSheet(style::NAV_BUTTON_ACTIVE);
    layout->addWidget(chat_avator,1,Qt::AlignTop | Qt::AlignHCenter);

    // 好友列表
    friend_avator = new QPushButton();
    friend_avator->setFixedSize(45,45);
    friend_avator->setIconSize(QSize(45,45));
    friend_avator->setIcon(QIcon(":/resource/image/address.png"));
    friend_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    layout->addWidget(friend_avator,1,Qt::AlignTop | Qt::AlignHCenter);

    // 好友申请列表
    access_avator= new QPushButton();
    access_avator->setFixedSize(45,45);
    access_avator->setIconSize(QSize(45,45));
    access_avator->setIcon(QIcon(":/resource/image/request.png"));
    access_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    layout->addWidget(access_avator,1,Qt::AlignTop | Qt::AlignHCenter);

    // 增加空白区域
    layout->addStretch(10);
}
