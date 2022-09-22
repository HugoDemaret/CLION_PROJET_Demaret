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

//returns true if file exists, false otherwise
bool exists_file(const std::string& name){
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}


//creates a files if it doesn't exists (return success : 0), return an error otherwise (code 4)
u_int8_t create_file(std::string str){
    if (!exists_file(str)){
        return 4;
    }
    std::ofstream file(str, std::ios::binary);
    file.close();
    return 0;
}

//opens a file if it exists, creates a new file and returns it if not
std::fstream get_file(std::string str){
    //we pass to the create_file :  it will check if it exists or create it otherwise, then we print the return value
    int8_t err_code = create_file(str);
    err_message(err_code);
    //then we return the file that has the corresponding name (that we either just created, or that already existed)
    std::fstream file(str, std::ios::binary);
}


//reads page with page_id, puts page into the buffer
void read_page(page_id page, std::vector<char>& buffer){
    if (exists_file("F" + std::to_string(page.file_id) + ".bdda")) {
        std::fstream file("F" + std::to_string(page.file_id) + ".bdda", std::ios::binary);
        buffer = std::vector(std::istreambuf_iterator<char>(file), {});
    }
    err_message(2);
}

