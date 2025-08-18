
#include"FriendsLists.h"

/// 好友申请列表
/// \brief FriendsLists::FriendsLists
/// \param owner
/// \param user_id
/// \param avatar
/// \param name
/// \param discription
/// 默认构造函数
///
using namespace common;
FriendsLists::FriendsLists(
    QWidget* owner,
    const QString&user_id,
    const QIcon&avatar,
    const QString&name,
    const QString& discription
    ):Baseitem(owner,user_id,avatar,name,discription),userId(user_id)
{
}

void FriendsLists::SetSatus(bool status)
{
    // MY_LOG_INF("todo ...");
}

void FriendsLists::mousePressEvent(QMouseEvent* event){
    MY_LOG_INF("in friendlists 1...");
}

void FriendsLists::enterEvent(QEnterEvent*event) {
    MY_LOG_INF("in friendlists 2...");
}

void FriendsLists::leaveEvent(QEvent* event){
    MY_LOG_INF("in friendlists 3...");
}

void FriendsLists::Actived()
{


}
