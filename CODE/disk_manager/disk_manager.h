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


//file_manager.cpp
bool exists_file(const std::string& name);
std::ifstream get_file(std::string str);
u_int8_t create_file(std::string str);
std::vector<file> get_file_list();
void save_file_list(std::vector<file> file_list);
file init_file(uint32_t id);

//disk_manager.cpp
std::vector<page_id> get_available_page_list(std::vector<file> file_list);
void read_page(page_id page, std::vector<char>& buffer);
page_id alloc_page(std::vector<file> page_list);
std::vector<page_id> get_page_list(std::vector<file> file_list);
void init_pages(std::vector<file> file_list);
//


#endif //PROJET_BDDA_DEMARET_DISK_MANAGER_H
