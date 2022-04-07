/*
 * @Author: nineis
 * @Date: 2022-03-14 09:21:52
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-14 09:53:36
 * @FilePath: \practicing code\Essential_CXX\exercise3\find.cpp
 * @Description: find function implement using 标兵
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename elemType>
const elemType* usr_find(const elemType* first, const elemType* last, const elemType& value)
{
    if(!first || !last) return 0;

    //const elemType* first 表示该指针所指向的值为const，而指针是可以改变的。
    for(; first != last; ++first) if(*first == value) return first;

    return 0;
}

template<typename elemType>
inline const elemType* usr_begin(const vector<elemType>& vec) { return vec.empty() ? 0 : &vec[0]; }

template<typename elemType>
inline const elemType* usr_end(const vector<elemType>& vec) { return vec.empty() ? 0 : &vec[vec.size()]; }

int main(){
    vector<int> usr_vec{1, 2, 3, 7, 12};
    int value(6);
    //注意这里一定都要在函数前加上usr_来与stl中的genetic function区别开，不然会报错。
    const int* vec_ptr = usr_find(usr_begin(usr_vec), usr_end(usr_vec), value);

    if(vec_ptr) cout << "The value exists and it is " << (*vec_ptr) << endl;
    else cerr << "There is no such value! " << endl;
}