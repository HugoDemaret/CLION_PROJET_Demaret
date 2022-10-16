//
// Created by Hugo Demaret on 06/10/2022.
//

#ifndef PROJET_BDDA_DEMARET_BUFFER_MANAGER_H
#define PROJET_BDDA_DEMARET_BUFFER_MANAGER_H

#include "frame.h"
#include "../global.h"
#include "../disk_manager/disk_manager.h"

extern std::vector<page_id> lru;
extern std::vector<frame> frame_list;
extern std::vector<frame> empty_frame_list;

char* get_page(page_id page);
void free_page(page_id page, bool dirty);
void flush_all();
void init_frames();

#endif //PROJET_BDDA_DEMARET_BUFFER_MANAGER_H
