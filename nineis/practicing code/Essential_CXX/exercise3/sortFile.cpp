/*
 * @Author: nineis
 * @Date: 2022-03-15 14:28:17
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 14:43:13
 * @FilePath: \practicing code\Essential_CXX\exercise3\sortFile.cpp
 * @Description: practice 3.2
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream infile("sortfile.txt", ios_base::in | ios_base::app);

    //alert dimission
    //...

    istream_iterator<string> is(infile);
    istream_iterator<string> eof;

    vector<string> test;
    copy(is, eof, back_inserter(test));

    //自己定义function object 要等第四章 wait...

}