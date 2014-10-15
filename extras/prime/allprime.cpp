#include <iostream>
using namespace std;
#define MAX 1000  //primes upto 100(inclusive)

int find_next(bool * P, int curr, int max){ //find next true index starting from curr
    for(int i=curr; i<=max; i++){
        if(P[i]) return i;
    }
    return -1;
}

int main(){
    bool * P = new bool[MAX+2]; //use only 1 TO MAX

    //initialize to true
    for(int i=0; i<MAX; i++){
        P[i] = true;
    }

    P[1] = false;
    int curr = 1;

    while(true){
        curr = find_next(P, curr, MAX);
        if(curr == -1) break;
        int i = 2;
        for(; curr*i <= MAX; i++){
            P[curr*i] = false;
        }
        curr++;
    }

    int count = 0;
    for(int i=1; i<MAX; i++){
        if(P[i]) {
            count++;
            cout << i << ", ";
        }
    }
    cout << endl;
    cout << "Total primes upto " << MAX << " = " << count << endl;

}
