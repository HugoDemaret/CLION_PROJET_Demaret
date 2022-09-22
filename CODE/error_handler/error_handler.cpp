//
// Created by Hugo Demaret on 22/09/2022.
//

#include <iostream>
#include "error.h"

void err_message(int8_t err_code){
    switch (err_code) {
        case -1:
            std::cout << "Error : " << err_code << " Unexpected Event..." << std::endl;
            break;
        case 0:
            if (DEBUG == 1){
                std::cout << "Debug mode : " << err_code << " Command worked properly!" << std::endl;
            }
            break;
        case 1:
            std::cout << "Error : " << err_code << " DataBase directory could not be found!" << std::endl;
            break;
        case 2:
            std::cout << "Error : " << err_code << " File could not be found!" << std::endl;
            break;
        case 3:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        case 4:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        default:
            std::cout << "Error : " << err_code << " Unknown Error Code" << std::endl;
            break;
    }
}

