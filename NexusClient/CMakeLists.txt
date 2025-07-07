cmake_minimum_required(VERSION 3.19)
project(NexusClient LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(NexusClient
    WIN32 MACOSX_BUNDLE
    main.cpp
    ClientWindow.cpp
    ClientWindow.h
    model/UserInfo.h
    model/ChatSessionInfo.h
    model/MessageType.h
    model/Message.h
    factory/MsgFac.h
)

target_link_libraries(NexusClient
    PRIVATE
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

