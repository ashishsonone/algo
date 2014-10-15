// conditional operator
#include <iostream>
using namespace std;

int main ()
{
    int a, b,c,d;
    a = 0;
    b = 2;
    d = (!a < !b );
    c = a == 0 < b == 0;
    cout << d << " "<<c <<endl;
}
