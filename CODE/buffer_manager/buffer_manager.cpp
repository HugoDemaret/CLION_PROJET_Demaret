//
// Created by Hugo Demaret on 06/10/2022.
//

#include "buffer_manager.h"


std::vector<page_id> lru;
std::vector<frame> frame_list;
std::vector<frame> empty_frame_list;

char* get_page(page_id page){
    for (int i = 0; i<lru.size(); ++i){
        if (lru.at(i).id = page.id && lru.at(i).file_id == page.file_id) {

        }
    }
    if (frame_list.size() < main_db.frame_count){
        frame f = empty_frame_list.back();
        empty_frame_list.pop_back();
        f.pin_count++;
        f.page_id = page;
        lru.push_back(page);

    } else {

    }
    return "c";
}

void free_page(page_id page, bool dirty){

}

void flush_all(){

}


void init_frames(){
    char buffer[main_db.page_size];
    for(int i = 0; i<main_db.frame_count; ++i){
        frame f;
        f.buffer = buffer;
        f.pin_count = 0;
        f.dirt = false;
        empty_frame_list.push_back(f);
    }
}



