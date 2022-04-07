/*
 * @Author: nineis
 * @Date: 2022-03-09 11:48:06
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-09 19:13:58
 * @FilePath: \practicing code\Essential_CXX\exercise1\5-8\GNSystem.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "GNSystem.hpp"
#include "EnumParse.hpp"

bool initialize(){
    return true;
}

QueBank::QueBank(){
    ifstream infile("que_bank.txt", ios::in | ios::app);
    Que que_tmp;
    while(infile >> que_tmp._queName){
        infile >> que_tmp.Num[0] >> que_tmp.Num[1] >> que_tmp.Num[2];
        que_addr.push_back(que_tmp);
        //cout << "magic happens" << endl;
    }
}

void
QueBank::showQB(){
    vector<Que>::iterator i;
    cout << "-------The quesiton Bank--------" << endl;
    for( i = que_addr.begin(); i != que_addr.end(); ++i){
        cout << (*i)._queName << ' '
             << (*i).Num[0] << ' '
             << (*i).Num[1] << ' '
             << (*i).Num[2] << endl;
    }

}

UsrBase::UsrBase(){
    ifstream infile("usr_bank.txt", ios_base::app);
    Usr usr_tmp;
    while(infile >> usr_tmp.usrname){
        infile >> usr_tmp.usr_scores;
        usr_addr.push_back(usr_tmp);
    }
}

void
UsrBase::showUB(){
    vector<Usr>::iterator i;
    cout << "-------The userBase--------" << endl;
    for(i = usr_addr.begin(); i != usr_addr.end(); ++i){
        cout << (*i).usrname << ' '
             << (*i).usr_scores << endl;
    }
}

template<>
EnumParser<CMD>::EnumParser(){
    enumMap["quit"] = quit;
    enumMap["login"] = login;
    enumMap["showQB"] = showQB;
    enumMap["showUB"] = showUB;
    enumMap["start"] = start;
}