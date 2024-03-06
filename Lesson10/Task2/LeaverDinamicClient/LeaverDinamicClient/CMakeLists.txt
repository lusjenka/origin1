cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
project(Leaver_project VERSION 1.0)
include_directories(E:/Study/Lesson10/Task2/LeaverDinamicClient/LeaverLibraryDinamic)
add_executable(Leaver_project LeaverDinamicClient.cpp)
#add_subdirectory(LibraryDinamic)
target_link_libraries(Leaver_project LeaverDinamic_project)

