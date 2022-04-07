/*
 * @Author: nineis
 * @Date: 2022-03-17 18:18:25
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-17 18:30:12
 * @FilePath: \practicing code\Essential_CXX\exercise4\test.cpp
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

void print_usr() {} //出口，必须要有

template<typename T, typename... Types>
void print_usr(T const& firstArg, Types const&... args)
{
    cout << firstArg << endl;
    cout << sizeof...(args) << endl;
    print_usr(args...);
}

int main(){
    //cout << __cplusplus << endl;    //201402

    print_usr("what?", 300, "你不对劲", 77.777);
}