cmake_minimum_required(VERSION 3.9)


project(MyOpenCVProj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(MyOpenCVProj ${SOURCE_FILES})
find_package(OpenCV REQUIRED)
target_link_libraries(MyOpenCVProj ${OpenCV_LIBS})
