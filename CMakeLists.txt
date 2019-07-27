cmake_minimum_required(VERSION 3.7)
project(SafetyServer)

set(CMAKE_CXX_STANDARD 14)
find_package(spdlog REQUIRED)
find_package(Threads)

add_library(SafetyCommon SHARED IMPORTED)
set_property(TARGET SafetyCommon PROPERTY IMPORTED_LOCATION "../SafetyCommonLibrary/libSafetyCommon.so")
add_executable(${PROJECT_NAME} main.cpp Server.cpp Server.h)

include_directories(../SafetyCommonLibrary/include)

target_link_libraries(${PROJECT_NAME} SafetyCommon spdlog::spdlog ${CMAKE_THREAD_LIBS_INIT})