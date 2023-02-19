cmake_minimum_required(VERSION 3.0.0)
project(tree )

include(CTest)
enable_testing()

set(SOURCES src/main.cpp)
add_executable(tree ${SOURCES})
target_include_directories(tree PRIVATE  include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
