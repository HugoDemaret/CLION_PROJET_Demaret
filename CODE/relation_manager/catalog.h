//
// Created by Hugo Demaret on 21/11/2022.
//

#ifndef PROJET_BDDA_DEMARET_CATALOG_H
#define PROJET_BDDA_DEMARET_CATALOG_H
#include "../global.h"
#include "column_info.h"
#include "relation_info.h"


typedef struct catalog{
    u_int nb_relation;
    relation *relations;
}catalog;

#endif //PROJET_BDDA_DEMARET_CATALOG_H
