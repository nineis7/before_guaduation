/*
 * @Author: nineis
 * @Date: 2022-03-07 10:36:52
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-07 11:11:16
 * @FilePath: \C++OOP\LibMat\main.cpp
 * @Description: test main
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "lib.hpp"

int main() {
    cout << "----------- the testing of derived class with virtual characters--------" << endl;
    LibMat lm; 
    print(lm);
    cout << "---------------wait" << endl;

    Books bo("how i met your mother", "nineis");
    print(bo);
    cout << "---------------wait" << endl;

    AudioBooks au("jianlai", "nineis", "myFather");
    print(au);
}