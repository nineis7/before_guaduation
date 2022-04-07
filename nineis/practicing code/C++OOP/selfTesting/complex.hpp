/*
 * @Author: nineis
 * @Date: 2022-03-04 12:23:12
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-04 17:43:25
 * @FilePath: \C++OOP\selfTesting\complex.hpp
 * @Description: the declaration of the complex class
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * 
 * @Notes:
 * the definition of inline function needs to be put into .hpp file.
 */
#pragma once
#ifndef _MYCOMPLEX_H
#define _MYCOMPLEX_H

#include <iostream>
class complex;
complex&
__doapl(complex* ths, const complex& x);

complex
operator+ (const complex& x, const complex& y);

complex
operator+ (const complex& x, const double y);

complex
operator+ (const double x, const complex& y);

std::ostream&
operator<< (std::ostream & os, const complex& x);

class complex{
public:
    complex(double r = 0, double i = 0): re(r), im(i) {}
    double real() const { return re;}
    double imag() const { return im;}
    complex& operator+= (const complex& x);


private:
    double re, im;

    friend complex& __doapl(complex*, const complex&);
};


#endif