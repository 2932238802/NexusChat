#include "Applylists.h"

//////////////////////////////
/// \brief ApplyLists::ApplyLists
/// \param owner
/// \param user_id
/// \param name
/// \param avator
/// 默认构造函数 申请列表
//////////////////////////////
ApplyLists::ApplyLists(
    QWidget* owner,
    const QString&user_id,
    const QIcon &avator,
    const QString& name
    ):Baseitem(
          owner,
          user_id,
          avator,
          name,
          QString{""}
          )
{
    MY_LOG_INF("ApplyLists::ApplyLists 申请列表初始化 ...");
    QGridLayout* layout = dynamic_cast<QGridLayout*>(this->layout());
    if(!layout){
        MY_LOG_ERROR("ApplyLists::ApplyLists falied by nullptr<layout>...");
        return;
    }

    if(massage)
    {
        layout->removeWidget(massage);
        delete massage;
    }


    // 创建两个按钮出来
    QPushButton* accept = new QPushButton();
    QPushButton* reject = new QPushButton();
    QLabel* name_label = new QLabel();
    name_label->setText(name);
    name_label->setStyleSheet(style::MID_NAME_LABEL);
    name_label->setFixedHeight(35);
    name_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    // 设置内容
    accept->setText("同意");
    reject->setText("拒绝");
    layout->addWidget(accept,1,1,1,2);
    layout->addWidget(reject,1,3,1,2);
    layout->addWidget(name_label,0,1,1,4);

    // DeBug
    MY_LOG_SUC("ApplyLists::ApplyLists 申请列表初始化 成功");
}


void ApplyLists::SetSatus(bool status)
{
    MY_LOG_INF("in ApplyLists 0...");
}

void ApplyLists::mousePressEvent(QMouseEvent* event){
    MY_LOG_INF("in ApplyLists 1...");
}

void ApplyLists::enterEvent(QEnterEvent*event) {
    MY_LOG_INF("in ApplyLists 2...");
}

void ApplyLists::leaveEvent(QEvent* event){
    MY_LOG_INF("in ApplyLists 3...");
}

void ApplyLists::Actived()
{


}


