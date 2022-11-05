//
// Created by Hugo Demaret on 25/09/2022.
//

#ifndef PROJET_BDDA_DEMARET_FILE_H
#define PROJET_BDDA_DEMARET_FILE_H



typedef struct file{
    uint16_t id; //the path to the file (the id that gets concatenated)
    uint8_t nb_occupied; //keeps the number of pages occupied, if it is 4 then no need to load it
    bool page_occupied[4]; //if page_occupied[k] is true, then page is occupied (otherwise it isn't)
    //uint32_t size; //the size of the file
}file;

#endif //PROJET_BDDA_DEMARET_FILE_H
