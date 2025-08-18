#pragma once;

#include <QScrollArea>
#include <QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include <qscrollbar.h>
#include"../factory/MsgFac.h"
#include"../style/Style.h"
#include"../common/MyLog.h"
///
/// \brief The Message class
/// 消息对话
///
using q = QWidget;
class MessageShow : public QScrollArea
{
    Q_OBJECT
public:
    MessageShow();

private:
    q* container;
};

///
/// \brief The MsgItem class
/// 1. 调用消息工厂 创建消息
/// 2.
class MsgItem: public QWidget{

    Q_OBJECT

public:
    MsgItem(bool isRight);
    static MsgItem* MakeMsgItem(bool is_right,const Message& message);

private:
    bool isRight;
};
