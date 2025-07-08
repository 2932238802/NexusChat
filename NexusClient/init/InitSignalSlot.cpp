

#include"../ClientWindow.h"
#include"../style/ButtonStyle.h"

/**
 * @brief ClientWindow::InitSignalSlot 初始化信号槽
 */
void ClientWindow::InitSignalSlot(){

    // 最左侧的四个按钮
    // QPushButton*user_avator; // 用户头像
    // QPushButton*chat_avator; // 会话按钮
    // QPushButton*friend_avator; // 好友列表按钮
    // QPushButton*access_avator; // 好友申请按钮

    connect(chat_avator,
            &QPushButton::clicked,
            this,
            &ClientWindow::SwitchToChat // 聊天窗口列表
            );

    connect(friend_avator,
                &QPushButton::clicked,
                this,
                &ClientWindow::SwitchToFriend // 好友列表
            );
    connect(access_avator,
                &QPushButton::clicked,
                this,
                &ClientWindow::SwitchToAccess // 好友申请列表
            );
}

void ClientWindow::SwitchToChat()
{
    active_tab = common::ActiveTab::CHAT_LIST;

    // 设置对应激活的按钮图标
    // 把其他图标设为 暗色

    chat_avator->setStyleSheet(style::NAV_BUTTON_ACTIVE);
    friend_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    access_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
}

void ClientWindow::SwitchToFriend()
{
    active_tab = common::ActiveTab::FRIEND_LIST;
    chat_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    friend_avator->setStyleSheet(style::NAV_BUTTON_ACTIVE);
    access_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
}

void ClientWindow::SwitchToAccess()
{
    active_tab = common::ActiveTab::ACCESS_LIST;
    chat_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    friend_avator->setStyleSheet(style::NAV_BUTTON_INACTIVE);
    access_avator->setStyleSheet(style::NAV_BUTTON_ACTIVE);
}





