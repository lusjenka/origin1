cmake_minimum_required(VERSION 3.22.0)
project(LeaverDinamic_project VERSION 1.0)
set(LeaverDinamic_project_source LeaverDinamic.cpp LeaverDinamic.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(LeaverDinamic_project SHARED ${LeaverDinamic_project_source})

