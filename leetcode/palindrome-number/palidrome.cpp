#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) {
    int c = x;
    int pow10;
    int high;
    for(pow10=1 ; ; pow10++){
        //cout << (c/high) << " " << high << endl;
        c = c/10;
        if(!c) break;
    }


    high = 1;
    for(int i=1; i<pow10; i++){
        high = high *10;
    }
    cout << x << " " << pow10 <<   " high" << high << endl;
    
    c = x;

    bool ispal = true;
    for(int i=0, div=high; i<pow10/2; i++, div=div/100){
        int mod = 10;
        cout << "c =" << c << " div = " << div << " | " << c%mod << "==" << c/div << endl;
        if(c%mod != c/div) {
            ispal = false;
            break;
        }
        c = c % div;
        c = c / mod;
    }
    return ispal;
}
int main(){
    int x;
    cin >> x;
    cout << isPalindrome(x);
}
