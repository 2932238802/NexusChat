
#pragma once
#include"Qstring"
#include"QIcon"
#include"Message.h"

namespace model
{

class ChatSessionInfo{
    /**
     * 1. 聊天框的各个信息
     */
public:

    QString chat_session_id = "";       // 会话的id 唯一
    QString user_id = "";               // 对方用户（们）的id

    QString chat_seesion_name = "" ;    // 会话的名称
    Message latestmassege;              // 最近的消息

    QIcon avatar;                       // 如果是单聊 那么就是对方的头像 不然就是
};
}
