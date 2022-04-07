/*
 * @Author: nineis
 * @Date: 2022-03-16 09:24:04
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-16 09:25:10
 * @FilePath: \practicing code\Essential_CXX\exercise4\class_test.cpp
 * @Description: test for class froward declaration
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Stack{
private:
    size_t size;
};

void testFunction(Stack const& );

int main(){
    cout << "*****testing****" << endl;
}