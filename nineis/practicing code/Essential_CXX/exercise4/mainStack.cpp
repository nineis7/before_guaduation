/*
 * @Author: nineis
 * @Date: 2022-03-16 10:25:45
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-16 10:34:34
 * @FilePath: \practicing code\Essential_CXX\exercise4\mainStack.cpp
 * @Description: test main for class stack
 * 
 *          pracitce 4.1 & 4.2
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */


#include "Stack.h"

int main(){
    Stack sta;
    sta.push("what");
    sta.push("what");
    sta.push("what");
    sta.push("what");
    sta.push("what");
    sta.push("unbelievable");
    sta.push("stay");
    sta.push("hold");
    sta.push("shit");
    string word;
    if(sta.peek(word)) cout << word << endl;

    if(sta.find("stay")) cout << "find word 'stay'." << endl;
    cout << "word 'what' occurs for " << sta.count("what") << " times." << endl;
}
