#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    long long N, count, val;
    char c;
    for(int i=0; i<T; i++){
        count = 0;
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> c;
            if(c == '1') count++;
        }
        val = count;
        if(val != 0){
            val += (count * (count-1))/2;
        }
        cout << val << endl;
    }
}
