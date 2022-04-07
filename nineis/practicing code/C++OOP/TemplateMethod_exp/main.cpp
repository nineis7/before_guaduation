/*
 * @Author: nineis
 * @Date: 2022-03-07 12:02:59
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-07 12:08:45
 * @FilePath: \C++OOP\TemplateMethod_exp\main.cpp
 * @Description: testing main
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 1. rec.start_to_draw() == Shape::start_to_draw(&rec). So 'this pointer' is &rec.
 *         2. draw() == rec->draw(); 
 */


#include "Shape.hpp"

int main(){
    Rectangle rec;
    rec.start_to_draw(); //derived class invokes base function.

    cout << "-------------" << endl;

    Ellipse ell;
    ell.start_to_draw();
}