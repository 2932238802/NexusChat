#include "Baseitem.h"

/// 基类 基本布局
/// \brief Baseitem::Baseitem
/// \param owner
/// \param id
/// \param avator
/// \param name
/// \param text
///
Baseitem::Baseitem(QWidget* owner,
                   const QString& id,
                   const QIcon& avator,
                   const QString&name,
                   const QString&text):owner(owner),id(id)

{
    this->setFixedHeight(70);
    this->setStyleSheet(style::MIDSCROLLERBAY_FRIENDITEM);
    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(0);
    this->setLayout(layout);

    massage = new QLabel();
    massage->setText(text);
    layout->addWidget(massage);

    tx = new QPushButton();
    tx->setFixedSize(70,70);
    tx->setIconSize(QSize(60,60));                            // 设置图片尺寸
    tx->setIcon(avator);                                      // 设置头像
    tx->setStyleSheet(style::MIDSCROLLERBAY_AVATOR);          // 设置样式
    tx->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed); // 就是不随着 父进行变化

    layout->addWidget(tx,0,0,2,1);
}

