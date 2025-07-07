#pragma once
#include"../model/Message.h"
#include"../model/ChatSessionInfo.h"
#include"../model/UserInfo.h"
#include"../model/MessageType.h"

namespace{
using namespace model;

class MsgFac{
    /**
     * @brief Make
     * @param type
     * @param chat_sessiong_id
     * @param sender
     * @param content
     * @param filename 只有消息类型是文件的时候才有效
     * @return
     */
    static Message Make(
        MessageType type,
        const QString& chat_sessiong_id,
        const UserInfo& sender,
        const QByteArray& content,
        const QString& filename
        )

    {

        switch(type){

        case MessageType::FILE_TYPE:        // 如果是文件类型
        {

            Message msg;
            break;
        }
        case MessageType::IMAGE_TYPE:
        {
            break;
        }
        case MessageType::SPEECH_TYPE:
        {
            break;
        }
        case MessageType::TEXT_TYPE:
        {
            break;
        }
        defalut:
        {
            return Message();
        }

        }

        return Message();
    }

};

}
