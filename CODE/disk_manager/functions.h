//
// Created by Hugo Demaret on 22/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_FUNCTIONS_H
#define PROJET_BDDA_DEMARET_FUNCTIONS_H

#include "page_id.h"

bool exists_file(const std::string& name);
void read_page(page_id page, std::vector<char>& buffer);
std::fstream get_file(std::string str);
u_int8_t create_file(std::string str);

#endif //PROJET_BDDA_DEMARET_FUNCTIONS_H
