#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define MOD 1000000007

int main(){
    unsigned long long T,l, val;
    T = 40000000005;
    T = T * 2 + 1;
    l = 60000000000;
    //cout << (unsigned long long)(T%l) << endl;;
    
    cin >> T;
    //cout  << sizeof(T) <<endl;
    
    for(int i=0; i<T; i++){
        string S;
        val = 1;
        cin >> S;
        l = S.size();
        for(int c=0; c<l; c++){
            if(c % 2 == 0){
                if(S[c] == 'l'){
                    val = (2*val) % MOD; 
                }
                else{
                    val = (2*val+2) % MOD;
                }
            }
            else{
                if(S[c] == 'l'){
                    val = (2*val-1) % MOD; 
                }
                else{
                    val = (2*val+1) % MOD;
                }
            }
        }
        cout << val << endl;
    }
}
