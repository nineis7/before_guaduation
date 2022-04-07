/*
 * @Author: nineis
 * @Date: 2022-03-12 15:32:22
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-12 15:53:28
 * @FilePath: \practicing code\Essential_CXX\exercise2\1\main.cpp
 * @Description: test main
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "fun.hpp"

int main(){
    cout << "Please enter the position you want to get from the fibon sequence: (999 for quiting) ";
    size_t pos(0);
    size_t elem(0);
    cin >> pos;
    while (pos != 999)
    {
        if(get_fibon_elem(pos, elem)){
            cout << "element # " << pos
                 << " is " << elem << endl;
        }else{
            cout << "Oops! Something went wrong! please check out your input." << endl;
        }

        cout << "Please enter the position you want to get from the fibon sequence: (999 for quiting) ";
        cin >> pos;
    }

    cout << "Bye!" << endl;
    
}