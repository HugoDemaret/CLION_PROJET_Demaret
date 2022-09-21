//
// Created by hugodemaret on 21/09/2022.
//

#include <string>
#include <algorithm>


//returns a given string in uppercase
std::string to_upper(std::string str){
    return std::transform(str.begin(), str.end(), str.begin, ::toupper);
}

//returns a given string in lowercase
std::string to_lower(std::string str){
    return std::transform(str.begin(), str.end(), str.begin, ::tolower);
}
