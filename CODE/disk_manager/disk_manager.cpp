//
// Created by Hugo Demaret on 22/09/2022.
//
#include <fstream>
#include <sys/stat.h>
#include "db_params.h"
#include <iostream>
#include <string>
#include "functions.h"
#include "../error_handler/error.h"
#include "page_id.h"
#include <vector>
#include "file.h"
#include "filelist.h"

page_id alloc_page(){
    //todo
}



//reads page with page_id, puts page into the buffer
void read_page(page_id page, std::vector<char>& buffer){
    if (exists_file("F" + std::to_string(page.file_id) + ".bdda")) {
        std::fstream file("F" + std::to_string(page.file_id) + ".bdda", std::ios::binary);
        buffer = std::vector(std::istreambuf_iterator<char>(file), {});
    }
    err_message(2);
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
}