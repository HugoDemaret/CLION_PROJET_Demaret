//
// Created by Hugo Demaret on 22/09/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <string>
#include "disk_manager.h"
#include "../error_handler/error.h"
#include "db_params.h"
#include <filesystem>
#include "filelist.h"



//returns true if file exists, false otherwise
bool exists_file(const std::string& name){
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}


//creates a files if it doesn't exists (return success : 0), return an error otherwise (code 4)
u_int8_t create_file(std::string str){
    if (!exists_file("F" + str + ".bdda")){
        return 4;
    }
    std::ofstream file("F" + str + ".bdda", std::ios::binary);
    file.close();
    return 0;
}

//opens a file if it exists, creates a new file and returns it if not
std::ifstream get_file(std::string str){
    //we pass to the create_file :  it will check if it exists or create it otherwise, then we print the return value
    int8_t err_code = create_file(str);
    err_message(err_code);
    //then we return the file that has the corresponding name (that we either just created, or that already existed)
    std::ifstream file(str, std::ios::binary);
    return file;
}


//gets the list of pages from filelist.schema : a binary file that keeps record of the state of every files
//gets loaded when DB starts (or created if unexistent)
//faster than checking every file in the DB, but if the file gets deleted, then we are doomed :
//implement an alternative method to rebuild the file ? (maybe after if i'm not already dead/strongly deficient bc of c++)
std::vector<file> get_file_list(void){
    std::string f_path = db_main.db_paths + "fileslist.schema";
    std::ifstream f_list = get_file(f_path);
    //get fileslist.schema size
    std::size_t f_size = std::filesystem::file_size(f_path);
    //if files are registered (that is, they exist in fileslist.schema)
    //gets the number of files in fileslist.schema
    const size_t count = f_size / sizeof(file);
    std::vector<file> file_list(count);
    f_list.read(reinterpret_cast<char *>(&file_list[0]), count * sizeof(file));
    return file_list;
}

void save_file_list(std::vector<file> file_list){
    //todo : improve ?
    std::string f_path = db_main.db_paths + "fileslist.schema";
    std::ofstream fout(f_path, std::ios::out | std::ios::binary);
    fout.write((char*)&file_list[0], file_list.size() * sizeof(file));
    fout.close();
}


file init_file(uint32_t id){
    std::string str = std::to_string(id);
    create_file(str);
    file f;
    f.id = id;
    f.size = 0;
    f.nb_occupied = 0;
    for (int i=0; i<4; ++i){
        f.page_occupied[i] = false;
    }
    return f;
}