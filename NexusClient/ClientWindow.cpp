#include "ClientWindow.h"
#include "QHBoxLayout"


ClientWindow::~ClientWindow() {}

ClientWindow*  ClientWindow::instance = nullptr;

/**
 * @brief ClientWindow::Instance
 * @return 单例模式
 */
ClientWindow* ClientWindow::Instance()
{
    if(instance == nullptr)
    {
        // 如果不传参数 这个parent 就是以桌面为窗口
        instance = new ClientWindow();
    }
    return instance;
}

ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Nexus");
    // 设置图标
    this->setWindowIcon(QIcon(":/resource/image/theme.png")); // 文件图标

    // 用这个来初始化 仰面布局
    // QWidget* navigation_bar; // 导航栏 left
    // QWidget* contacts_column; // 联系人 middle
    // QWidget* forchat; // 聊天框 right

    InitMainWindow();
    InitNavigation(); // 最左侧
    InitContacts(); // 中间部分 联系人 位置 初始化会话
    InitForchat();  // 最右侧 初始化聊天框布局
    InitSignalSlot();
}







