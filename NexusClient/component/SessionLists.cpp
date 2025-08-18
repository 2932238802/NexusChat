#include "SessionLists.h"

////////////////////////////////////////////////////////
/// 中间层的 组件之一
////////////////////////////////////////////////////////
// 微信头像选择 就是 微信顶置的那一块的设置
// 布局 用 网格布局
SessionLists::SessionLists(
    QWidget* _owner,
    const QString& id,
    const QIcon& avator,
    const QString&name,
    const QString&text
    ):Baseitem(_owner,id,avator,name,text),owner(_owner)
{

    QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
    if(layout == nullptr)
    {
        MY_LOG_ERROR("SessionLists::SessionLists layout is nullptr!");
        return;
    }

    // 创建名字 Expanding 就是尽可能的扩展
    QLabel* name_label = new QLabel();
    name_label->setText(name);
    name_label->setStyleSheet(style::MID_NAME_LABEL);
    name_label->setFixedHeight(35);
    name_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    // 创建消息预览
    massage = new QLabel();
    massage->setText(text);
    massage->setFixedHeight(35);
    massage->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    layout->addWidget(name_label,0,1,1,1);  // 名字 一行一列
    layout->addWidget(massage,1,1,1,1);     // 消息一行一列
}

////////////////////////////////////////////////////////
/// 中间层的 组件之一 点击效果
////////////////////////////////////////////////////////
void SessionLists::mousePressEvent(QMouseEvent* event)
{
    // 点击的时候 修改背景

    emit Clicked(this);
    MY_LOG_INF("SessionLists clicked");
    QWidget::mousePressEvent(event);
}

////////////////////////////////////////////////////////
/// 中间层的 组件之一 鼠标进入效果 和出去的效果
////////////////////////////////////////////////////////
void SessionLists::enterEvent(QEnterEvent*event)
{
    if(!this->selected)
    {
        this->setStyleSheet(style::MID_COMPONENT_MOUTH_HOVER);
    }
    QWidget::enterEvent(event);
}

void SessionLists::leaveEvent(QEvent* event)
{
    if(!this->selected)
    {
        this->setStyleSheet(style::MIDSCROLLERBAY_FRIENDITEM);
    }
    QWidget::leaveEvent(event);
}

////////////////////////////////////////////////////////
/// 中间层的 组件之一 设置状态
////////////////////////////////////////////////////////
void SessionLists::SetSatus(bool status)
{
    if(selected == status) return;
    selected = status;
    if(!status)
    {
        // 如果没有选中
        if(!this->underMouse())
        {
            this->setStyleSheet(style::MIDSCROLLERBAY_FRIENDITEM);
        }
        else{
            this->setStyleSheet(style::MID_COMPONENT_MOUTH_HOVER);
        }
    }
    else{
        // 说明被点击了
        this->setStyleSheet(style::MID_COMPONENT_MOUTH_CLICK);
    }
}



void SessionLists::Actived()
{


}

