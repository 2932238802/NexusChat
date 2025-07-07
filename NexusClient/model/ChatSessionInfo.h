
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

    QString chat_session_id;
    QString chat_seesion_name;
    Message latestmassege;      // 最近的消息
    QIcon avatar;               // 如果是单聊 那么就是对方的头像 不然就是
    QString user_id;
};
}
