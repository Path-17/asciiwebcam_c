cmake_minimum_required(VERSION 3.15)
project(asciiWebcam)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(asciiWebcam main.cpp)
target_link_libraries(asciiWebcam ${OpenCV_LIBS})