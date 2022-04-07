/*
 * @Author: nineis
 * @Date: 2022-03-04 14:54:04
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-04 16:49:20
 * @FilePath: \C++OOP\selfTesting\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 */


#include "complex.hpp"


int main(){
    complex c1(2, 1);
    complex c2(3, 1);

    std::cout << c1 + c2 << std::endl;

    complex c3 = c1 + c2;
    std::cout << c3 << std::endl;

    c2 += c1;
    std::cout << c2 << std::endl;

}