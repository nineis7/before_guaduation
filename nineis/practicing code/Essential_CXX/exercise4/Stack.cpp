/*
 * @Author: nineis
 * @Date: 2022-03-16 09:37:17
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-16 10:43:13
 * @FilePath: \practicing code\Essential_CXX\exercise4\Stack.cpp
 * @Description: part of definition of class Stack
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "Stack.h"

bool
Stack::push(string const& elem)
{
    if(!full()){
        this->_stack.push_back(elem);
        return true;
    }
    else{
        cerr << " space full!" << endl;
        return false;
    }
}

bool
Stack::pop(string & elem)
{
    if(!empty()){
        elem = this->_stack[_stack.size() - 1];
        this->_stack.pop_back();
        return true;
    }
    else{
        cerr << "space empty!" << endl;
        return false;
    }
}

bool
Stack::peek(string & elem) const
{
    if(!empty()){
        elem = this->_stack[_stack.size() - 1];
        return true;
    }
    else{
        cerr << "space empty!" << endl;
        return false;
    }
}

bool
Stack::find(string const& word) const
{
    for(auto i : _stack) if(i == word) return true;

    return false;
}

int
Stack::count(string const& word) const
{
    int countNum(0);
    for(auto i: _stack) if(i == word) ++countNum;

    return countNum;
}