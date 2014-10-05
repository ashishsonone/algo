#include <iostream>
using namespace std;

//returns a possible majority candidate(if there is any). 
//Must check the returned value whether it is indeed in majority
int majority(int *A, int n){
    int candidate = A[0];
    int count = 1;
    for(int i=1; i<n; i++){
        cout << candidate << " " << count << endl;
        int e = A[i];
        if(e == candidate) count++;
        else if(count > 0) count--;
        else{ //count is 0. Make this new candidate
            candidate = e;
            count = 1;
        }
    }

    return candidate;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int candidate = majority(A, N);
    //check if this candidate is indeed in majority
    int c = 0;
    for(int i=0; i<N ; i++){
        if(A[i] == candidate) c++;
    }
    if(c > N/2) cout << "majority is " << candidate << endl;
    else cout << "no majority" << endl;
}
