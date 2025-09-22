cmake_minimum_required(VERSION 3.21)
project(rdvdicom VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
)

include_directories(${CMAKE_HOME_DIRECTORY})

add_subdirectory(app)
add_subdirectory(base)

