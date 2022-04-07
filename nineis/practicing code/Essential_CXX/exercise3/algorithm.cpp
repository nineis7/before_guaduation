/*
 * @Author: nineis
 * @Date: 2022-03-14 11:12:05
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-14 11:21:19
 * @FilePath: \practicing code\Essential_CXX\exercise3\algorithm.cpp
 * @Description: test genetic algorithms
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool is_elem(const vector<int>& vec, const int elem)
{
    vector<int> vec_tmp(vec.size());
    copy(vec.begin(), vec.end(), vec_tmp.begin());

    sort(vec_tmp.begin(), vec_tmp.end());

    return binary_search(vec_tmp.begin(), vec_tmp.end(), elem);

}

int main(){
    vector<int> vec{1,2,3,4,5,10,121,8,9};

    if(is_elem(vec, 5)) cout << "Yes it exists." << endl;
    else cout << "defeat..." << endl; 
}