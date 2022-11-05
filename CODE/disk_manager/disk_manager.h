//
// Created by Hugo Demaret on 22/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_DISK_MANAGER_H
#define PROJET_BDDA_DEMARET_DISK_MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "page_id.h"
#include "file.h"
//variables


//file_manager.cpp
bool exists_file(const std::string& name);
std::fstream get_file(std::string str);
u_int8_t create_file(std::string str);
std::vector<file> get_file_list();
void save_file_list();
file init_file(u_int16_t id);
void save_nb_file();
u_int16_t get_nb_file();

//disk_manager.cpp
std::vector<page_id> get_available_page_list();
void read_page(page_id page, char* buffer);
void write_page(page_id page, char* buffer);
page_id alloc_page();
void dealloc_page(page_id page);
std::vector<page_id> get_page_list();
void init_pages();
//


#endif //PROJET_BDDA_DEMARET_DISK_MANAGER_H
