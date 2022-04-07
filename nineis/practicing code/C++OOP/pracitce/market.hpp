/*
 * @Author: nineis
 * @Date: 2022-03-07 14:39:52
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-07 15:14:00
 * @FilePath: \C++OOP\pracitce\market.hpp
 * @Description: exercise for inheritance and componence
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#pragma once
#ifndef _MYMARKET_
#define _MYMARKET_

#include <iostream>
using namespace std;

class market
{
private:
    /* data */
public:
    market(/* args */) { cout << "market::market() contructor invokes." << endl; }
    ~market() { cout << "market::~market() decontructor invokes." << endl; }
};

class fruit
{
private:
    /* data */
public:
    fruit() { cout << "fruit::fruit contructor invokes." << endl; }
    ~fruit() { cout << "fruit::~fruit() deconstructor invokes." << endl; }
};

class basket: public market
{
private:
    /* data */
    fruit fru;
    int count;
public:
    basket() { cout << "basket::basket() constructor invokes." << endl; }
    ~basket() { cout << "basket::~basket() deconstructor invokes." << endl; }
    Asssemble()
};

#endif