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
#include "../db_params.h"
#include <filesystem>
#include "filelist.h"
#include "../global.h"

const char* FILE_S_IN = "{%[^,],%d,%d}";
const char* FILE_S_OUT = "{%s,%d,%d}";






//gets the list of pages from filelist.schema : a binary file that keeps record of the state of every files
//gets loaded when DB starts (or created if unexistent)
//faster than checking every file in the DB, but if the file gets deleted, then we are doomed :
//implement an alternative method to rebuild the file ? (maybe after if i'm not already dead/strongly deficient bc of c++)
std::vector<file> get_file_list(void){

    std::vector<file> f_list;
/*
    std::string f_path = main_db.db_paths + "fileslist.schema";
    FILE* output_file;
    char* path = f_path.data();
    output_file = fopen(path,"r");
    if (output_file != NULL) {
        for (int i = 0; i < main_db.total_nb_file; ++i) {
            file f;
            char occupied[MAX_PAGES_PER_FILE];
            fscanf(output_file, FILE_S_IN,  occupied, &f.nb_occupied, &f.id);
            for (int i = 0; i<MAX_PAGES_PER_FILE; ++i){
                f.page_occupied[i] = (occupied[i] == '1');
            }
            f_list.push_back(f);
        }
        fclose(output_file);
    }
*/
    return f_list;



    /*
    //std::cout << main_db.db_paths << " here" << std::endl;
    //std::cout << f_path << std::endl;
    std::string f_path = main_db.db_paths + "fileslist.schema";
    std::fstream f_list(f_path, std::ios::binary);
    //get fileslist.schema size
    std::size_t f_size = std::filesystem::file_size(f_path);
    //if files are registered (that is, they exist in fileslist.schema)
    //gets the number of files in fileslist.schema
    const size_t count = f_size / sizeof(file);
    std::vector<file> file_list(count);
    f_list.read(reinterpret_cast<char *>(&file_list[0]), count * sizeof(file));
    return file_list;
    /*
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
     */
}

void save_file_list(void){
    /*
    std::string f_path = main_db.db_paths + "fileslist.schema";
    std::ofstream fout(f_path, std::ios::out | std::ios::binary);
    fout.write((char*)&file_list[0], file_list.size() * sizeof(file));
    fout.close();
    */
    /*
    printf("DEBUG");
    std::string f_path = main_db.db_paths + "fileslist.schema";
    FILE* output_file;
    char* path = f_path.data();

    output_file = fopen(path,"w");
    if (output_file != NULL) {
        for (auto f : file_list) {
            char occupied[MAX_PAGES_PER_FILE];
            for (int i = 0; i<MAX_PAGES_PER_FILE; ++i){
                occupied[i] = f.page_occupied[i] ? '1' : '0';
            }
            fprintf(output_file, FILE_S_OUT, occupied, f.nb_occupied, f.id);
        }
        fclose(output_file);
    }
    */
}

u_int16_t get_nb_file(){
    std::string f_path = main_db.db_paths + "nb_files.schema";
    //opens the file in binary mode
    u_int16_t nb_file = 0;
    FILE* input_file;
    char* path = f_path.data();
    input_file = fopen(path,"r");
    fscanf(input_file,"%d",&nb_file);
    fclose(input_file);
    return nb_file;
}

void save_nb_file(void){
    std::string f_path = main_db.db_paths + "nb_files.schema";
    //opens the file in binary mode
    FILE* output_file;
    char* path = f_path.data();
    output_file = fopen(path,"w");
    fprintf(output_file,"%d",main_db.total_nb_file);
    //fprintf(output_file,"%d",0);
    //putw(main_db.total_nb_file,output_file);
    fclose(output_file);
}

file init_file(uint16_t id){
    std::string str = std::to_string(id);
    file f;
    f.id = id;
    //f.size = 0;
    f.nb_occupied = 0;
    for (int i=0; i<4; ++i){
        f.page_occupied[i] = false;
    }

    std::string f_path = main_db.db_paths + "F" + str + ".bdda";
    //opens the file in binary mode
    FILE* output_file;
    char* path = f_path.data();
    output_file = fopen(path,"r+b");
    if (output_file == NULL){
        output_file = fopen(path,"w+b");
    }
    fclose(output_file);

    return f;
}