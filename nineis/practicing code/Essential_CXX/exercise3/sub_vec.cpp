/*
 * @Author: nineis
 * @Date: 2022-03-15 10:43:07
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 11:06:32
 * @FilePath: \practicing code\Essential_CXX\exercise3\sub_vec.cpp
 * @Description: practice for sub_vec() template function
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 *  1. typename 用法：typename 必须前置于嵌套依赖类型名
 *  2. 结果最后有乱码，暂未解决
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//并非传引用所以返回值的assignment开销还比较大，如果vec太大的话
template<typename ElemType>
vector<ElemType>
sub_vec(vector<ElemType> const& v, ElemType val)
{
    vector<ElemType> vec(v);
    sort(vec.begin(), vec.end());

    //这里要加typename，但具体原因尚未知晓 ：typename 必须前置于嵌套依赖类型名
    typename vector<ElemType>::iterator iter =
     find_if(vec.begin(), vec.end(), bind2nd(greater<ElemType>(), val));

    vec.erase(iter, vec.end());

    return vec;
}

int main(){
    const int elem_size = 8;
    int arr[elem_size] = {12,8,43,0,7,24,5,15};
    vector<int> vec(arr, arr + elem_size);

    //存储容器
    //int arr_s[elem_size];
    //vector<int> vec_s(elem_size);

    // cout << "sub integer array for values less than 8 : " << endl;
    // sub_vec(arr, arr + elem_size, arr_s, elem_size, less<int>());

    cout << "sub integer vector fot values greater than 8 : " << endl;
    vector<int> vec_s = sub_vec(vec, elem_size);

    for(auto i : vec_s) cout << i << " ";

}