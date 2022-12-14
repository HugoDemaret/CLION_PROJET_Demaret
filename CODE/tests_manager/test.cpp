//
// Created by Hugo Demaret on 26/11/2022.
//

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

#define TESTNBPAGE 4

void test_disk_manager(){

    char buffer[PAGE_SIZE];
    for (int i = 0; i<main_db.page_size; ++i){
        if (i%2)
            buffer[i] = 'a';
        else buffer[i] = 'b';
    }

    page_id pages[TESTNBPAGE];
    for (int i = 0; i<TESTNBPAGE; ++i){
        pages[i] = alloc_page();
        printf("Taille alloc : %d\n", a_p_list.size());
        printf("%d,%d\n",pages[i].file_id,pages[i].id);
        write_page(pages[i], buffer);
    }



    /*
    char buff[PAGE_SIZE];
    for (int i = 0; i<TESTNBPAGE; ++i){
        printf("\nPAGE I : %d     ::   ",TESTNBPAGE-i-1);
        read_page(pages[i],buff);
        for (int j = 0; j<PAGE_SIZE; ++j){
            printf("%c",buff[j]);
        }
    }

    for (int i = 0; i<TESTNBPAGE;++i){
        dealloc_page(pages[i]);
    }

    char buff2[PAGE_SIZE];
    for (int i = 0; i<main_db.page_size; ++i){
        if (i%2)
            buff2[i] = 'E';
        else buff2[i] = 'D';
    }
    for (int i = TESTNBPAGE; i>0; i=i/2){
        pages[i] = alloc_page();
        write_page(pages[i],buff2);
    }



    /*
    char buff[PAGE_SIZE];
    for (int i = 0; i<main_db.page_size; ++i){
        if (i%2)
            buff[i] = 'D';
        else buff[i] = 'E';
    }
    for (int i = 0; i<TESTNBPAGE; ++i){
        write_page(pages[i], buffer);
    }
*/

    //save_file_list();

    /*
    printf("%d,%d",pages[5].file_id,pages[3].id);
    write_page(pages[3],buff);


    /*
    page_id page;
    page = alloc_page();
    char* buffer = NULL;
    char* rbuffer = NULL;
    buffer = (char*)calloc(main_db.page_size,sizeof(char));
    rbuffer = (char*)calloc(main_db.page_size,sizeof(char));

    for(int i = 0; i<main_db.page_size;++i){
        buffer[i] = 'c';
    }

    write_page(page,buffer);
    read_page(page,rbuffer);

    for (int i = 0; i<main_db.page_size; ++i){
        printf("%c",rbuffer[i]);
    }

    dealloc_page(page);
    page = alloc_page();
    for(int i = 0; i<main_db.page_size;++i){
        buffer[i] = 'a';
    }
    write_page(page,buffer);
    std::cout << page.file_id << " and " << page.id << std::endl;
    */


    /*
    clock_t start_time = clock();
    page_id page;
    page = alloc_page();
    char* rbuffer=NULL;
    char* buffer=NULL;

    printf("HERE");

    rbuffer = (char*)calloc(main_db.page_size,sizeof(char));
    buffer = (char*)calloc(main_db.page_size,sizeof(char));

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

    free(buffer);
    free(rbuffer);
    */
}


void test_buffer_manager(){
    //page_id page;
    page_id pages[TESTNBPAGE];
    //page = alloc_page();
    for (int i = 0; i<TESTNBPAGE; ++i){
        pages[i] = alloc_page();
    }

    char* buffer = get_page(pages[0]);
    for (int i = 0; i<main_db.page_size;++i){
        buffer[i] = 'a';
    }
    for (int i = 0; i<main_db.page_size;++i){
        printf("%c",buffer[i]);
    }
    //write_page(pages[0],buffer);



    free_page(pages[0],true);

    flush_all();
    buffer = get_page(pages[1]);
    for (int i = 0; i<main_db.page_size;++i){
        buffer[i]= '4';
    }
    free_page(pages[1],true);

    flush_all();

    char* buffer0 = get_page(pages[2]);
    for (int i = 0; i<main_db.page_size; ++i){
        printf("%c",buffer0[i]);
    }

    free_page(pages[2],false);

    //flush_all();


    //flush_all();
    //printf("Here");

    /*
    for (int i = 0; i<TESTNBPAGE;++i){
        //printf("Here2");
        char* buffer = get_page(pages[i]);
        //printf("Here3");
        for (int j = 0; i<main_db.page_size; ++i){
            buffer[j] = 'a';
        }
    }
    for (int i = 0; i<TESTNBPAGE; ++i){
        free_page(pages[i],true);
    }
    //printf("HERE");
    flush_all();
/*
    {
        char* buffer = get_page(page);
        for (int i = 0; i<main_db.page_size; ++i){
            printf("%c",buffer[i]);
        }
        printf("\nEND\n");
        free_page(page, false);
        flush_all();
    }

    {
        char *buffer = get_page(page);

        for (int i = 0; i < main_db.page_size; ++i) {
            buffer[i] = 'b';
        }

        for (int i = 0; i<main_db.page_size;++i){
            printf("%c",buffer[i]);
        }
        free_page(page, true);

        flush_all();
        printf("End\n");
    }

    {
        char* buffer = get_page(page);
        for (int i = 0; i<main_db.page_size; ++i){
            printf("%c",buffer[i]);
        }
        printf("\nEND\n");
        free_page(page, false);
        flush_all();
    }
*/


}