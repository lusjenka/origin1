cmake_minimum_required(VERSION 3.22.0)

project(LeaverDinamic_project)
add_library(LeaverDinamic SHARED LeaverLibraryDinamic/LeaverDinamic.cpp LeaverLibraryDinamic/LeaverDinamic.h)
add_executable(LD_p LeaverDinamicClient/LeaverDinamicClient.cpp)
target_link_libraries(LD_p LeaverDinamic)
