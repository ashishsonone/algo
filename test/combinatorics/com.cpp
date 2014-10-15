#include <iostream>
using namespace std;

class Solution {
public:
    int nCr(int N, int R){
        cout << R << endl;
        int num = 1, den= 1;
        for(int i=0; i<R; i++){
            num *= (N-i);
            den *= (R-i);
            cout <<  num << " " << den << endl;
        }
        return num/den;
    }

    int uniquePaths(int m, int n) {
        return nCr(m+n, n);
    }
};

int nCr(int N, int R){
    int num = 1, den= 1;
    for(int i=0; i<R; i++){
        num *= (N-i);
        den *= (R-i);
    }
    return num/den;
}
int main(){
    int v = nCr(101,1);
    cout << v << endl;
    Solution S;
    cout << S.uniquePaths(100,1);
}
