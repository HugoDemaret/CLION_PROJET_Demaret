//
// Created by Hugo Demaret on 06/10/2022.
//

#ifndef PROJET_BDDA_DEMARET_FRAME_H
#define PROJET_BDDA_DEMARET_FRAME_H
#include "../global.h"

typedef struct frame{
    u_int8_t pin_count;
    bool dirt;
    char *buffer;
    page_id page;
}frame;

#endif //PROJET_BDDA_DEMARET_FRAME_H
