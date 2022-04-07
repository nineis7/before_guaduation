/*
 * @Author: nineis
 * @Date: 2022-03-13 14:16:14
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-13 14:54:06
 * @FilePath: \practicing code\Essential_CXX\exercise2\2\Maxol.cpp
 * @Description: max overloading and template implementation
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 存在疑惑：template中能否使用范围for？
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename elemType>
elemType usr_max(const elemType& para_1, const elemType& para_2)
{
    cout << "Invoking elemtype function..." << endl;
    return (para_1 > para_2) ? para_1 : para_2;
}

template<typename elemType>
const vector<elemType>& usr_max(const vector<elemType>& vec_1, const vector<elemType>& vec_2)
{
    cout << "Invoking vector<elemtype> function..." << endl;
    return (vec_1.size() > vec_2.size()) ? vec_1 : vec_2;
}

template<typename elemType>
bool usr_max(const elemType arr[], const int size)
{
    cout << "Invoking elemtype arr[] function..." << endl;
    int count(0); //for(auto i : arr) ++count;
    while(arr[count] != '\0') ++count;
    return (count > size) ? true : false;
}

inline bool
operator> (string str1, string str2)
{
    cout << "Invoking operator> function..." << endl;
    return (str1.size() > str2.size());
}

int main(){
    int para_int_1(12), para_int_2(14);
    cout << "Type int comparation." << usr_max(para_int_1, para_int_2) << endl; 
    double para_dou_1(12.00), para_dou_2(14.00);
    cout << "Type double comparation: " << usr_max(para_dou_1, para_dou_2) << endl;
    string str_1("serious"), str_2("fuckyoub aby"); //若不重载，比较的是第一个元素的ASCII码
    cout << "Type string comparation: " << usr_max(str_1, str_2) << endl;


    vector<int> vec_1{1,3,5};
    vector<int> vec_2{1,3,5,9};
    cout << "Type vector<int> comparation: " << usr_max(vec_1, vec_2).size() << endl;
    float arrf[]{1.2, 2.5};
    cout << "Type arr_f comparation: " << usr_max(arrf, 5) << endl; 


}