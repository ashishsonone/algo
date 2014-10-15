#include <iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    int x = (bool) a;
    if(x == 0) cout << x << endl;
    else if(x == 1) cout << x << endl;
    else cout << "Unexpected" << endl;
}
