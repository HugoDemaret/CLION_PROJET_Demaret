//
// Created by Hugo Demaret on 22/09/2022.
//
#include <fstream>
#include <sys/stat.h>
#include "db_params.h"
#include <iostream>
#include <string>
#include "functions.h"
#include "../error_handler/error.h"
#include "page_id.h"
#include <vector>
#include "file.h"


page_id alloc_page(){
    std::vector<file> file_list = get_file_list();
    for (auto f : page_list){

    }
}



//reads page with page_id, puts page into the buffer
void read_page(page_id page, std::vector<char>& buffer){
    if (exists_file("F" + std::to_string(page.file_id) + ".bdda")) {
        std::fstream file("F" + std::to_string(page.file_id) + ".bdda", std::ios::binary);
        buffer = std::vector(std::istreambuf_iterator<char>(file), {});
    }
    err_message(2);
}

