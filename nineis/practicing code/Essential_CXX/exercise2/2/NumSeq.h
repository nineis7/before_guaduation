/*
 * @Author: nineis
 * @Date: 2022-03-13 13:22:43
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-13 14:09:20
 * @FilePath: \practicing code\Essential_CXX\exercise2\2\NumSeq.h
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#pragma once
#ifndef _MYNUMSEQ_
#define _MYNUMSEQ_

#include <vector>
#include <iostream>
using namespace std;

#define MAX_SIZE 1024
#define MIN_SIZE 0

bool createSeq(const int size, vector<int>& usr_vec);
void displaySeq(const vector<int>& usr_vec);

inline bool 
is_ok(const int size)
{
    return ((size > MIN_SIZE) && (size < MAX_SIZE));
}

const vector<int>* createSeq(const int size);
bool get_elem(const int pos, int& elem, const vector<int>& usr_vec);

#endif