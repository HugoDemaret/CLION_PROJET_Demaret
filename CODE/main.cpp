#include <iostream>
#include <vector>
#include "interpreter/functions.h"
#include "disk_manager/db_params.h"
#include "disk_manager/functions.h"
#include "disk_manager/file.h"
#include "disk_manager/page_id.h"
#include "disk_manager/filelist.h"


#define PAGE_SIZE 4096
#define DB_PATH "../DB/"
#define MAX_PAGES_PER_FILE 4


//CREATES NEW DATABASE "main_db"
db_params main_db;
//CREATES NEW FILE LIST "file_list"
std::vector<file> file_list;




int main(int argc, char **argv){
    //sets the parameters of the DB
    main_db.db_paths = DB_PATH;
    main_db.page_size = PAGE_SIZE;
    main_db.max_pages_per_file = MAX_PAGES_PER_FILE;
    //loads the file list
    std::vector<file> test = get_file_list();

    std::cout << "DBMS" << std::endl;
    shell_runner();
    return 0;
}