cmake_minimum_required (VERSION 3.5)
project (qt-opencv-samples)
include(ExternalProject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)
find_package(OpenCV REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

FILE(GLOB_RECURSE headerFiles "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
FILE(GLOB_RECURSE sourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
FILE(GLOB_RECURSE resourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/src/*.qrc")

add_executable(${PROJECT_NAME} ${sourceFiles} ${headerFiles} ${resourceFiles})

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    Qt5::QuickControls2
    ${OpenCV_LIBS})
