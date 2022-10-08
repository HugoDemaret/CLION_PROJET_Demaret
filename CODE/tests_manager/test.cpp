//
// Created by Hugo Demaret on 29/09/2022.
//
#include <iostream>
#include <time.h>
#include <vector>
#include "../db_params.h"
#include "../disk_manager/page_id.h"
#include "../disk_manager/disk_manager.h"
#include "../disk_manager/file.h"
#include "../disk_manager/filelist.h"
#include "test.h"
#include "../global.h"

#define TESTNBPAGE 10

void test_disk_manager(){
    clock_t start_time = clock();
    page_id page;
    page = alloc_page();
    char rbuffer[main_db.page_size];
    char buffer[main_db.page_size];


    page_id pages[TESTNBPAGE];
    for (int i  = 0 ; i<TESTNBPAGE ; ++i){
        pages[i] = alloc_page();
    }




    for (int i = 0; i<main_db.page_size; ++i){
        buffer[i] = 97;

    }

    for (int i = 0; i<TESTNBPAGE; ++i ){
        write_page(pages[i], buffer);
    }

    write_page(page, buffer);



    read_page(page,rbuffer);


    for (int i; i<main_db.page_size; ++i){
        std::cout << rbuffer[i] <<" GOES BRRR "<< std::endl;
    }

    dealloc_page(page);

    page = alloc_page();
    for (int i; i<main_db.page_size; ++i){
        buffer[i] = 108;
    }

    write_page(page, buffer);



    read_page(page,rbuffer);

    for (int i; i<main_db.page_size; ++i){
        std::cout << rbuffer[i] <<" GOES BRRR "<< std::endl;
    }
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Done in %f seconds\n", elapsed_time);
}