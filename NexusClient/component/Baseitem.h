#pragma once
#include"QWidget"
#include"QLabel"
#include"QLayout"
#include"QPushButton"
#include"../common/MyLog.h"
#include"../style/Style.h"

enum class MidType{
    FRIEND = 1,
    APPLY = 2,
    SESSION = 3
};

class Baseitem : public QWidget{
    Q_OBJECT

public:
    Baseitem(QWidget* owner,
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
     void mousePressEvent(QMouseEvent* event) override = 0;
     void enterEvent(QEnterEvent*event) override = 0 ;
     void leaveEvent(QEvent* event) override = 0;
     virtual void SetSatus(bool status) = 0;
     virtual void Actived() = 0;

signals:
    void Clicked(Baseitem* itemId);

protected:
    QLabel* massage;
    QPushButton* tx;
    QWidget *owner;
    QString id;
    bool selected = false;
};


