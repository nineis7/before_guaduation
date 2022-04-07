/*
 * @Author: nineis
 * @Date: 2022-03-17 16:56:39
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-17 17:34:47
 * @FilePath: \practicing code\CPPpra\201601.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
using namespace std;

/*
int main(){
    vector<string> vec_word;
    istream_iterator<string> is( cin );
    istream_iterator<string> eof;

    copy(is, eof, back_inserter(vec_word) );

    for(auto i : vec_word) cout << i << " 的长度为： " << i.size() << endl; 
}
*/

int main(){
    string word;
    while(cin >> word){
        cout << word << " 的长度为： " << word.size() << endl;
        // cin.clear();
    }
    // cin.clear();
}
