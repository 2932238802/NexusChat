#pragma once
#include"Qstring"
#include"QIcon"

namespace model
{
    /**
     *
     *
     */
    class UserInfo{

        QString user_id = "";
        QString nick_name = "" ;
        QString description = "" ;        // 这个是用户签名
        QString photo = "" ;
        QIcon avatar ;
    };
}
