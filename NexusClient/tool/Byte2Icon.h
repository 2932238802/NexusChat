#pragma once
#include"QIcon"
#include"QByteArray"


namespace tool
{
/**
 * @brief Byte2Icon
 * @param ba
 * @return 返回一个QIcon
 */
static inline QIcon Byte2Icon(const QByteArray& ba){
    QPixmap pixmap;
    pixmap.loadFromData(ba);
    QIcon icon(pixmap);
    return icon;
}
}
