

#include"../ClientWindow.h"

/// 右侧布局
/// \brief ClientWindow::InitForchat
///
using qvb = QVBoxLayout;
using qhb = QHBoxLayout;

void ClientWindow::InitForchat()
{
    // 垂直布局
    qvb* layout = new qvb();
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    layout->setAlignment(Qt::AlignTop);

    forchat->setLayout(layout);

    // 创建上面
    QWidget* titleWidget =new QWidget();
    titleWidget->setFixedHeight(62);

    titleWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    layout->addWidget(titleWidget);
    qhb* layoutForTitle = new qhb();
    layoutForTitle->setSpacing(0);
    layoutForTitle->setContentsMargins(20,0,20,0);
    titleWidget->setLayout(layoutForTitle);

#if DEBUG
    QLabel*words = new QLabel();
    words->setText("测试标题");
    words->setStyleSheet("QLabel { border-bottom: 1px solid rgb(10,10,10);font-size:24px; color: rgb(20,20,20);}");
    layoutForTitle->addWidget(words);
    QPushButton* otherButton = new QPushButton();
    otherButton->setFixedSize(30,30);
    otherButton->setIconSize(QSize(30,30));
    otherButton->setIcon(QIcon(":/resource/image/other.png"));
    otherButton->setStyleSheet("QPushButton{background-color: transparent; } QPushButton:pressed{background-color: rgb(180,180,180);} ");
    layoutForTitle->addWidget(otherButton);
#endif

    // messageShow 就是消息展示区
    messageShow = new MessageShow();
    layout->addWidget(messageShow);


    messageEdit = new MessageEdit();
    layout->addWidget(messageEdit,0,Qt::AlignBottom);









}

