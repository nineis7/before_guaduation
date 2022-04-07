/*
 * @Author: nineis
 * @Date: 2022-03-12 15:30:11
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-12 15:49:33
 * @FilePath: \practicing code\Essential_CXX\exercise2\1\fun.cpp
 * @Description: function set
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#include "fun.hpp"

bool get_fibon_elem(const size_t pos, size_t& elem)
{
    if( pos<0 || pos>1024)
    {
        elem = 0; return false;
    }

    elem = 1;
    size_t num_1(1), num_2(1);

    for(size_t index(2); index < pos; index++)
    {
        elem = num_1 + num_2;
        num_1 = num_2; num_2 = elem;
    }

    return true;
}