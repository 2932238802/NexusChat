#pragma once

#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include"common/DeBug.h"
#include"QPushButton"
#include"common/Status.h"
#include"qlineedit.h"
#include"component/MessageShow.h"
#include"component/MessageEdit.h"

class ClientWindow : public QWidget
{
    Q_OBJECT
private:
    ClientWindow(QWidget *parent = nullptr);
    static ClientWindow* instance;
    common::ActiveTab active_tab = common::ActiveTab::CHAT_LIST ;


public:
    // 对于单例模型 最关键的部分就是
    // 限制别人 创建不了示例
    // 因为 主窗口在程序启动的时候 就会已经创建好了
    // 不用担心 线程的问题
    static ClientWindow* Instance();
    ~ClientWindow();
private:
    void InitMainWindow();
    void InitNavigation();
    void InitContacts(); // 初始化会话
    void InitForchat(); // 初始化聊天框布局
    void InitSignalSlot();

    // 按钮槽的申明
    void SwitchToChat();
    void SwitchToFriend();
    void SwitchToAccess();

    // 数据加载
    void LoadAccess();
    void LoadFriend();
    void LoadChat();

private:
    QWidget* navigation_bar; // 导航栏 left
    QWidget* contacts_column; // 联系人 middle
    QWidget* forchat; // 聊天框 right

    // 最左侧的四个按钮
    QPushButton*user_avator; // 用户头像
    QPushButton*chat_avator; // 会话按钮
    QPushButton*friend_avator; // 好友列表按钮
    QPushButton*access_avator; // 好友申请按钮
    QPushButton*add_friend; // 增加好友按钮

    // 搜索框
    QLineEdit* search_edit;

    //
    MessageShow* messageShow;
    MessageEdit* messageEdit;

};

