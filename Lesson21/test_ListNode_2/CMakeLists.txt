#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(test_ListNode_2)
#добавляем поддиректорию, в которой будет catch2
add_subdirectory(catch2)
#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(test_ListNode_2 main.cpp)
add_executable(testListNodeTest test-main.cpp)
#линкуемся к catch2, в котором уже есть main
target_link_libraries(testListNodeTest PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)