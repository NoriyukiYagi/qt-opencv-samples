cmake_minimum_required (VERSION 3.14)
project (qt-opencv-samples)
include(ExternalProject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)

set(OPENCV_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv)
set(OPENCV_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/install/opencv)
ExternalProject_Add(opencv
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external/opencv
    SOURCE_DIR ${OPENCV_SOURCE_DIR}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${OPENCV_INSTALL_DIR})
include_directories(${OPENCV_INSTALL_DIR}/include)
if(WIN32)
    FILE(GLOB_RECURSE opencvLibs "${OPENCV_INSTALL_DIR}/*.lib")
else()
    FILE(GLOB_RECURSE opencvLibs "${OPENCV_INSTALL_DIR}/*.a")
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

FILE(GLOB_RECURSE headerFiles "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
FILE(GLOB_RECURSE sourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
FILE(GLOB_RECURSE resourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/src/*.qrc")

add_executable(${PROJECT_NAME} ${sourceFiles} ${headerFiles} ${resourceFiles})
add_dependencies(${PROJECT_NAME} opencv)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    Qt5::QuickControls2
    ${opencvLibs})
