cmake_minimum_required(VERSION 3.7)
project(SafetyServer)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)


add_library(SafetyCommon STATIC IMPORTED)
set_property(TARGET SafetyCommon PROPERTY IMPORTED_LOCATION "../SafetyCommonLibrary/libSafetyCommon.a")
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} SafetyCommon)