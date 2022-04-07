/*
 * @Author: nineis
 * @Date: 2022-03-13 14:55:11
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-13 15:00:16
 * @FilePath: \practicing code\Essential_CXX\exercise2\2\testfor.cpp
 * @Description: 测试范围for
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#include <iostream>
using namespace std;

template<typename elemType>
void test(elemType arr[])
{
    for(auto i : arr) cout << " suc" << endl;
}

int main(){
    int arr[]{1,2,3,4,5,6,7};
    for(auto i: arr) cout<<"thx"<< endl;
    test(arr); //error
}
