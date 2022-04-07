/*
 * @Author: nineis
 * @Date: 2022-03-14 14:59:55
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 15:22:35
 * @FilePath: \practicing code\DS\vector\myVector.cpp
 * @Description: definition of class Vector(aborted)
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 *          模板类定义不能放在cpp中
 */

#include "myVector.h"
#include <iostream>
using namespace std;

template<typename T> void
Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
    //if(lo > hi || lo < 0 || hi)
    _elem = new T[_capacity = 2 * (hi -lo)]; _size = 0;
    while(lo < hi) _elem[_size++] = A[lo++];

    cout << "Construction success!" << endl;
}

template<typename T> Vector<T> &
Vector<T>::operator= (Vector<T> const& V)
{
    if(!_elem) delete []_elem;
    if(_elem == &V) return *this;
    
    copyFrom(V, 0, V.size());

    return *this;
}