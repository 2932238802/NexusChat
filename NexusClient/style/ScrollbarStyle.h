#pragma once
#include"QString"
namespace style{

// 这里高度设为0
// 是为了让内容自动去填充高度
// 滑块的颜色
inline const QString MIDSCROLLERBAY_HEIGHT =  R"(
        QScrollBar:vertical {
        border: none;
        background-color: rgb(200,200,200);
        width: 5px;

    }

    QScrollBar::handle:vertical {
        background-color: rgb(100,100,100);
        min-height: 20px;
        border-radius: 2px;
    }
)";

inline const QString MIDSCROLLERBAY_WIDTH = R"(
    QScrollBar:horizontal {
        border: none;
        height: 0px;
    }
)";


inline const QString MIDSCROLLERBAY_FRIENDITEM = R"(
    QWidget {
    background-color: rgb(231,231,231);
}
)";

// 顶置那个部分 中间模块的 头像设置 样式设置
inline const QString MIDSCROLLERBAY_AVATOR = R"(
    QPushButton {
    border:none;
}
)";

// 设置文字 就是 名字大小
inline const QString MID_NAME_LABEL = R"(
    QLabel{
    font-size: 18px;
    font-weight: 600;
}
)";


};

