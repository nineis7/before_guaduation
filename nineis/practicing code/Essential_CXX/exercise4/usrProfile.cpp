/*
 * @Author: nineis
 * @Date: 2022-03-17 16:54:29
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-17 18:17:25
 * @FilePath: \practicing code\Essential_CXX\exercise4\usrProfile.cpp
 * @Description: practice 4.4
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class UserProfile
{
public:
    UserProfile(bool l = true, string n = "guess",
                size_t lc = 1, size_t TGT = 0, size_t CGT = 0
                )
private:
    bool _isLogin; //登陆状态
    string _name;  //实际姓名
    size_t _loginCount; //登录次数
    size_t _TotGT, _CorGT;  //猜过次数，猜对次数
    vector<string> _level; //等级
    double CorPercentage;   //猜对百分比
};

int main(){

}