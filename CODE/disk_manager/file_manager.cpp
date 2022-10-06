//
// Created by Hugo Demaret on 22/09/2022.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <sys/stat.h>
#include <string>
#include "disk_manager.h"
#include "../error_handler/error.h"
#include "db_params.h"
#include <filesystem>
#include "filelist.h"
#include "../global.h"








//gets the list of pages from filelist.schema : a binary file that keeps record of the state of every files
//gets loaded when DB starts (or created if unexistent)
//faster than checking every file in the DB, but if the file gets deleted, then we are doomed :
//implement an alternative method to rebuild the file ? (maybe after if i'm not already dead/strongly deficient bc of c++)
std::vector<file> get_file_list(void){
    std::string f_path = main_db.db_paths + "fileslist.schema";
    char* path = f_path.data();
    FILE* input_file;
    input_file = fopen(path,"rb");
    if (input_file == NULL){
        err_message(3);
        exit(0);
    }
    struct stat st;
    stat(path, &st);
    int size = st.st_size / sizeof(file);
    file buffer[size];
    std::vector<file> f_list;
    fread(buffer, sizeof(file), size, input_file);
    f_list.push_back(buffer[0]);
    fclose(input_file);
    //free(buffer);
    return f_list;
}

void save_file_list(void){
    std::string f_path = main_db.db_paths + "fileslist.schema";
    char* path = f_path.data();
    FILE* output_file;
    output_file = fopen(path,"w+b");
    if (output_file == NULL){
        err_message(3);
        exit(0);
    }
    file buffer[file_list.size()];
    std::copy(file_list.begin(), file_list.end(), buffer);
    rewind(output_file);
    fwrite(buffer, sizeof(file), file_list.size(), output_file);
    fwrite(buffer, 1, sizeof(buffer), output_file);
    fclose(output_file);
    //free(buffer);
}


file init_file(uint32_t id){
    std::string str = std::to_string(id);
    file f;
    f.id = id;
    f.size = 0;
    f.nb_occupied = 0;
    for (int i=0; i<4; ++i){
        f.page_occupied[i] = false;
    }
    return f;
}