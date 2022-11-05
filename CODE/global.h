//
// Created by Hugo Demaret on 29/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_GLOBAL_H
#define PROJET_BDDA_DEMARET_GLOBAL_H



#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <stdio.h>
#include "db_params.h"
#include "disk_manager/disk_manager.h"
#include "disk_manager/file.h"
#include "buffer_manager/buffer_manager.h"



extern db_params main_db;

#define DEBUG 1
#define PAGE_SIZE 4
#define DB_PATH "../DB/"
#define MAX_PAGES_PER_FILE 4
#define MAX_FRAME_COUNT 2


extern std::vector<file> file_list; //file list
extern std::vector<page_id> a_p_list; //available pages list
extern std::vector<page_id> p_list; //pages list (available and not available)


#endif //PROJET_BDDA_DEMARET_GLOBAL_H
