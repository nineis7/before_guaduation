#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// void fun(int *ap, int *bp)
// {
//     int *cp;
//     cp = ap; ap = bp; bp = cp;
// }

void fun(int **s, int a[2][3])
{
    **s = a[1][1];
}

int main(){
    // cout << sizeof(long double) << endl;
    // int a(8),b(16);
    // int *ap = &a;
    // int *bp = &b;
    // fun(ap, bp);
    // cout << *ap << " " << *bp << endl;

    int a[2][3] = {1,3,5,7,9,11}, *p;
    p = new int;
    fun(&p, a);
    cout << *p << endl;
}