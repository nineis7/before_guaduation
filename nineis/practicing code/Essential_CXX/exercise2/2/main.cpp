/*
 * @Author: nineis
 * @Date: 2022-03-13 13:50:07
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-13 14:12:48
 * @FilePath: \practicing code\Essential_CXX\exercise2\2\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "NumSeq.h"

int main(){
    const vector<int >* vec;
    // if(createSeq(5, vec)) cout << "create 5 success! " << endl; displaySeq(vec);
    // if(createSeq(13, vec)) cout << "create 5 success! " << endl; displaySeq(vec);
    // if(createSeq(-5, vec)) cout << "create 5 success! " << endl; displaySeq(vec);
    vec = createSeq(5); displaySeq(*vec);
    vec = createSeq(12); displaySeq(*vec);
    int elem(0);
    if(get_elem(4, elem, *vec)) cout << "element # " << 4 << " is: " << elem << endl;

}