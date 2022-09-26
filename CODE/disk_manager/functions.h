//
// Created by Hugo Demaret on 22/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_FUNCTIONS_H
#define PROJET_BDDA_DEMARET_FUNCTIONS_H

#include "page_id.h"
#include "file.h"

bool exists_file(const std::string& name);
void read_page(page_id page, std::vector<char>& buffer);
std::ifstream get_file(std::string str);
u_int8_t create_file(std::string str);
std::vector<file> get_file_list(void);
page_id alloc_page(std::vector<file> page_list);
std::vector<page_id> get_page_list(std::vector<file> file_list);
void save_file_list(std::vector<file> file_list);
std::vector<page_id> get_available_page_list(std::vector<file> file_list);


#endif //PROJET_BDDA_DEMARET_FUNCTIONS_H
