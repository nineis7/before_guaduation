/*
 * @Author: nineis
 * @Date: 2022-03-14 10:10:45
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-14 11:00:20
 * @FilePath: \practicing code\Essential_CXX\exercise3\find_iter.cpp
 * @Description: find function appling for iterator
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 *  需要完成的事： 毕设开题报告、复试英语问题总结、                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 *               过去的课题项目经历回顾(多维背包边缘计算问题，汇编，计算器apk)
 *  只需放心飞的事：C++，AI与统计学，毕设，数据结构C++
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

template<typename IteratorType, typename elemType >
IteratorType usr_find(IteratorType first, IteratorType last, const elemType& value)
{
    for(; first != last; ++first) if( *first == value) return first;

    return last;
}

int main(){
    int usr_arr[] = {1,2,3,4,5,6,8};


    //array implementation
    int* int_ptr = usr_find(usr_arr, usr_arr+ 7, 8);
    if(int_ptr != (usr_arr+7) ) cout << "find it! " << *int_ptr << endl;

    //iter & vec implementation
    vector<int> usr_vec{1,2,3,4,5,6,7};
    vector<int>::iterator iter_vec = usr_vec.begin();
    vector<int>::iterator iter_last = usr_vec.end();
    vector<int>::iterator usr_iter = usr_find(iter_vec, iter_last, 5);
    if(usr_iter != usr_vec.end() ) cout << "find it! iter " << *usr_iter << endl; 

}