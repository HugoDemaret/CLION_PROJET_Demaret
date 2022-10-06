//
// Created by Hugo Demaret on 29/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_GLOBAL_H
#define PROJET_BDDA_DEMARET_GLOBAL_H

#include <algorithm>
#include <stdio.h>
#include "disk_manager/disk_manager.h"
#include "disk_manager/db_params.h"
#include "disk_manager/file.h"


extern db_params main_db;

extern std::vector<file> file_list; //file list
extern std::vector<page_id> a_p_list; //available pages list
extern std::vector<page_id> p_list; //pages list (available and not available)


#endif //PROJET_BDDA_DEMARET_GLOBAL_H
