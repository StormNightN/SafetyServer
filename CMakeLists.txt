cmake_minimum_required(VERSION 3.7)
project(SafetyServer)

set(CMAKE_CXX_STANDARD 14)
find_package(spdlog REQUIRED)
find_package(Threads)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCES main.cpp Server.cpp)

if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O2")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wpedantic -pedantic")
endif()

add_library(SafetyCommon SHARED IMPORTED)
set_property(TARGET SafetyCommon PROPERTY IMPORTED_LOCATION "../SafetyCommonLibrary/libSafetyCommon.so")
include_directories(../SafetyCommonLibrary/include)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}   SafetyCommon
                                        spdlog::spdlog
                                        ${CMAKE_THREAD_LIBS_INIT})