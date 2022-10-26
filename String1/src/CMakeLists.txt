# CMakeList.txt : CMake project for MyString, include source and define
# project specific logic here.
#
set(BINARY ${CMAKE_PROJECT_NAME})
cmake_minimum_required (VERSION 3.8)



# Local header files here ONLY
SET(TARGET_H
    MyString.h 
   )

# Local source files here
SET(TARGET_SRC
    MyString.cpp
    )

	# Local source files here
SET(TARGET_SRC_MAIN
    Main.cpp
    )
	
add_executable(${BINARY}_run ${TARGET_H}  ${TARGET_SRC}  ${TARGET_SRC_MAIN} )
add_library(${BINARY}_lib STATIC ${TARGET_H}  ${TARGET_SRC})
# TODO: Add tests and install targets if needed.
