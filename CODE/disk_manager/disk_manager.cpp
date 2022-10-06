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
        uint32_t id = file_list.size();
        file f = init_file(id);
        file_list.push_back(f);
        a_p_list = get_available_page_list();
    }
    //returns the first page available
    page_id page;
    //allocates a page to be returned with last value in vector (we use a stack => allows for a sequential fill of the files
    // thus optimising the space taken on the disk)
    page = a_p_list.back();
    //removes the allocated page in the vector
    // in f_list sets the page to occupied
    for (auto fi : file_list){
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
    for (auto fi : file_list){
        if (fi.id == page.file_id){
            fi.nb_occupied--;
            fi.page_occupied[page.id] = false;
        }
    }
    a_p_list.push_back(page);
}



//reads page with page_id, puts page into the buffer
void read_page(page_id page, char* buffer){
    //checks if the page asked for respect the max number of pages available
    if (page.id >= main_db.max_pages_per_file) {
        err_message(4);
    } else {
       //sets the file path
        std::string f_path = main_db.db_paths + "F" + std::to_string(page.file_id) + ".bdda";
        //opens the file in binary mode
        FILE* output_file;
        char* path = f_path.data();
        output_file = fopen(path,"rb");
        fseek(output_file, page.id * main_db.page_size,SEEK_SET);
        fread(buffer, sizeof(char), main_db.page_size , output_file);
        fclose(output_file);
        std::cout << std::endl;
    }
}

void write_page(page_id page,  char* buffer){
    //checks if the page asked for respect the max number of pages available
    std::cout << std::endl;
    if (page.id >= main_db.max_pages_per_file) {
        err_message(4);
    } else {
        //sets the path
        std::string f_path = main_db.db_paths + "F" + std::to_string(page.file_id) + ".bdda";
        //opens the file in binary mode
        FILE* output_file;
        char* path = f_path.data();
        output_file = fopen(path,"w+b");
        fseek(output_file, page.id * main_db.page_size,SEEK_SET);
        fwrite(buffer, sizeof(char), main_db.page_size ,output_file);
        fclose(output_file);
    }
}

//note that this function merely gets the list of pages, not the list of pages where it is possible to write
//in order to write into a page, the programme will use the get_available_page_list() function
std::vector<page_id> get_page_list(){
    std::vector<page_id> page_list;
    for (auto f : file_list){
        for (int i = 0; i<main_db.max_pages_per_file; ++i){
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
std::vector<page_id> get_available_page_list(){
    std::vector<page_id> page_list;
    for (auto f : file_list){
        for (int i = 0; i<main_db.max_pages_per_file; ++i){
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
void init_pages(){
    a_p_list = get_available_page_list( );
    p_list = get_page_list();
}

int get_current_count_alloc_pages(){
    //f_list.size()*4 gives the total number of pages (alloc or not)
    //a_p_list.size() give the total number of non alloc pages
    //thus we have the number of allocated pages without computing anything more complex (such as iterating over the lists)
    return file_list.size()*main_db.max_pages_per_file-a_p_list.size();
}