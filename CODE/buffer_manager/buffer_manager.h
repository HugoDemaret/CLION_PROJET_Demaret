//
// Created by Hugo Demaret on 06/10/2022.
//

#ifndef PROJET_BDDA_DEMARET_BUFFER_MANAGER_H
#define PROJET_BDDA_DEMARET_BUFFER_MANAGER_H

#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <stdio.h>
#include "frame.h"
#include "../disk_manager/disk_manager.h"

extern std::list<page_id> lru;
extern std::list<std::pair<frame,page_id> > frame_list;
extern std::list<frame> empty_frame_list;

char* get_page(page_id page);
void free_page(page_id page, bool dirty);
void flush_all();
void init_frames();
void free_buffer(char** buffer);
void free_frames();

#endif //PROJET_BDDA_DEMARET_BUFFER_MANAGER_H
