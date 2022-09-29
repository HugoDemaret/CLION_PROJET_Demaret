//
// Created by Hugo Demaret on 22/09/2022.
//
#include <fstream>
#include <sys/stat.h>
#include "db_params.h"
#include <iostream>
#include <string>
#include "disk_manager.h"
#include "../error_handler/error.h"
#include "page_id.h"
#include <vector>
#include "file.h"
#include "filelist.h"
#include "../global.h"

std::vector<page_id> a_p_list;
std::vector<page_id> p_list;


//allocates a page from the a_p_list
page_id alloc_page(){
    //if available page list is empty, creates new file, initializes pages and uses the first page of the file
    if (a_p_list.empty()) {
        uint32_t id = f_list.size();
        file f = init_file(id);
        f_list.push_back(f);
        a_p_list = get_available_page_list(f_list);
    }
    //returns the first page available
    page_id page;
    //allocates a page to be returned with last value in vector (we use a stack => allows for a sequential fill of the files
    // thus optimising the space taken on the disk)
    page = a_p_list.back();
    //removes the allocated page in the vector
    // in f_list sets the page to occupied
    for (auto fi : f_list){
        if (fi.id == page.file_id){
            fi.nb_occupied++;
            fi.page_occupied[page.id] = true;
        }
    }
    a_p_list.pop_back();
    return page;
}


//deallocates a page given its page_id
void dealloc_page(page_id page){
    //in f_list sets the page to not occupied
    for (auto fi : f_list){
        if (fi.id == page.file_id){
            fi.nb_occupied--;
            fi.page_occupied[page.id] = false;
        }
    }
    a_p_list.push_back(page);
}



//reads page with page_id, puts page into the buffer
void read_page(page_id page, char *buffer[]){
    if ((page.id >= 4) && exists_file("F" + std::to_string(page.file_id) + ".bdda")) {
        err_message(3);
    } else {
        //todo : open file ; get to position page.id * 4096; load into the buffer from page.id * 4096 to page.id *4096 + 4095
        std::fstream file = get_file("F" + std::to_string(page.file_id) + ".bdda" );
        file.seekg(page.id * 4096 , std::ios::end);
        file.read(*buffer, 4096);
    }
}

void write_page(page_id page, char *buffer[]){
    //todo : open file; get to position page.id*4k; writes with f.write();
    if ((page.id >= 4) && exists_file("F" + std::to_string(page.file_id) + ".bdda")) {
        err_message(3);
    } else {
        std::fstream file = get_file("F" + std::to_string(page.file_id) + ".bdda" );
        file.seekg(page.id * 4096 , std::ios::end);
        file.write(*buffer, 4096);
    }
}

//note that this function merely gets the list of pages, not the list of pages where it is possible to write
//in order to write into a page, the programme will use the get_available_page_list() function
std::vector<page_id> get_page_list(std::vector<file> file_list){
    std::vector<page_id> page_list;
    for (auto f : file_list){
        for (int i = 0; i<4; ++i){
            page_id page;
            page.file_id = f.id; //sets the id of the file for the page
            page.id = i; // sets the id of the page (ranging from 0 to 3) => 4 pages maximum
            page_list.push_back(page); //adds the page to the list of pages
        }
    }
    return page_list;
}

//gets the pages that are available to write in
//differs in that it checks if the page is empty
std::vector<page_id> get_available_page_list(std::vector<file> file_list){
    std::vector<page_id> page_list;
    for (auto f : file_list){
        for (int i = 0; i<4; ++i){
            //only if the page isn't occupied !
            if (!f.page_occupied[i]) {
                page_id page;
                page.file_id = f.id; //sets the id of the file for the page
                page.id = i; // sets the id of the page (ranging from 0 to 3) => 4 pages maximum
                page_list.push_back(page); //adds the page to the list of pages
            }
        }
    }
    return page_list;
}

//initializes the pages at the start of the programme (see in main.cpp)
void init_pages(std::vector<file> file_list){
    a_p_list = get_available_page_list( file_list);
    p_list = get_page_list(file_list);
}

int get_current_count_alloc_pages(){
    //f_list.size()*4 gives the total number of pages (alloc or not)
    //a_p_list.size() give the total number of non alloc pages
    //thus we have the number of allocated pages without computing anything more complex (such as iterating over the lists)
    return f_list.size()*4-a_p_list.size();
}