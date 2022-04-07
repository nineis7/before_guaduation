/*
 * @Author: nineis
 * @Date: 2022-03-14 14:26:25
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-14 14:29:31
 * @FilePath: \DS\vector\selfAssignmentTest.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void print_vec(vector<int> const& V)
{
    for(auto i: V) cout << i << " ";
    cout << endl;
}

vector<int>&
vector::operator= ( vector<int> const& V)
{

}

int main(){
    vector<int> v1{1,2};
    v1 = v1;
    print_vec(v1);
    // vector<int> v2;
}