/*
 * @Author: nineis
 * @Date: 2022-03-15 14:44:24
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 14:56:09
 * @FilePath: \practicing code\Essential_CXX\exercise3\family_info.cpp
 * @Description: practice 3.3
 *                  save infomation from family using map and vector nested
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, vector<string>> fam_info{ {"赵", {"赵匡胤", "赵子航", "赵云", "赵码"} },
                                            { "李", {"李云龙", "李小龙", "李寄", "李不知名"} },
                                            { "王", {"王二", "王丹", "王子", "王无"} },
                                            { "仇", {"仇隽", "仇英"} },
                                            { "孙", {"孙少"} },
                                            { "钱", {"钱龙", "钱学森"} } };
    
    string name;
    cout << "输入你想查询的姓氏： （输入退出即可退出）";
    cin >> name;
    while(name != "退出"){
        if(fam_info.count(name)) {
            cout << "你的家人们是： ";
            for(auto i : fam_info[name]) cout << i << " ";
            cout << endl;
        }
        else cout << "你没有家人啦！" << endl;
        cout << "输入你想查询的姓氏： （输入退出即可退出）";
        cin >> name;
    }
}
