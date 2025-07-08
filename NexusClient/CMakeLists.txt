
cmake_minimum_required(VERSION 3.19)
project(NexusClient LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set(APP_SOURCES
    main.cpp
    ClientWindow.cpp
)
set(APP_HEADERS
    ClientWindow.h
)


set(MODEL_HEADERS
    model/UserInfo.h
    model/ChatSessionInfo.h

    model/Message.h
)
set(FACTORY_HEADERS
    factory/MsgFac.h


)
set(TOOL_HEADERS
    tool/MakeId.h
    tool/MakeTime.h
    tool/Byte2Icon.h
    tool/ReadFile.h
)

set(COMMON_HEADERS
    common/MessageType.h
    common/MyLog.h
    common/Status.h
)

set(STYLE_HEADERS
    style/ButtonStyle.h
    style/LineEditStyle.h
)

qt_add_executable(NexusClient
    WIN32 MACOSX_BUNDLE
    ${APP_SOURCES}
    ${APP_HEADERS}
    ${MODEL_HEADERS}
    ${FACTORY_HEADERS}
    ${TOOL_HEADERS}
    ${COMMON_HEADERS}
    ${STYLE_HEADERS}
    resource.qrc
    init/InitSignalSlot.cpp
    init/InitMainWindow.cpp
    init/InitNavigation.cpp

    load/LoadAccess.cpp
    load/LoadChat.cpp
    load/LoadFriend.cpp
    init/InitContacts.cpp
    init/InitForchat.cpp


)


source_group("Source Files" FILES ${APP_SOURCES})
source_group("Header Files" FILES ${APP_HEADERS})
source_group("Header Files\\Model"  FILES ${MODEL_HEADERS})
source_group("Header Files\\Factory" FILES ${FACTORY_HEADERS})
source_group("Header Files\\Tool"   FILES ${TOOL_HEADERS})



target_link_libraries(NexusClient PRIVATE
    Qt::Core
    Qt::Widgets
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
