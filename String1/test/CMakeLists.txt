# CMakeList.txt : CMake project for MyString, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
set(BINARY ${CMAKE_PROJECT_NAME}_test)



# Local source files here
SET(Test_SRC
    MyStringTest.cpp
	MainTest.cpp
    )


add_executable(${BINARY} ${Test_SRC})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

# TODO: Add tests and install targets if needed.
