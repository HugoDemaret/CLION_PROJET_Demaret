//
// Created by hugodemaret on 21/09/2022.
//
#include <vector>
#include <string>

//Code comes from here : https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//this function converts a string to a vector of strings, given a string and a delimiter
//It is equivalent to the "split()" method in python
std::vector<std::string> split(std::string str, std::string delimiter){
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
        token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back(str.substr (pos_start));
    return res;
}