//
// Created by hugodemaret on 21/09/2022.
//
#include <iostream>
#include <string>
#include <vector>
#include "../string_converter/case_modifier.cpp"
#include "../string_converter/split.cpp"
#include "functions.h"

void shell_runner(void){
    bool quit = true;
    while (quit) {
        quit = shell_waiter();
    }
}


bool shell_waiter(void){
    std::cout << "Please enter a command : " << std::endl;

    //sets the return variable to true, will be changed if needed during runtime
    bool state = true;

    //defining the command (containing the command in one string) and command vector (containing the command splitted into different strings)
    std::string command;
    std::vector<std::string> command_vec;
    //reading the command from stdin
    getline(std::cin, command);
    //splitting the command into the vector
    command_vec = split(command, " ");



    if (to_lower(command_vec[0]) == "quit"){
        state = !state;
    } else {
        //todo give command to interpreter
    }
    return state;
}
