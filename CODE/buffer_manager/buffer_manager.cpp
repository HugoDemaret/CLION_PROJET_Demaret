//
// Created by Hugo Demaret on 06/10/2022.
//

#include "buffer_manager.h"


std::list<page_id> lru;
std::list<std::pair<frame,page_id> > frame_list;
std::list<frame> empty_frame_list;

/**
 * Loads a page into a buffer with a call to the disk manager, given a page_id
 * @param page
 * @return buffer filled with page
 */
char* get_page(page_id page){
    //if frames are not occupied
    //printf("Debug1");
    if (frame_list.empty()){
        printf("EMPTY FRAME\n");
        frame f = empty_frame_list.back();

        empty_frame_list.pop_back();

        read_page(page, f.buffer);

        f.pin_count++;
        f.page = page;
        frame_list.emplace_back(std::make_pair(f,page));
        return f.buffer;
    }
    if (frame_list.size() < main_db.frame_count){
        printf("NOT EMPTY FRAME BUT LESS\n");
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
        f.page = page;
        frame_list.emplace_back(std::make_pair(f,page));
        return f.buffer;
    }
    //LRU :
    printf("LRU\n");
    frame f = frame_list.front().first;
    frame_list.pop_front();
    read_page(page, f.buffer);
    f.pin_count++;
    f.page = page;
    frame_list.emplace_back(std::make_pair(f,page));
    return f.buffer;
}

/**
 * Frees the page, updates the dirt value accordingly
 * @param page
 * @param dirty
 */
void free_page(page_id page, bool dirty){
    for (auto & it : frame_list){
        if (it.second.id == page.id && it.second.file_id == page.file_id){
            it.first.pin_count--;
            it.first.dirt = dirty;
        }
    }
}

/**
 * Frees a buffer and sets it to NULL
 * @param buffer
 */
void free_buffer(char* buffer){
    if (buffer != NULL){
        free(buffer);
        buffer = NULL;
    }
}


/**
 * Flushes all pages and saves those with dirty set to true
 */
void flush_all(){
    for (auto & it : frame_list){
        if (it.first.dirt){
            write_page(it.second,it.first.buffer);
        }
        it.first.pin_count =0;
        it.first.dirt = false;

    }
    for (auto & it:empty_frame_list){
        if (it.dirt){
            write_page(it.page,it.buffer);
        }
        it.pin_count = 0;
        it.dirt = false;
    }
}


/**
 * Frees all the frames (buffers)
 */
void free_frames(){
    for (auto & it:empty_frame_list){
        free_buffer(it.buffer);
    }
    for (auto & it:frame_list){
        free_buffer(it.first.buffer);
    }
}


/**
 * Initialises all the frames for the DBMS
 */
void init_frames(){
    for(int i = 0; i<main_db.frame_count; ++i){

        char *buffer = NULL;
        buffer = (char*) calloc(main_db.page_size, sizeof (char));
        frame f;
        f.buffer = buffer;
        f.pin_count = 0;
        f.dirt = false;
        empty_frame_list.push_back(f);
    }
}



