cmake_minimum_required(VERSION 3.0.0)
project(exp )

include(CTest)
enable_testing()

set(SOURCES src/main.cpp src/Students.cpp)
add_executable(exp1 ${SOURCES})
target_include_directories(exp1 PRIVATE  include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
