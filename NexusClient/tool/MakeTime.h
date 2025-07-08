
#include"QString.h"
#include"QDateTime"

// 避免函数重定义的问题
/**
 * @brief MakeTime
 * @param timestamp 时间戳
 * @return 返回格式化的时间
 */
namespace tool{
static inline QString MakeTime()
{
    int64_t timestamp = QDateTime::currentMSecsSinceEpoch();
    // 先把时间戳 转换成 QDateTime 对象
    QDateTime time = QDateTime::fromMSecsSinceEpoch(timestamp);

    return time.toString("MM-dd HH:mm:ss");
}

}
