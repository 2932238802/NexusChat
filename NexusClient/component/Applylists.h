#pragma once

#include"MidSessionFriendAread.h"
#include"Baseitem.h"
#include"../common/MyLog.h"

using namespace common;
class ApplyLists: public Baseitem
{
    Q_OBJECT
public:
    ApplyLists(QWidget* owner,
               const QString& user_id,
               const QIcon& avator,
               const QString &name
               );

    void SetSatus(bool status) override;
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent*event) override;
    void leaveEvent(QEvent* event) override;
    void Actived() override;
};


