cmake_minimum_required(VERSION 3.10.0)
project(rdvvtk VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    OpenGLWidgets
)

find_package(VTK 9.5 REQUIRED COMPONENTS
    GUISupportQt
    IOLegacy
)

include_directories(${CMAKE_HOME_DIRECTORY})

set(SRC_FILES
    main.cpp
    MainWindow.hpp
    MainWindow.cpp
    SceneWidget.hpp
    SceneWidget.cpp
)

qt_wrap_ui(UI_FILES
    MainWindow.ui
)

set(RCC_FILES
    resources.qrc
)

qt_add_executable(${PROJECT_NAME} WIN32
    ${SRC_FILES}
    ${UI_FILES}
    ${RCC_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::OpenGLWidgets
    VTK::GUISupportQt
    VTK::IOLegacy
)
