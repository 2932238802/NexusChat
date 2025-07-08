#pragma once
#include"QBytearray"
#include"QFile"
#include"../common/MyLog.h"

namespace Tool
{
using namespace common;
/**
 * @brief ReadFile_file2byte
 * @param path 文件路径
 * @return 返回一个二进制的数据
 */
static inline QByteArray ReadFile_file2byte(const QString& path)
{
    // 直接根据 路径
    // 以只读的方式 打开
    QFile file(path);
    bool isok = file.open(QFile::ReadOnly);

    if(!isok)
    {
        MY_LOG_ERROR("以只读的方式 打开文件失败!");
        return QByteArray(); // 返回一个空的类
    }

    QByteArray ba = file.readAll();
    file.close(); // 关闭一下文件
    return ba;
}

/**
 * @brief WriteFile 写入文件函数
 * @param path 文件路径
 * @param content 写入文件的内容
 */
static inline void WriteFile(const QString& path,const QByteArray& content)
{
    QFile file(path);
    bool isok = file.open(QFile::WriteOnly); // 以写的方式

    if(!isok)
    {
        MY_LOG_ERROR("以写的方式 打开文件失败!");
        return;
    }

    file.write(content); // 写入文件内容
    file.flush(); // 刷新缓冲区

    file.close(); // 关闭文件
}
}
