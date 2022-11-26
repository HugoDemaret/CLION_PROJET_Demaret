#include <iostream>
#include <vector>
#include "interpreter/interpreter.h"
#include "db_params.h"
#include "disk_manager/disk_manager.h"
#include "disk_manager/file.h"
#include "disk_manager/page_id.h"
#include "disk_manager/filelist.h"
#include "tests_manager/test.h"
#include "global.h"





//CREATES NEW DATABASE "main_db"
db_params main_db;
//CREATES NEW FILE LIST "f_list"
std::vector<file> file_list;
//CREATES THE CATALOG
catalog main_catalog;



int main(int argc, char **argv){
    //sets the parameters of the DB
    main_db.db_paths = DB_PATH;
    main_db.page_size = PAGE_SIZE;
    main_db.max_pages_per_file = MAX_PAGES_PER_FILE;
    main_db.frame_count = MAX_FRAME_COUNT;
    printf("DEBUG");
    main_db.total_nb_file = get_nb_file();
    //loads the file list
    file_list = get_file_list();
    init_frames();
    //initializes the pages (available and not available)
    init_pages();
    //
    if (DEBUG){
        //test_disk_manager();
        test_buffer_manager();
    }
    std::cout << "DBMS" << std::endl;
    //starts the shell
    shell_runner();
    save_file_list();
    save_nb_file();
    free_frames();
    return 0;
}
