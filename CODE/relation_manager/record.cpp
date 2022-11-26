//
// Created by hugodemaret on 26/11/2022.
//

#include "record.h"
#include "../global.h"



record new_record(relation rel){
    record rec;
    rec.rel_info = rel;
    rec.values = NULL;
    return rec;
}

void write_to_buffer(char* buffer, u_int32_t pos, record* rec){
    buffer+= pos;
    char **ptr = rec->values;
    column *col = rec->rel_info.columns;
    for (int i=0; i<rec->rel_info.nb_column; ++i){
        if (col[i].type == INTEGER) {
            write_int_to_buffer(*(int*) ptr, buffer);
            ptr+=4;
            buffer+=4;
        } else if (col[i].type == REAL){
            write_float_to_buffer(*(float*) ptr, buffer);
            ptr+=4;
            buffer+=4;
        } else if (col[i].type == VARCHAR){
            memmove(buffer, ptr, col[i].size);
            ptr+= (col[i].size + (4-col[i].size%4));
            buffer+= (col[i].size + (4-col[i].size%4));
        } else {
            exit(EXIT_FAILURE);
        }
    }
}

void read_from_buffer(char* buffer, u_int32_t pos, record* rec){
    buffer+= pos;
    char **ptr = rec->values;
    column *col = rec->rel_info.columns;
    for (int i=0; i<rec->rel_info.nb_column; ++i){
        if (col[i].type == INTEGER) {
            read_int_from_buffer(buffer);
            ptr+=4;
            buffer+=4;
        } else if (col[i].type == REAL){
            read_float_from_buffer(buffer);
            ptr+=4;
            buffer+=4;
        } else if (col[i].type == VARCHAR){
            memmove(buffer, ptr, col[i].size);
            ((char*)ptr)[col[i].size] = '\0';
            ptr+= (col[i].size + (4-col[i].size%4));
            buffer+= (col[i].size + (4-col[i].size%4));
        } else {
            exit(EXIT_FAILURE);
        }
    }
}

int get_written_size(){

}