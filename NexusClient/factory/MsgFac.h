#pragma once
#include"../Model/Message.h"
#include"../Model/ChatSessionInfo.h"
#include"../model/UserInfo.h"
#include"../common//MessageType.h"
#include"../tool/MakeId.h"
#include"../tool/MakeTime.h"


namespace{
using namespace model;

class MsgFac{
    /**
     * @brief Make
     * @param type 消息类型
     * @param chat_sessiong_id 会话id
     * @param sender 发送者
     * @param content 内容
     * @param filename 只有消息类型是文件的时候才有效
     * @return
     */
    static Message Make(
        MessageType type,                       // 消息的类型
        const QString& chat_sessiong_id,        // 对应的会话是什么
        const UserInfo& sender,                 // 发送的内容是什么
        const QByteArray& content,              // 谁发送的
        const QString& filename                 // 如果是文件 文件的内容是什么
        )

    {

        switch(type){

            // QString time;               // 发送的时间
            // QString msg_id;             // 消息的唯一标识符
            // QString chat_session_id;    // 消息所处的会话
            // MessageType msg_type;       // 消息类型

            // UserInfo sender;            // 发送者信息

            // QByteArray content;         // 消息的正文
            // QString file_id;            // 这里的file_id 只有在文件是 语音 文件 或者 图片的时候 才生效 要把这个id 放到消息队列里面
            // QString file_name;          // 文件名字

        case MessageType::TEXT_TYPE:        // 如果是文件类型
        {
            // 文本消息的处理
            Message msg;
            msg.time = tool::MakeTime();
            msg.msg_id = tool::MakeId();
            msg.chat_session_id = chat_sessiong_id;
            msg.msg_type = MessageType::TEXT_TYPE;

            msg.sender = sender;

            msg.content = content;
            msg.file_id = "";
            msg.file_name = "";
            return msg;
        }
        case MessageType::IMAGE_TYPE:
        {
            // 图片信息
            Message msg;

            msg.time = tool::MakeTime();
            msg.msg_id = tool::MakeId();
            msg.chat_session_id = chat_sessiong_id;
            msg.msg_type = MessageType::IMAGE_TYPE;

            msg.sender = sender;

            msg.content = content;

            // TODO: 这里要完善
            msg.file_id = "";
            msg.file_name = "";

            return msg;
        }
        case MessageType::FILE_TYPE:
        {
            Message msg;

            msg.time = tool::MakeTime();
            msg.msg_id = tool::MakeId();
            msg.chat_session_id = chat_sessiong_id;
            msg.msg_type = MessageType::FILE_TYPE;

            msg.sender = sender;

            msg.content = content;

            // TODO: 这里要完善
            msg.file_id = "";
            msg.file_name = filename;

            return msg;
        }
        case MessageType::SPEECH_TYPE:
        {
            Message msg;

            msg.time = tool::MakeTime();
            msg.msg_id = tool::MakeId();
            msg.chat_session_id = chat_sessiong_id;
            msg.msg_type = MessageType::SPEECH_TYPE;

            msg.sender = sender;

            msg.content = content;

            // TODO: 这里要完善
            msg.file_id = "";
            msg.file_name = "";

            return msg;
        }
        defalut:
        {
            return Message();
        }
        }
    }

};

}
