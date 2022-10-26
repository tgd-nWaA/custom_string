# CMakeList.txt : CMake project for MyString, include source and define
# project specific logic here.
#
project(CustomStringCpp)
cmake_minimum_required (VERSION 3.8)


# Add source to this project's executable.
# add_executable (MyString "MyString.cpp" "MyString.h" "Main.cpp")




set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(include)
link_directories(lib)
add_subdirectory(src)
add_subdirectory(test)
#add_subdirectory(lib/googletest)

# TODO: Add tests and install targets if needed.
