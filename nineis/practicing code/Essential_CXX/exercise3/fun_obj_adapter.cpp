/*
 * @Author: nineis
 * @Date: 2022-03-15 09:39:40
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 09:59:41
 * @FilePath: \practicing code\Essential_CXX\exercise3\fun_obj_adapter.cpp
 * @Description: function object adapter practice
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

template<typename InputIterator, typename OutputIterator,
            typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
        OutputIterator at, ElemType const& value, Comp pred)
{
    while( (first = find_if(first, last, bind2nd(pred, value))) != last){
        cout << "found value " << *first << endl;

        //*at++ = *first++;

        *at = *first; //先传值
        //再同时后移
        at++;
        first++;
    }

    return at;
}

int main(){
    const int elem_size = 8;
    int arr[elem_size] = {12,8,43,0,7,24,5,15};
    vector<int> vec(arr, arr + elem_size);

    //存储容器
    int arr_s[elem_size];
    vector<int> vec_s(elem_size);

    cout << "filtering integer array for values less than 8 : " << endl;
    filter(arr, arr + elem_size, arr_s, elem_size, less<int>());

    cout << "filtering integer vector fot values greater than 8 : " << endl;
    filter(vec.begin(), vec.end(), vec_s.begin(), elem_size, greater<int>());
}