/*
 * @Author: nineis
 * @Date: 2022-03-14 14:31:04
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 15:21:54
 * @FilePath: \practicing code\DS\vector\myVector.h
 * @Description: the class vector declaration and part of definition.
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 *      1. 模板类的声明和定义必须都放在头文件中；
 */

#pragma once
#ifndef _MYVECTOR_
#define _MYVECTOR_

#include <iostream>
using namespace std;

typedef int Rank;
#define _DEFAULT_CAPACITY 3

template<typename T> class Vector {
private:
    Rank _size; int _capacity; T* _elem;
protected:
    void copyFrom(T const* A, Rank lo, Rank hi);
public:
    Vector(int c = _DEFAULT_CAPACITY, Rank s = 0, T v = 0) //容量为s，所有元素均为v的初始化形式
    { _elem = new T[_capacity = c]; for(_size = 0; _size < s; _elem[_size++] = v); }
    //Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //array assignemnt
    //Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
    Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }
    //Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }
    ~Vector() { delete []_elem; }

    Rank size() const { return _size; }

    Vector<T> & operator= (Vector<T> const& );
};

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
    //这一步编译器可能自动优化了，自己添加了，故没有报错
    if(this == &V) return *this;
    
    cout << "我从别人那里拷贝" << endl;
    copyFrom(V._elem, 0, V.size());

    return *this;
}

#endif