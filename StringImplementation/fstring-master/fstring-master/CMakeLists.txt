cmake_minimum_required(VERSION 3.10)
project(FStringfwd.h)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CXX_FLAGS -Wall -Werror)
set(CMAKE_CXX_STANDARD 11)

add_executable(FString_test FString_test.cpp)
target_link_libraries(FString_test gtest)
