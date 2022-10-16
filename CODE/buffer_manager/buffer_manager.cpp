//
// Created by Hugo Demaret on 06/10/2022.
//

#include "buffer_manager.h"


std::list<page_id> lru;
std::list<std::pair<frame,page_id> > frame_list;
std::list<frame> empty_frame_list;

char* get_page(page_id page){
    //if frames are not occupied
    if (frame_list.empty()){
        frame f = empty_frame_list.back();
        empty_frame_list.pop_back();
        read_page(page, f.buffer);
        f.pin_count++;
        frame_list.push_back(std::make_pair(f,page));
        return f.buffer;
    }
    if (frame_list.size() < main_db.frame_count){
        bool in = false;
        for (auto it = frame_list.begin(); it != frame_list.end() && !in; ++it) {
            if (it->second.file_id == page.file_id && it->second.id == page.id) {
                in = true;
                it->first.pin_count++;
                return it->first.buffer;
            }
        }
        frame f = empty_frame_list.back();
        empty_frame_list.pop_back();
        read_page(page, f.buffer);
        f.pin_count++;
        frame_list.push_back(std::make_pair(f,page));
        return f.buffer;
    }
    //LRU :
    frame f = frame_list.front().first;
    frame_list.pop_front();
    read_page(page, f.buffer);
    f.pin_count++;
    frame_list.push_back(std::make_pair(f,page));
    return f.buffer;
}

void free_page(page_id page, bool dirty){
    for (auto it = frame_list.begin(); it != frame_list.end(); ++it){
        if (it->second.id == page.id && it->second.file_id == page.file_id){
            it->first.pin_count--;


        }
    }
}

void flush_all(){
    char buffer[main_db.page_size];
    for (auto it = frame_list.begin(); it != frame_list.end(); ++it){
        if (it->first.dirt){
            write_page(it->second,it->first.buffer);
        }
        it->first.pin_count =0;
        it->first.dirt = false;
        it->first.buffer = buffer;
    }
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



