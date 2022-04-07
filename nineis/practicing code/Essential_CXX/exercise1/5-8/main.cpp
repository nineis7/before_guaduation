/*
 * @Author: nineis
 * @Date: 2022-03-09 11:17:32
 * @LastEditors: nineis
 * @LastEditTime: 2022-03-09 19:17:21
 * @FilePath: \practicing code\Essential_CXX\exercise1\5-8\main.cpp
 * @Description: exercise 1.5-8 in essencial C++ book.
 * 
 * Copyright (c) 2022 by nineis, All Rights Reserved. 
 * @Notes: 
 */

#include "GNSystem.hpp"
#include "EnumParse.hpp"

/*
int main(){
    //if(!initialize()) { cerr << "Oops! initialization failed. " << endl;}
    vector<int> fibonacci{ 1, 2, 3 };
    vector<int> lucas{ 3, 4, 7 };
    vector<int> pell{ 2, 5, 12 };
    vector<int> triangular{ 3, 6, 10 };
    vector<int> square{ 4, 9, 16 };
    vector<int> pentagonal{ 5, 12, 22 };
   // const int seq_cnt = 6;
    vector<int> *seq_addrs[seq_cnt] = {
        &fibonacci, &lucas, &pell,
        &triangular, &square, &pentagonal 
    };

    string usr_name;
    size_t num_tries(0);
    size_t num_right(0);
    size_t num_cor = 0;
    bool is_new = true;

    cout << "please enter your name: "; cin >> usr_name;

    // infile opened in output mode
    ifstream infile("seq_data.txt", ios_base::in | ios_base::app);
    if (! infile)
    {
    // open failed for some reason ...
    // we'll presume it is a new user ...
    }
    else
    {
    // ok: read each line of the input file
        // see if user has played before ...
        // format of each line:
        // name num_tries num_correct
        // nt: number of tries
        // nc: number of correct guesses
        string name;
        int nt;
        int nc;
        while (infile >> name)
        {
        infile >> nt >> nc;
        if (name == usr_name)
        {
            // match!
            cout << "Welcome back, " << usr_name
                 << "\nYour current score is " << nc
                 << " out of " << nt << "\nGood Luck!\n";
            num_tries = nt;
            num_cor = nc;
            is_new = false;
        }
        }
    }
    
    if(is_new){
        cout << "It seems like you are a new guy, so please enter your info: " << endl;
        cout << "Username, num tries and num right: "; cin >> usr_name >> num_tries >> num_right;

        ofstream outfile("seq_data.txt", ios_base::app);
        if(!outfile) { cerr << "Oops! Unable to save session data!" << endl; }
        else {
            outfile << usr_name << ' '
                    << num_tries << ' '
                    << num_right << endl;
            cout << "save success!" << endl;
        }
    }

    srand(seq_cnt);
    vector<int> *current_vec = 0;
    while(1){
        size_t seq_index = rand() % seq_cnt;
        current_vec = seq_addrs[seq_index];
        cout << "The first two elements of the sequence are: "
             << (*current_vec)[0] << ", "
             << (*current_vec)[1]
             << "\nWhat is the next element? ";
        size_t usr_guess(0);
        cin >> usr_guess;
        while(usr_guess != (*current_vec)[2]){
            cout << "Try again!" << endl;
            cin >> usr_guess;
        }
        cout << "Congratulations!" << endl;
    }

}
*/

int main(){
    cout << "Initializing the GNSystem..." << endl;
    QueBank QB;
    UsrBase UB;
    if(!initialize()) cerr << "Oops! Something went wrong!" << endl;
    else cout << "Initialization success!" << endl;

    cout << "--------------Welcome to the GNSystem!----------------" << endl;
    EnumParser<CMD> CMDTypeParser;
    string mycmd;
    cout << "enter your command >  "; cin >> mycmd;
    CMD command = CMDTypeParser.ParseSomeEnum(mycmd);
    while( command != quit ){
        switch (command)
        {
        case showQB:
            QB.showQB();
            cout << "enter your command >  "; cin >> mycmd;
            command = CMDTypeParser.ParseSomeEnum(mycmd);
            break;
        
        case showUB:
            UB.showUB();
            cout << "enter your command >  "; cin >> mycmd;
            command = CMDTypeParser.ParseSomeEnum(mycmd);
            break;
        
        case start:
            cout << "let's start!" << endl;
            cout << "enter your command >  "; cin >> mycmd;
            command = CMDTypeParser.ParseSomeEnum(mycmd);
            break;
        
        case login:
            //UB.login();
            cout << "enter your command >  "; cin >> mycmd;
            command = CMDTypeParser.ParseSomeEnum(mycmd);
            break;
        
        // case showQB:
        //     QB.showQB();
        //     break;
        
        default:
            break;
        }
    }
    // QB.showQB();
    // UB.showUB();
}