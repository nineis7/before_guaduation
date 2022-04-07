/*
 * @Author: nineis
 * @Date: 2022-03-16 09:43:54
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-16 10:45:56
 * @FilePath: \practicing code\Essential_CXX\exercise4\Stack.h
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 *         const nested : 
 *      当function为const function时，其内部调用的所有function均需要为const function
 */

#pragma once
#ifndef _MYSTACK_
#define _MYSTACK_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Stack;

class Stack{
private:
    vector<string> _stack;

public:
    bool push(string const& );
    bool pop(string & );
    bool peek(string &) const;
    bool find(string const& ) const;
    int count(string const& ) const;

    bool empty() const { return _stack.empty(); }
    bool full() const { return _stack.size() == _stack.max_size(); }

    int size() const { return _stack.size(); }
};

#endif