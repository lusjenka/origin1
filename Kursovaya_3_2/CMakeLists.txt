cmake_minimum_required(VERSION 3.10)
project(Kursovaya_3_2)
add_executable(Kursovaya_3_2 main.cpp Parser.h Parser.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.ini
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
