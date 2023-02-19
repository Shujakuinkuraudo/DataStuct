cmake_minimum_required(VERSION 3.0.0)
project(sort )

include(CTest)
enable_testing()

set(SOURCES src/main.cpp )
add_executable(sort ${SOURCES})
target_include_directories(sort PRIVATE  include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
