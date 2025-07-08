#pragma once
                                                                                                 #pragma once

#include"QString.h"
#include"QUuid.h"

namespace tool{
/**
 * @brief MakeId 获取唯一的id
 * @return 返回一个唯一的id
 */
static inline QString MakeId()
{
    return 'M' + QUuid::createUuid().toString().slice(25,12);
}
}
