#pragma once
#include"QWidget"
#include"QLabel"
#include"Baseitem.h"
#include"../style/Style.h"
#include"../common/MyLog.h"

using namespace common;
class SessionLists : public Baseitem {
    Q_OBJECT

public:
    SessionLists(QWidget* owner,
                    const QString& id,
                      const QIcon& avator,
                      const QString&name,
                      const QString&text
                      );
public:
    /**
     * @brief MousePressEvent
     * @param event
     */
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent*event) override;
    void leaveEvent(QEvent* event) override;
    void SetSatus(bool status) override;
    void Actived() override;

private:
    // 父亲组件 SessionFriendArea
    //  bool selected 标记是不是 被选中
    bool selected = false;
    QWidget *owner;

protected:
    QLabel* massage;
};


