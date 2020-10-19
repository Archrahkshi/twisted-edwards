cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(pazi_1)
add_executable(${PROJECT_NAME} main.cpp Point.h calc.cpp test.cpp calc.h test.h Point.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(NTL REQUIRED)
target_link_libraries(${PROJECT_NAME} ${NTL_LIBRARY})
