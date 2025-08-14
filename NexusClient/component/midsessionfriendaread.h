#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QPushButton>
#include<QLabel>
#include<QStyleOption>
#include<QPainter>
#include"../Debug.h"
#include"../style/ScrollbarStyle.h"
#include"../common/MyLog.h"

using namespace common;

////////////////////////////////////////////////
/// 中间层
////////////////////////////////////////////////
class MidSessionFriendAread : public QScrollArea
{
    // 这个注释的作用
    // 1.
    Q_OBJECT
public:
    explicit MidSessionFriendAread(QWidget *parent = nullptr);

    // 清理 和 添加
    void ClearItem();
    void AddItem(const QIcon&avator,
                 const QString& name,
                 const QString& Text
                 );
public:
    // 官方文档设置
    void paintEvent(QPaintEvent* event) override;


private:
    // 后续往 container 内部的 增加元素
    QWidget* container;

signals:
};



class SessionFriendItem : public QWidget{
    Q_OBJECT

public:
    SessionFriendItem(QWidget* owner,
                        const QIcon& avator,
                      const QString&name,
                      const QString&text
                      );



private:
    // 父亲组件 SessionFriendArea
    //  bool selected 标记是不是 被选中了
    QWidget* owner;
    bool selected = false;

};














