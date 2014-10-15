#include <iostream>
#include <bitset>
using namespace std;

#define NUMBITS 32
typedef bitset<NUMBITS> B32;

void print(int A[]){
    for(int i=0; i< NUMBITS; i++){
        cout << A[NUMBITS-i-1];
    }
}

int singleNumber(int A[], int n) {
    int count[NUMBITS];
    for(int i=0; i<NUMBITS; i++){
        count[i] = 0;
    }
    //cout << "c " ;print(count); cout << endl;
    for(int k=0; k<n; k++){
        B32 num = A[k];
        for(int i=0; i<NUMBITS; i++){
            count[i] = (count[i] + num[i])%3;
        }
        //cout << "n " << num << "    " << A[k] << endl;
        //cout << "c "; print( count); cout << endl;
    }

    B32 ans;
    for(int i=0; i<NUMBITS; i++){
        ans[i] = count[i];
    }
    return (int)ans.to_ulong();
}
int main(){
    int A[10];
    for(int i=0; i<10; i++){
        cin >> A[i];
    }

    cout << singleNumber(A, 10) << endl;
}
