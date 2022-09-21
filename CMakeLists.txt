cmake_minimum_required(VERSION 3.19)
project(Projet_BDDA_DEMARET)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet_BDDA_DEMARET CODE/main.cpp CODE/interpreter/shell.cpp CODE/string_converter/case_modifier.cpp CODE/interpreter/functions.h CODE/string_converter/split.cpp CODE/string_converter/string_modifier.h CODE/interpreter/interpreter.cpp)