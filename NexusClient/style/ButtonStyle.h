#pragma once
#include"QString"
namespace style {
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


} // namespace style





