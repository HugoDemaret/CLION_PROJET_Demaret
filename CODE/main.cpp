#include <iostream>
#include <vector>
#include "interpreter/interpreter.h"
#include "disk_manager/db_params.h"
#include "disk_manager/disk_manager.h"
#include "disk_manager/file.h"
#include "disk_manager/page_id.h"
#include "disk_manager/filelist.h"


#define PAGE_SIZE 4096
#define DB_PATH "../DB/"
#define MAX_PAGES_PER_FILE 4


//CREATES NEW DATABASE "main_db"
db_params main_db;
//CREATES NEW FILE LIST "file_list"
std::vector<file> f_list;
std::vector<page_id> a_page_list;
std::vector<page_id> page_list;




int main(int argc, char **argv){
    //sets the parameters of the DB
    main_db.db_paths = DB_PATH;
    main_db.page_size = PAGE_SIZE;
    main_db.max_pages_per_file = MAX_PAGES_PER_FILE;
    //loads the file list
    f_list = get_file_list();
    //initializes the pages (available and not available)
    init_pages(f_list);
    //

    std::cout << "DBMS" << std::endl;
    //starts the shell
    shell_runner();
    return 0;
}
