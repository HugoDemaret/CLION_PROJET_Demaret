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
        //from 1 to 9 : problem or finding data (directory, file...)
        case 1:
            std::cout << "Error : " << err_code << " DataBase directory could not be found!" << std::endl;
            break;
        case 2:
            std::cout << "Error : " << err_code << " File could not be found!" << std::endl;
            break;
        case 3:
            std::cout << "Error : " << err_code << " Page not found ! (Maybe the page you tried to access is > 4 ?)" << std::endl;
            break;
        case 4:
            std::cout << "Error : " << err_code << " File already exists!" << std::endl;
            break;
        //from 10 to 19 : error with saving procedure (no file, path not found etc)
        //From 20 to 29 : error with disk manager
        case 20:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        case 21:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        case 22:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        case 23:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        case 24:
            std::cout << "Error : " << err_code << " To be attributed" << std::endl;
            break;
        //from 30 to 39 : error with buffer manager
        default:
            std::cout << "Error : " << err_code << " Unknown Error Code" << std::endl;
            break;
    }
}

