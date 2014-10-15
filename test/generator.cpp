#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

#define N 5

using namespace std;
bool palcheck(bitset<N> a){
    for(int i=0; i< N/2; i++){
        if(a[i]!=a[N-i-1]) return false;
    }
    return true;
}
bool majcheck(bitset<N> a){
    int count = a.count();
    if(2*count >= N) return true;
    else return false;
}

void loopy(bool (*check)(bitset<N> a)){
    bitset<N> b;
    for(int i=0; i<pow(2,N);i++){
        b = i;
        if(check(b)) cout << b <<" 1" <<endl;
        else cout << b <<" 0" <<endl;
    }
}

int main(){
    bitset<N> b(string("101101"));
    //cout << palcheck(b) <<" " << b <<endl;
    //loopy(palcheck);
    loopy(majcheck);
}
