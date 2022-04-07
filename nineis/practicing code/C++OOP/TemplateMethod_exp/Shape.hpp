/*
 * @Author: nineis
 * @Date: 2022-03-07 11:52:09
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-07 12:05:30
 * @FilePath: \C++OOP\TemplateMethod_exp\Shape.hpp
 * @Description: using to test and study template method and the application of virtual function 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#pragma once
#ifndef _MYSHAPE_
#define _MYSHAPE_

#include <iostream>
using namespace std;

class Shape
{
private:
    /* data */
public:
    Shape(/* args */) {}
    ~Shape() {}
    virtual void start_to_draw();
private:
    virtual void draw() = 0;
};

inline void
Shape::start_to_draw(){
    cout << "here is start_to_draw function invoking." << endl;
    draw();
}

class Rectangle: public Shape
{
private:
    /* data */
public:
    Rectangle(/* args */) {}
    ~Rectangle() {}
    virtual void draw();
};

inline void
Rectangle::draw(){
    cout << "draw a line * 4" << endl;
}

class Ellipse: public Shape
{
private:
    /* data */
public:
    Ellipse(/* args */) {}
    ~Ellipse() {}
    virtual void draw();
};

inline void
Ellipse::draw(){
    cout << "draw a curve." << endl;
}

#endif
