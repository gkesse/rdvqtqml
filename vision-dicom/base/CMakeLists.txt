cmake_minimum_required(VERSION 3.21)
project(base VERSION 1.0 LANGUAGES CXX)

set(SRC_FILES
    Config.hpp
    Config.cpp
    Tools.hpp
    Tools.cpp
)

add_library(${PROJECT_NAME}
    ${SRC_FILES}
)
