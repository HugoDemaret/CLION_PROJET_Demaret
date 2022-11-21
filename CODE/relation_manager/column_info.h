//
// Created by Hugo Demaret on 21/11/2022.
//

#ifndef PROJET_BDDA_DEMARET_COLUMN_INFO_H
#define PROJET_BDDA_DEMARET_COLUMN_INFO_H

typedef struct column{
    std::string column_name;
    union column_type {
        char* type = {"INTEGER", "REAL" ,"VARCHAR(T)"};
    };
}column;

#endif //PROJET_BDDA_DEMARET_COLUMN_INFO_H
