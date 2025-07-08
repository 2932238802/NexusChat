#include"QString"



// 左侧的按钮
// style.h

#include "QString"

namespace style {
const QString NAV_BUTTON_INACTIVE = R"(
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

const QString NAV_BUTTON_ACTIVE = R"(
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

} // namespace style





