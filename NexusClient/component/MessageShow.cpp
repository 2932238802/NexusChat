#include "MessageShow.h"


using namespace common;
MessageShow::MessageShow() {

    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setWidgetResizable(true);

    // 滚动条样式
    this->verticalScrollBar()->setStyleSheet(style::MESSAGE_SHOW_VERTICAL_SCROLLBAR);
    this->horizontalScrollBar()->setStyleSheet(style::MESSAGE_SHOW_HORIZONTAL_SCROLLBAR);
    this->setStyleSheet(style::MESSAGE_SHOW);

    container = new q();
    this->setWidget(container);

    QVBoxLayout* layout = new QVBoxLayout();

}

///
/// \brief MsgItem::MsgItem
/// \param is_right
/// 构造函数
MsgItem::MsgItem(bool is_right):isRight(is_right)
{

}


///
/// \brief MakeMsgItem
/// \param is_right
/// \param message
/// \return
/// 1. 创建对应的实体 消息 把抽象的 Message -> 显示到 Qt上面来
MsgItem *MsgItem::MakeMsgItem(bool is_right, const Message &message)
{
    auto msgItem = new MsgItem(is_right);
    QGridLayout* layout = new QGridLayout();

    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    msgItem->setMinimumHeight(100);
    msgItem->setLayout(layout);

    QPushButton* qpb = new QPushButton();
    qpb->setFixedSize(40,40);
    qpb->setIconSize(QSize(40,40));
    qpb->setIcon(message.sender.avatar);


    // 创建名字和时间 包括样式设置
    QLabel* nameQlable = new QLabel();
    nameQlable->setText(message.sender.nick_name +" | " + message.time);
    nameQlable->setAlignment(Qt::AlignBottom);
    nameQlable->setStyleSheet(style::MESSAGE_SHOW_NAME_TIME);

    // 创建消息体
    QWidget* messageBody = new QWidget();

    switch(message.msg_type){

    case(common::MessageType::FILE_TYPE):
    {
        // messageBody = MakeFileMsg();
    }
    case(common::MessageType::IMAGE_TYPE):{

    }
    case(common::MessageType::SPEECH_TYPE):{

    }
    case(common::MessageType::TEXT_TYPE):{

    }
    default:{
        MY_LOG_ERROR("error msg type:",message.msg_type);
    }
    }



    if(!is_right)
    {
        // 如果是在 左侧
        layout->addWidget(qpb,0,0,2,1,Qt::AlignTop|Qt::AlignLeft);
        layout->addWidget(nameQlable,0,1,Qt::AlignLeft);
        layout->addWidget(messageBody,1,1);
    }
    else{
        layout->addWidget(qpb,0,1,2,1,Qt::AlignTop|Qt::AlignRight);
        layout->addWidget(nameQlable,0,0,Qt::AlignRight);
        layout->addWidget(messageBody,1,0);
    }



}























