#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Ccc{
private:
    int xx,yy;
public:
    Ccc(int x, int y): xx(x), yy(y) {}
    friend Ccc& operator++(Ccc &);
    Ccc& operator++(int);
    void print_Ccc() { cout << xx << yy << endl; }
};

Ccc& operator++ (Ccc &x)
{
    ++x.xx;
    ++x.yy;
    return x;
}

Ccc& Ccc::operator++ (int)
{
    this->xx++;
    this->yy++;
    return *this;
}

int main(){
    Ccc t(20,20);
    //++t;
    t++;
    t.print_Ccc();
}
