/*
 * @Author: nineis
 * @Date: 2022-03-24 17:10:36
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-24 17:17:40
 * @FilePath: \practicing code\Essential_CXX\exercise4\cpp.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class human
{
public:
    ~human() { cout << "human die..." << endl; }
    void disp() { cout << "human disp..." << endl; }
};

class man: public human
{
public:
    ~man() { cout << "man die..." << endl; }
    void disp() { cout << "man disp..." << endl; }
};

int main(){
    // int i(5), b(7);
    // cout << (i+++b) << endl;
    // cout << i << endl;
    human *p = new man;
    p->disp();
    delete p;
    return 0;
}


// ******************** results *************
// 当并非虚函数时，调用的均是父类的成员函数
// human disp...
// human die...