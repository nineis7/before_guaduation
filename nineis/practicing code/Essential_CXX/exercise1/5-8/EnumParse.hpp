/*
 * @Author: nineis
 * @Date: 2022-03-09 18:32:47
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-09 18:32:48
 * @FilePath: \practicing code\Essential_CXX\exercise1\5-8\EnumParse.hpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#pragma once
#ifndef _ENUMPARSE_
#define _ENUMPARSE_

#include <string>
#include <map>

using namespace std;

template <typename T> class EnumParser
{
    map<string, T> enumMap;
public:
    EnumParser(){};

    T ParseSomeEnum(const string &value)
    { 
        typename map <string, T>::const_iterator iValue = enumMap.find(value);
        if (iValue  == enumMap.end())
            throw runtime_error("");
        return iValue->second;
    }
};

#endif