//
// Created by Hugo Demaret on 25/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_FILELIST_H
#define PROJET_BDDA_DEMARET_FILELIST_H

#include "file.h"
#include "disk_manager.h"

extern std::vector<file> f_list; //file list
extern std::vector<page_id> a_p_list; //available pages list
extern std::vector<page_id> p_list; //pages list (available and not available)


#endif //PROJET_BDDA_DEMARET_FILELIST_H
