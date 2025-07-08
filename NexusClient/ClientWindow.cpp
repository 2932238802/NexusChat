#include "ClientWindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Nexus");
    // 设置图标
    this->setWindowIcon(QIcon(":/resource/image/theme.png")); // 文件图标


}

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









