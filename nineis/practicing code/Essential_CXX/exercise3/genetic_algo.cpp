/*
 * @Author: nineis
 * @Date: 2022-03-15 09:01:17
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-15 09:24:00
 * @FilePath: \practicing code\Essential_CXX\exercise3\genetic_algo.cpp
 * @Description: testing genetic algorithm filter()
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int count_occurs(vector<int> const& , int);

vector<int> filter(vector<int> const& V, int filter_value, 
                    bool (*pred)(int, int))
{
    vector<int> vec_tmp;

    for(int ix(0); ix < V.size(); ++ix)
        if(pred(V[ix], filter_value)){
            vec_tmp.push_back(V[ix]);
            cout << "Element " << V[ix] << " appears " << count_occurs(V, V[ix]) << " times." << endl;
        }

    
    return vec_tmp;
}

//对vector中一个值的出现频率进行计算
int count_occurs(vector<int> const& V, int val)
{
    vector<int>::const_iterator iter = V.begin();
    int count(0);
    //very beautiful
    while((iter = find(iter, V.end(), val)) != V.end()){
        ++iter;
        ++count;
    }

    return count;
}

inline
bool less_than(int pre, int suf) { return (pre < suf) ? true : false; }

inline
bool greater_than(int pre, int suf) { return (pre > suf) ? true : false; }

inline
void print_vec(vector<int> const& V)
{
    for(auto i : V) cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> vec{1,2,4,7,2,3,4,5,6,7,7,8};
    vector<int> v2 = filter(vec, 6, less_than);
    print_vec(v2);
    vector<int> v3 = filter(vec, 4, greater_than);
    print_vec(v3);
}