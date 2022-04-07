/*
 * @Author: nineis
 * @Date: 2022-03-15 14:06:36
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 14:27:43
 * @FilePath: \practicing code\Essential_CXX\exercise3\readFile.cpp
 * @Description: read file into map and choose certain words from sets to separate from it.
 *              practice 3.1
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

int main(){
    fstream iofile("infile.txt", ios_base::in | ios_base::app);
    map<string, int> usr_map;
    string cur_word;
    set<string> word_exclusion{"a", "an", "but", "some", "and", "or", "the" };

    while(iofile >> cur_word){
        if(word_exclusion.count(cur_word)) continue;

        usr_map[cur_word]++;
    }

    //user inquires certain words
    cout << " enter the word you want to inquire: ";
    string usr_word; cin >> usr_word;
    if(usr_map.count(usr_word)) 
        cout << "Yes it actually exists and it occurs for " 
                << usr_map[usr_word] << " times." << endl;
    else
        cout << "Sry but it doesn't exist." << endl;            

    cout << "********Here is the map list after exlusiving certain words *********** " << endl;
    for(auto i : usr_map) cout << i.first << " occurs " << i.second << " times." << endl;
}