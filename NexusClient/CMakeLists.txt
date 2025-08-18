
cmake_minimum_required(VERSION 3.20)

project(NexusClient LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    ClientWindow.cpp
    init/InitSignalSlot.cpp
    init/InitMainWindow.cpp
    init/InitNavigation.cpp
    init/InitContacts.cpp
    init/InitForchat.cpp
    load/LoadAccess.cpp
    load/LoadChat.cpp
    load/LoadFriend.cpp
    component/MidSessionFriendAread.cpp
    component/FriendsLists.cpp
    component/ApplyLists.cpp
    component/SessionLists.cpp
    component/Baseitem.cpp
    component/MessageShow.cpp
    component/MessageEdit.cpp
)

# 统一管理所有 .h 头文件
set(PROJECT_HEADERS
    ClientWindow.h
    model/UserInfo.h
    model/ChatSessionInfo.h
    model/Message.h
    factory/MsgFac.h
    tool/MakeId.h
    tool/MakeTime.h
    tool/Byte2Icon.h
    tool/ReadFile.h
    common/MessageType.h
    common/MyLog.h
    common/Status.h
    common/Debug.h

    style/Style.h
    component/MidSessionFriendAread.h
    component/ApplyLists.h
    component/FriendsLists.h
    component/SessionLists.h
    component/Baseitem.h
    component/MessageShow.h
    component/MessageEdit.h
)

qt_add_executable(NexusClient
    WIN32 MACOSX_BUNDLE
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    resource.qrc
    logs/DeBug.log
    component/MessageEdit.cpp component/MessageEdit.h

)

target_include_directories(NexusClient PRIVATE
    ${CMAKE_SOURCE_DIR}
)


target_link_libraries(NexusClient PRIVATE
    Qt::Core
    Qt::Widgets
)
target_link_libraries(NexusClient PRIVATE Qt6::Widgets)
target_link_libraries(NexusClient PRIVATE Qt6::Widgets)


source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("Header Files" FILES ${PROJECT_HEADERS})

source_group("Header Files\\Model" FILES
    model/UserInfo.h
    model/ChatSessionInfo.h
    model/Message.h
)
source_group("Header Files\\Factory" FILES
    factory/MsgFac.h
)
source_group("Header Files\\Tool" FILES
    tool/MakeId.h
    tool/MakeTime.h
    tool/Byte2Icon.h
    tool/ReadFile.h
)
source_group("Header Files\\Common" FILES
    common/MessageType.h
    common/MyLog.h
    common/Status.h
    common/Debug.h
)
source_group("Header Files\\Style" FILES
    style/ButtonStyle.h
    style/LineEditStyle.h
    style/ScrollbarStyle.h
)
source_group("Header Files\\Component" FILES
    component/MidSessionFriendAread.h
    component/ApplyLists.h
    component/FriendsList.h
    component/SessionLists.h
    component/Baseitem.h
)


include(GNUInstallDirs)


install(TARGETS NexusClient
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


qt_generate_deploy_app_script(
    TARGET NexusClient
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
