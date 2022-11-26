//
// Created by hugodemaret on 26/11/2022.
//

#include "catalog.h"
#include "../global.h"


void init(void){

}

void finish(void){

}

void add_relation_info(relation rel){
    main_catalog.catalog_list.add(rel);
    main_catalog.nb_relation++;
}

relation get_relation_info(std::string rel_name){
    for (auto rel : main_catalog.catalog_list){
        if (rel.rel_name == rel_name){
            return rel;
        }
    }
    relation rel;
    rel.rel_name = "";
    rel.columns = 0;
    rel.nb_column = 0;
    return rel;
}
