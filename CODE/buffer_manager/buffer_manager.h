//
// Created by Hugo Demaret on 06/10/2022.
//

#ifndef PROJET_BDDA_DEMARET_BUFFER_MANAGER_H
#define PROJET_BDDA_DEMARET_BUFFER_MANAGER_H

#include "frame.h"

char* get_page(page_id page);
void free_page(page_id page, bool dirty);
void flush_all();

#endif //PROJET_BDDA_DEMARET_BUFFER_MANAGER_H
