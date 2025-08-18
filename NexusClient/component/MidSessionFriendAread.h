#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include"../common/Debug.h"
#include"../style/Style.h"
#include"../common/MyLog.h"
#include"Baseitem.h"
#include"SessionLists.h"
#include"FriendsLists.h"
#include"ApplyLists.h"


using namespace common;
class SessionLists;

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
    void AddItem(
                    MidType type,
                    const QString&id,
                    const QIcon&avator,
                    const QString& name,
                    const QString& Text
                 );
public:
    // 官方文档设置
    void paintEvent(QPaintEvent* event) override;


private:
    void OnSessionChildClick(Baseitem* item);

private:
    // 后续往 container 内部的 增加元素
    QWidget* container;
    Baseitem* current = nullptr; // 记录当前选择项
signals:
};














