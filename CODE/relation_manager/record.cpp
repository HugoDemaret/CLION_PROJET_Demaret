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

void write_to_buffer(char* buffer, u_int32_t pos, record rec){

}