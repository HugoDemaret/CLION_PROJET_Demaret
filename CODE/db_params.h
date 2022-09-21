//
// Created by hugodemaret on 21/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_DB_PARAMS_H
#define PROJET_BDDA_DEMARET_DB_PARAMS_H

typedef struct db_params{
    std::string db_paths;
    int page_size;
    int max_pages_per_file;
}db_params;

#endif //PROJET_BDDA_DEMARET_DB_PARAMS_H
