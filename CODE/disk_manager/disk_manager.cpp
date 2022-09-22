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

page_id alloc_page(){
    return page_id none;
}

void read_page(page_id page, std::vector<std::string> buffer){

}