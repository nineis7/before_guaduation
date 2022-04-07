/*
 * @Author: nineis
 * @Date: 2022-03-07 10:18:45
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-07 11:12:15
 * @FilePath: \C++OOP\LibMat\lib.hpp
 * @Description: the declarations and definitions of LibMat and its derived classes.
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#pragma once
#ifndef _MYLIBSYSTEM_
#define _MYLIBSYSTEM_

#include <iostream>
using namespace std;

class LibMat
{
private:
    /* data */
public:
    LibMat() { cout << "hey! I'm the constructor of class LibMat!" << endl;}
    virtual ~LibMat() { cout << "hey! I'm the deconstructor of class LibMat!" << endl;}
    virtual void print() const {  cout << "hey! I'm the print of class LibMat!" << endl;};
};

inline void
print(const LibMat& lm){
    cout << "hey! I'm the print with no classmember!" << endl;
    //cout << "And I'll invoke the mamber print according to the current invoker." << endl;

    lm.print();
}


#include <string>
class Books: public LibMat
{
protected:
    /* data */
    string _author;
    string _title;
public:
    Books(const string& au, const string& ti): _author(au), _title(ti) 
    { cout << "I'm the constructor of class Books!" << endl;}
    virtual ~Books() { cout << "i'm the deconstructor of class Books!" << endl; }
    virtual void print() const;
};

inline void
Books::print() const {
    cout << "hey! I'm the print of class Books!" << endl;
    cout << "My title is: " << _title << endl;
    cout << "My author is: " << _author << endl;
}

class AudioBooks: public Books
{
protected:
    string _narrator;
public:
    AudioBooks(const string& ti, const string& au, const string& na)
    : Books(ti, au), _narrator(na)
    { cout << "AudioBooks::constructor() yes." << endl; }
    virtual ~AudioBooks() {cout << "AudioBooks::deconstructor() yes." << endl; }
    virtual void print() const;
};

inline void
AudioBooks::print() const {
    cout << "hey! I'm the print of class AudioBooks!" << endl;
    cout << "My title is: " << _title << endl;
    cout << "My author is: " << _author << endl;
    cout << "My narrator is: " << _narrator << endl;
}

#endif