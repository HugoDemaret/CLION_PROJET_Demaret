#include <iostream>
#include "interpreter/functions.h"
#include "db_params.h"

#define PAGE_SIZE 4096
#define DB_PATH "../DB/"
#define MAX_PAGES_PER_FILE 4

//CREATES NEW DATABASE "main_db"
db_params main_db;



int main(void){
    //sets the parameters
    main_db.db_paths = DB_PATH;
    main_db.page_size = PAGE_SIZE;
    main_db.max_pages_per_file = MAX_PAGES_PER_FILE;
    //

    std::cout << "DBMS" << std::endl;
    shell_runner();
    return 0;
}