/*
 * @Author: nineis
 * @Date: 2022-03-04 12:28:28
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-04 17:39:16
 * @FilePath: \C++OOP\selfTesting\complex.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 */

//#include <iostream>
#include "complex.hpp"

/**
 * @description: two complex add together using operator +=
 * @param {complex*} ths
 * @param {const complex&} x
 * @return {*} ths
 */
complex&
__doapl(complex* ths, const complex& x){
    ths->re += x.re;
    ths->im += x.im;
    return *ths;
}


/**
 * @description: operator+=
 * @param {const complex&} x
 * @return {complex&}
 */
complex&
complex::operator+= (const complex& x){
    return __doapl(this, x);
}


complex
operator+ (const complex& x, const complex& y){
    return complex( x.real() + y.real(), x.imag() + y.imag());
}

complex
operator+ (const complex& x, const double y){
    return complex( x.real() + y, x.imag());
}

complex
operator+ (const double x, const complex& y){
    return y + x;
}

/**
 * @description: the overloading of operator <<
 * @param {std::ostream&, const complex& }
 * @return {ostream& }
 */
std::ostream&
operator<< (std::ostream& os, const complex& x){
    return os << x.real() << ", " << x.imag() << std::endl;
}

// std::istrea&
// operator>> (std::istream& is, const )