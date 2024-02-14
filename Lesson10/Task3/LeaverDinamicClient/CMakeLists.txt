cmake_minimum_required(VERSION 3.22.0)

project(LeaverDinamic_project VERSION 1.0)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(LeaverDinamic SHARED 
			./LeaverLibraryDinamic/LeaverDinamic.cpp 
			./LeaverLibraryDinamic/LeaverDinamic.h
)

target_include_directories(LeaverDinamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/LeaverLibraryDinamic)

add_executable(LD_p 
            ./LeaverDinamicClient/LeaverDinamicClient.cpp)

target_link_libraries(LD_p LeaverDinamic)