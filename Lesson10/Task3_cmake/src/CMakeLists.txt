cmake_minimum_required(VERSION 3.22.0)
project(MathPower)
add_library(MathPowerDynamicLib SHARED leaver.cpp leaver.h)
add_executable(MathPowerExe LeaverClient.cpp)
target_link_libraries(MathPowerExe MathPowerDynamicLib)



