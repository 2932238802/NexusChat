#pragma once


#include"Baseitem.h"

///////////////////////////////////////
// 继承上一个的样式
///////////////////////////////////////
class FriendsLists:public Baseitem
{
    Q_OBJECT
public:
    FriendsLists(
        QWidget* owner,
        const QString&user_id,
        const QIcon&avatar,
        const QString&name,
        const QString& discription
        );

    void SetSatus(bool status) override;
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent*event) override;
    void leaveEvent(QEvent* event) override;
    void Actived() override;
private:
    QString userId;
};

