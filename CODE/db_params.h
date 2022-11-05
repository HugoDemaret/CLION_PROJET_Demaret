//
// Created by hugodemaret on 21/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_DB_PARAMS_H
#define PROJET_BDDA_DEMARET_DB_PARAMS_H

#include <string>

typedef struct db_params{
    std::string db_paths;
    u_int16_t page_size; //usually limited to 4096 bytes
    char max_pages_per_file; //limited to 4 (in our case)
    u_int16_t frame_count;
    u_int16_t total_nb_file;
}db_params;


#endif //PROJET_BDDA_DEMARET_DB_PARAMS_H
