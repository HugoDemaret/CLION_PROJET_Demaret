//
// Created by Hugo Demaret on 21/11/2022.
//

#ifndef PROJET_BDDA_DEMARET_RELATION_INFO_H
#define PROJET_BDDA_DEMARET_RELATION_INFO_H
#include "../global.h"
#include "column_info.h"

typedef struct relation{
    std::string rel_name;
    u_int nb_column;
    column *columns;
}relation;

#endif //PROJET_BDDA_DEMARET_RELATION_INFO_H
