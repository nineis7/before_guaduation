/*
 * @Author: nineis
 * @Date: 2022-03-06 09:32:54
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-06 09:53:17
 * @FilePath: \C++OOP\string2\string.hpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#pragma once
#ifndef _MYSTRING_
#define _MYSTRING_

class String
{
private:
    /* data */
    char* m_data;
public:
    String(const char* cstr = 0);
    String(const String& str);
    String& operator= (const String& str);
    ~String();

    char* get_c_str() const { return m_data;}
};

#include <cstring>
inline
String::String(const char* cstr){
    if(cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        m_data[0] = '\0';
    }
}

inline
String::String(const String& str){
    this->m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
}

inline String&
String::operator=(const String& str){
    //self-assinment testing
    if(this == &str) return *this;

    delete[] this->m_data;
    this->m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
    return *this;
}

inline
String::~String(){
    delete[] m_data;
}


#endif