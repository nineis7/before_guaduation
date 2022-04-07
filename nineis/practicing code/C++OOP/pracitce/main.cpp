/*
 * @Author: nineis
 * @Date: 2022-03-07 14:49:49
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-07 15:13:46
 * @FilePath: \C++OOP\pracitce\main.cpp
 * @Description: testing
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 * Conclusion: when a derived class has component part and it invokes, the sequence should be:
 *  market()[base] -> fruit()[component] -> basket()[derived] {constructor order}
 *  析构顺序相反
 */

#include "market.hpp"

int main(){
    //fruit apple(20);
    //cout << "---------------------" << endl;
    basket ba;
}