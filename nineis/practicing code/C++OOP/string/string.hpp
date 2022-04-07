/*
 * @Author: nineis
 * @Date: 2022-03-04 17:16:35
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-04 20:06:18
 * @FilePath: \C++OOP\string\string.hpp
 * @Description: string.hpp : the declaration of class hpp
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * 
 * Notes:
 * class with pointer members must have copy ctor and copy op=
 */


#pragma once
#ifndef _MYSTRING_HPP
#define _MYSTRING_HPP

class String;


class String
{
private:
    /* data */
    char* m_data;

public:
    String(const char* cstr = 0); //deep copy instead of soft copy
    String(const String& str);
    String& operator= (const String& str);
    ~String();
    char* get_c_str() const { return m_data;}
};

#include <cstring>

inline
String::String(const char* cstr){
    if(cstr){
        this->m_data = new char[strlen(cstr) + 1];
        strcpy(this->m_data, cstr);
    }
    else{
        this->m_data = new char[1];
        this->m_data[0] = '\0';
    }
}

inline
String::~String(){
    delete[] m_data;
}

inline
String::String(const String& str){
    this->m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
}

inline String&
String::operator= (const String& str){

    //self-assignment
    if(this == &str) return *this;

    delete[] this->m_data;
    this->m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
    return *this;
}

#endif
