//
// Created by hugodemaret on 21/09/2022.
//
#include <iostream>
#include <string>

void shell_runner(void){
    bool quit = true;
    while (quit) {
        quit = shell_waiter();
    }
}


bool shell_waiter(void){
    std::cout << "Please enter a command : " << std::endl;
    bool state = true;
    std::string command_string;
    //todo : parse string into vector of string

    if (command.lower == "quit"){
        state = !state;
    } else {
        //todo give command to interpreter
    }
    return state;
}
