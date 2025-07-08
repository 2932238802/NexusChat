#pragma once

#include <QWidget>
#include"QPushButton"

class ClientWindow : public QWidget
{
    Q_OBJECT

private:
    ClientWindow(QWidget *parent = nullptr);
    static ClientWindow* instance;


public:
    // 对于单例模型 最关键的部分就是
    // 限制别人 创建不了示例
    // 因为 主窗口在程序启动的时候 就会已经创建好了
    // 不用担心 线程的问题
    static ClientWindow* Instance();
    ~ClientWindow();

private:

    QWidget* navigation_bar; // 导航栏
    QWidget* contacts_column; // 联系人
    QWidget* forchat; // 聊天框

    QPushButton*user_avator; // 用户头像
    QPushButton*chat_avator; // 会话按钮
    QPushButton*friend_avator; // 好友列表按钮
    QPushButton*access_avator; // 好友申请按钮
};

