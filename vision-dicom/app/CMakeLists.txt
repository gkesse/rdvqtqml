cmake_minimum_required(VERSION 3.21)
project(rdvdicom VERSION 1.0 LANGUAGES CXX)

set(SRC_FILES
    main.cpp
    Frameless.hpp
    Frameless.cpp
    GUIFrame.hpp
    GUIFrame.cpp
)

set(RCC_FILES
    app.qrc
)

qt_wrap_ui(UI_FILES
    GUIFrame.ui
)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    ${RCC_FILES}
    ${UI_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    base
    Qt6::Widgets
)
