//
// Created by Hugo Demaret on 21/11/2022.
//

#ifndef PROJET_BDDA_DEMARET_COLUMN_INFO_H
#define PROJET_BDDA_DEMARET_COLUMN_INFO_H

enum coltype {none, INTEGER, REAL, VARCHAR};

typedef struct column{
    std::string column_name;
    uint8_t size;
    enum coltype type;
    union {
        int n;
        float f;
        char* s;
    };
}column;

#endif //PROJET_BDDA_DEMARET_COLUMN_INFO_H
