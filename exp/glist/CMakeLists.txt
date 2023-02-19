cmake_minimum_required(VERSION 3.0.0)
project(glist )

include(CTest)
enable_testing()

set(SOURCES src/main.cpp )
add_executable(glist ${SOURCES})
target_include_directories(glist PRIVATE  include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
