//
// Created by Hugo Demaret on 21/11/2022.
//

#ifndef PROJET_BDDA_DEMARET_RECORD_H
#define PROJET_BDDA_DEMARET_RECORD_H

#include "relation_info.h"

typedef struct record{
    relation rel_info;
    char** values;
}record;

#endif //PROJET_BDDA_DEMARET_RECORD_HH