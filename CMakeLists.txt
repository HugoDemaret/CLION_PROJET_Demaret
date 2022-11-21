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
        CODE/db_params.h
        CODE/error_handler/error.h
        CODE/error_handler/error_handler.cpp CODE/disk_manager/disk_manager.cpp CODE/disk_manager/disk_manager.h CODE/disk_manager/file_manager.cpp CODE/disk_manager/page_id.h CODE/disk_manager/file.h CODE/disk_manager/filelist.h CODE/global.h CODE/tests_manager/test.cpp CODE/tests_manager/test.h CODE/buffer_manager/buffer_manager.h CODE/buffer_manager/buffer_manager.cpp CODE/buffer_manager/frame.h CODE/relation_manager/relation_info.h CODE/relation_manager/column_info.h CODE/relation_manager/catalog.h CODE/relation_manager/catalog_manager.cpp CODE/relation_manager/record.h)