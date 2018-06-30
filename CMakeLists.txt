project(MyOpenCVProjs)

cmake_minimum_required(VERSION 3.9)
execute_process(COMMAND sh ${PROJECT_SOURCE_DIR}/uic.sh)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        mainwindow.cpp
        ui_mainwindow.h
        mainwindow.h
        OpenCV/HelloWorld/opencv/showImage.hpp
        OpenCV/HelloWorld/views/CHelloWorldView.cpp
        OpenCV/HelloWorld/views/CHelloWorldView.h
        CUtils.hpp
        OpenCV/BaseView/CBaseView.cpp
        OpenCV/BaseView/CBaseView.h
        OpenCV/CutImage/views/CCutImgView.cpp
        OpenCV/CutImage/views/CCutImgView.h
        OpenCV/CutImage/opencv/cutImage.hpp OpenCV/BaseOpenCv/CBaseOpenCV.cpp OpenCV/BaseOpenCv/CBaseOpenCV.h)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH /Applications/QT/SRC/5.10.0)
set(Qt5Widgets_DIR /Applications/QT/SRC/5.10.0/clang_64/lib/cmake/Qt5Widgets)

find_package(Qt5Widgets)

add_executable(MyOpenCVProjs ${SOURCE_FILES})
find_package(OpenCV REQUIRED)

target_link_libraries(MyOpenCVProjs Qt5::Widgets ${OpenCV_LIBS})
