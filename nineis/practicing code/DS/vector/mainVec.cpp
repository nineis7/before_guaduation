/*
 * @Author: nineis
 * @Date: 2022-03-14 15:17:11
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-14 15:48:31
 * @FilePath: \DS\vector\mainVec.cpp
 * @Description: testing
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "myVector.h"
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
// using namespace std;

int main(){
    Vector<int> Vec(6, 3, 3);
    Vector<int> Vec_tmp(Vec);
    Vec_tmp = Vec;
    Vec = Vec;
    cout << Vec.size() << endl;
    // for(int i(0); )
}
