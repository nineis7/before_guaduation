/*
 * @Author: nineis
 * @Date: 2022-03-09 11:18:26
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-09 18:43:42
 * @FilePath: \practicing code\Essential_CXX\exercise1\5-8\GNSystem.hpp
 * @Description: the declaration and parts of definitions of this project
 * 1.the implementation of class GNSystem
 *  the derived classes it has are: 
 *      - the question bank 
 *          + initialize the bank data from disk(BankData.txt);
 *          + append new question into the bank(into the txt file too)
 *      - the user system
 *          + save all the info of each user
 *          + create new user/player
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#pragma once
#ifndef _GNSYSTEM_
#define _GNSYSTEM_

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

class Que;
class QueBank;
class Usr;
class UsrBase;

// class GNSystem{ 

// }

enum CMD { login, quit, showQB, showUB, start};

class Que{
public:
    string _queName;
    int Num[3];
};

class QueBank
{
    vector<Que> que_addr;
public:
    QueBank();
    void showQB();
};

class Usr{
public:
    string usrname;
    // size_t usr_tries;
    // size_t usr_rights;
    size_t usr_scores;
};

class UsrBase{
    vector<Usr> usr_addr;

public:
    UsrBase();
    void showUB();
    void login();
};


bool initialize();

#endif