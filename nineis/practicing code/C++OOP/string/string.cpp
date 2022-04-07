/*
 * @Author: nineis
 * @Date: 2022-03-04 17:54:28
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-04 19:56:11
 * @FilePath: \C++OOP\string\string.cpp
 * @Description: test main
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */
#include <iostream>
#include "string.hpp"

using namespace std;

int main(){
    String s1;
    String s2("hello");
    String s3(s2); //equal to [String s3 = s2] 因为是新生成
    s1 = s3;
    cout << s1.get_c_str() << endl;
    cout << s2.get_c_str() << endl;
    cout << s3.get_c_str() << endl;
}