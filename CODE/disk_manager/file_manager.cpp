//
// Created by Hugo Demaret on 22/09/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <string>
#include "functions.h"
#include "../error_handler/error.h"
#include "db_params.h"
#include <filesystem>


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
    return file;
}


//gets the list of pages from filelist.schema : a binary file that keeps record of the state of every files
//gets loaded when DB starts (or created if unexistent)
//faster than checking every file in the DB, but if the file gets deleted, then we are doomed :
//implement an alternative method to rebuild the file ? (maybe after if i'm not already dead/strongly deficient bc of c++)
void get_page_list(std::vector<page_id> page_list){
    std::fstream init_file = get_file("filelist.schema");

}
