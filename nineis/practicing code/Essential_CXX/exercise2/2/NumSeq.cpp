/*
 * @Author: nineis
 * @Date: 2022-03-13 13:35:51
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-13 14:09:58
 * @FilePath: \practicing code\Essential_CXX\exercise2\2\NumSeq.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "NumSeq.h"
bool createSeq(const int size, vector<int>& usr_vec)
{
    if(!is_ok(size)){
        cerr << "Size wrong! " << endl; return false;
    }

    for(int i = usr_vec.size(); i < size; i++){
        int elem = ((i+1) * ((i+1)*3 -1)) / 2;
        usr_vec.push_back(elem);
    }

    return true;
}

void displaySeq(const vector<int>& usr_vec)
{
    cout << "The pentagonal sequence is : ";
    for(auto i : usr_vec) cout << i << " ";
    cout << endl;
}

const vector<int>* createSeq(const int size)
{
    if(!is_ok(size)) { cerr << " gc " << endl; return 0; }

    static vector<int> sta_vec;

    for(int i = sta_vec.size(); i < size; i++){
        int elem = ((i+1) * ((i+1)*3 -1)) / 2;
        sta_vec.push_back(elem);
    }

    return &sta_vec;
}

bool get_elem(const int pos, int& elem, const vector<int>& usr_vec)
{
    if(!is_ok(pos-1)) { cerr << "Wrong position!" << endl; return false; }

    elem = usr_vec[pos-1];

    return true;
}