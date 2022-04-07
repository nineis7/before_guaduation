/*
 * @Author: nineis
 * @Date: 2022-03-15 14:58:03
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-16 09:15:54
 * @FilePath: \practicing code\Essential_CXX\exercise3\integerFile.cpp
 * @Description: practice 3.4
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //ifstream infile("numFile.txt", ios_base::in | ios_base::app);
    ofstream outfile_odd("outputNumFile_odd.txt", ios_base::app);
    ofstream outfile_even("outputNumFile_even.txt", ios_base::app);

    istream_iterator<int> is(cin);
    istream_iterator<int> eof;  //结束时在命令行中输入eof即可
    vector<int> vec_inte_cur;
    vector<int> vec_inte_odd;
    vector<int> vec_inte_even;
    

    copy(is, eof, back_inserter(vec_inte_cur));

    for(auto i : vec_inte_cur){
        if(i%2) vec_inte_odd.push_back(i);
        else vec_inte_even.push_back(i);
    }

    ostream_iterator<int> os_odd(outfile_odd, " ");
    ostream_iterator<int> os_even(outfile_even, "\n");

    copy(vec_inte_odd.begin(), vec_inte_odd.end(), os_odd);
    copy(vec_inte_even.begin(), vec_inte_even.end(), os_even);

}