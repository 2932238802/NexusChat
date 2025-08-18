#pragma once

#include <cstdio>
#include <cstring>
#include <ctime>

#include <iostream>
#include <string>
#include<fstream>

// #define tag QString("[%1]").arg(QString::number(__LINE__))
namespace common
{
#define RESET "\033[0m"
#define BLACK "\033[30m"   /* 黑色 */
#define RED "\033[31m"     /* 红色 */
#define GREEN "\033[32m"   /* 绿色 */
#define YELLOW "\033[33m"  /* 黄色 */
#define BLUE "\033[34m"    /* 蓝色 */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */
enum class G
{
    SUC = 1,
    INF,
    WAR,
    ERR,
};

inline const char *GetFile(const char *str)
{
    if (!str)
        return "UnknownFile";                 // 安全检查
    const char *pos_fwd = strrchr(str, '/');  // 正斜杠
    const char *pos_bwd = strrchr(str, '\\'); // 反斜杠

    const char *pos = pos_fwd;
    if (pos_bwd && (!pos_fwd || pos_bwd > pos_fwd))
    {
        pos = pos_bwd;
    }

    if (pos)
    {
        return pos + 1;
    }
    return str;
}

class MyLog
{

  public:
    template <class... Args> static void Log(const char *file, int line, G grade, Args... args)
    {
        std::string grade_str = "";
        std::string color_str = "";
        switch (grade)
        {
        case G::ERR:
            grade_str = "ERR";
            color_str = RED;
            break;
        case G::INF:
            grade_str = "INF";
            break;
        case G::WAR:
            grade_str = "WAR";
            color_str = MAGENTA;
            break;
        case G::SUC:
            grade_str = "SUC";
            color_str = GREEN;
            break;
        default:
            grade_str = "UNKWN";

            break;
        }
        // 测试专用
        std::ofstream logFile("D:\\PR\\NexusChat\\NexusClient\\logs\\DeBug.log",std::ios::app);

        if(!logFile.is_open())
        {
            std::cout<<("failed to open file ...");
            return;
        }

        time_t now = time(nullptr);
        struct tm *tmNow = localtime(&now);
        char time_buffer[80];
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tmNow);

        logFile<< "[" << time_buffer << "]" << " ";
        logFile << "[" << color_str << grade_str << RESET << "]" << " ";
        logFile << "[" << BLUE << GetFile(file) << ":" << line << RESET << " @LosAngelous]>>> ";
        (logFile << ... << args) << std::flush<<std::endl;
        logFile.close();
    }
};

#define MY_LOG_INF(...) MyLog::Log(__FILE__, __LINE__, G::INF, ##__VA_ARGS__)
#define MY_LOG_WARN(...) MyLog::Log(__FILE__, __LINE__, G::WAR, ##__VA_ARGS__)
#define MY_LOG_ERROR(...) MyLog::Log(__FILE__, __LINE__, G::ERR, ##__VA_ARGS__)
#define MY_LOG_SUC(...) MyLog::Log(__FILE__, __LINE__, G::SUC, ##__VA_ARGS__)

} // namespace MyLogNS
