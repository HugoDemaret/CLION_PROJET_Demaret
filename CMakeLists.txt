cmake_minimum_required(VERSION 3.19)
project(Projet_BDDA_DEMARET)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Projet_BDDA_DEMARET
        CODE/main.cpp
        CODE/interpreter/shell.cpp
        CODE/string_converter/case_modifier.cpp
        CODE/interpreter/interpreter.h
        CODE/string_converter/split.cpp
        CODE/string_converter/string_modifier.h
        CODE/interpreter/interpreter.cpp
        CODE/disk_manager/db_params.h
        CODE/error_handler/error.h
        CODE/error_handler/error_handler.cpp CODE/disk_manager/disk_manager.cpp CODE/disk_manager/disk_manager.h CODE/disk_manager/file_manager.cpp CODE/disk_manager/page_id.h CODE/disk_manager/file.h CODE/disk_manager/filelist.h)