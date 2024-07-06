cmake_minimum_required(VERSION 3.27)

project(qtsandbox
        DESCRIPTION "QT APPLICATION SANDBOX"
        LANGUAGES CXX
        VERSION 0.1.0
)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# Qt setup
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

option(USE_CLANG_TIDY "Use Clang-tidy" OFF)

include(${CMAKE_MODULE_PATH}/myVariables.cmake)
include(${CMAKE_MODULE_PATH}/ClangFormat.cmake)
include(${CMAKE_MODULE_PATH}/MakeDoc.cmake)

if (USE_CLANG_TIDY)
    include(${CMAKE_MODULE_PATH}/ClangTidy.cmake)
endif()

clangformat_setup()

add_subdirectory(lib)

file(GLOB_RECURSE SRCS ${SRC_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE my_lib Qt5::Core Qt5::Gui Qt5::Widgets)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
