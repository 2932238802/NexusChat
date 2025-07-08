#pragma once
#include"Qstring"
#include"QIcon"
#include"../common/MessageType.h"
#include"UserInfo.h"

namespace model
{

class Message{
    /**
     * 1. 消息类型
     */
public:
Message(){}

public:
    QString msg_id = "" ;               // 消息的唯一标识符
    QString file_id = "";               // 这里的file_id 只有在文件是 语音 文件 或者 图片的时候 才生效 要把这个id 放到消息队列里面
    QString chat_session_id = "" ;      // 消息所处的会话
    MessageType msg_type;               // 消息类型

    QByteArray content;                 // 消息的正文
    QString time = "";                  // 发送的时间
    UserInfo sender;                    // 发送者信息

    QString file_name = "";             // 文件名字
};
};
