cmake_minimum_required(VERSION 3.19)
project(Projet_BDDA_DEMARET)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Projet_BDDA_DEMARET
        CODE/main.cpp
        CODE/interpreter/shell.cpp
        CODE/utils/case_modifier.cpp
        CODE/interpreter/interpreter.h
        CODE/utils/split.cpp
        CODE/utils/string_modifier.h
        CODE/interpreter/interpreter.cpp
        CODE/db_params.h
        CODE/error_handler/error.h
        CODE/error_handler/error_handler.cpp CODE/disk_manager/disk_manager.cpp CODE/disk_manager/disk_manager.h CODE/disk_manager/file_manager.cpp CODE/disk_manager/page_id.h CODE/disk_manager/file.h CODE/disk_manager/filelist.h CODE/global.h CODE/tests_manager/test.cpp CODE/tests_manager/test.h CODE/buffer_manager/buffer_manager.h CODE/buffer_manager/buffer_manager.cpp CODE/buffer_manager/frame.h CODE/relation_manager/catalog.cpp CODE/relation_manager/record.h CODE/relation_manager/record.cpp CODE/utils/write_read_buffer.cpp CODE/utils/util.h)