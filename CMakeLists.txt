project(reflectionCPP)

cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)

add_executable(reflectionCPP ${PROJECT_SOURCE_DIR}/main_test.cpp ${SRC_DIR})