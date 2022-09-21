//
// Created by hugodemaret on 21/09/2022.
//

#include <string>
#include <algorithm>


//returns a given string in uppercase
std::string to_upper(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

//returns a given string in lowercase
std::string to_lower(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
