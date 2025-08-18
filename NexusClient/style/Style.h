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

// 水平的平滑移动
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
    border: none;
}
)";

// 设置文字 就是 名字大小
inline const QString MID_NAME_LABEL = R"(
    QLabel{
    font-size: 18px;
    font-weight: 600;
}
)";


// 消息展示整个的样式
inline const QString MESSAGE_SHOW = R"(
    QScrollArea{
        border: none;
    }

)";

// 消息展示区 垂直的滑块
inline const QString MESSAGE_SHOW_VERTICAL_SCROLLBAR = R"(
    QScrollBar:vertical{
        width: 2px;
        background-color: rgb(200,200,200);
    }
)";

// 消息展示区 垂直的滑块
inline const QString MESSAGE_SHOW_HORIZONTAL_SCROLLBAR = R"(
    QScrollBar:horizontal{
        height: 0;

    }
)";


// 消息展示区 用户时间和名字样式
inline const QString MESSAGE_SHOW_NAME_TIME = R"(
    QLabel {
        font-size: 12px;
        background-color: rgb(178,178,178);
    };
)";



















inline const QString NAV_BUTTON_INACTIVE = R"(
    QPushButton {
        background-color: rgb(120, 120, 120);
        border: none;
        padding: 5px;
        border-radius: 5px;
    }
    QPushButton:hover {
        background-color: rgba(220, 220, 220, 0.4);
    }
    QPushButton:pressed {
        background-color: rgba(200, 200, 200, 0.6);
    }
)";

inline const QString NAV_BUTTON_ACTIVE = R"(
    QPushButton {

        background-color: rgb(210, 210, 210);
        border: none;
        padding: 5px;
        border-radius: 5px;
    }
    QPushButton:hover {

        background-color: rgb(220, 220, 220);
    }
    QPushButton:pressed {

        background-color: rgb(200, 200, 200);
    }
)";

const QString ADDFRIEND_BUTTON = R"(
    QPushButton{
        border-radius:5px;
        background-color:rgb(226,226,226);
    }
    QPushButton:hover{
        background-color:rgb(240,240,240);
    }
)";

inline const QString MID_COMPONENT_MOUTH_CLICK = R"(
    QWidget{
       background-color: rgb(180,180,180);
    }
)";

inline const QString MID_COMPONENT_MOUTH_HOVER = R"(
    QWidget{
        background-color: rgb(215,215,215);
    }
)";














// 搜索框的样式
inline const QString LINE_EDIT_STYLE = R"(
    QLineEdit {
    border-radius:5px;
    background-color:rgb(226,226,226);
    padding-left:5px;
   }
)";

};

