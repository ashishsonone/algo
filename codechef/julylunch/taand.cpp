#include <iostream>
#include <bitset>
#include <algorithm>
#define MAXINDEX 32
using namespace std;

void print(bool *array, int N){
    for(int i=0; i<N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
void copy(bool *from, bool* to, int N){
    for(int i=0; i<N; i++){
        to[i] = from[i];
    }
}

void reset(bool *array, bool val, int N){
    for(int i=0; i<N; i++){
        array[i] = val;
    }
}

int main(){
    //int A[] = {4,5,2,3};
    //sort(A, A + 4);
    //cout << A[0] <<endl;
    int N, temp;
    cin >> N;

    bitset<MAXINDEX> * A = new bitset<MAXINDEX>[N];

    for(int i=0; i<N; i++){
        cin >> temp;
        A[i] = temp;
        //cout << A[i] << endl;
    }
    //cout << "input over" << endl;

    //starts here
    bool * old = new bool[N];
    bool * curr = new bool[N];
    reset(old, true, N); //1 means it is still a candidate;

    int good; //No of good candidates found so far in current run
    copy(old, curr, N);
    for(int index=MAXINDEX-1; index>=0; index--){
        good = 0;
        for(int j=0; j<N; j++){
            if(old[j]){ //only then consider it for current run
                if(A[j][index]){//i.e it is 1
                    good++;
                    curr[j] = true;
                }
                else{
                    curr[j] = false; //VERY important step missed in first go
                }
            }
        }
        if(good >= 2){//this round was success, curr becomes new old
            copy(curr, old, N);
            //cout << "N" << index << endl;
            //print(old, N);
        }
        else{//reset curr to prev old
            copy(old, curr, N);
            //cout << "O" << index << endl;
        }
    }

    //Now get any two numbers from final valid set and find their AND
    int N1, N2;
    bool f1 = false;
    for(int i=0; i<N; i++){
        //cout << A[i].to_ulong() << endl;
        if(old[i]){
            if(!f1){//first number still not found
                N1 = A[i].to_ulong();
                f1 = true;
            }
            else{
                N2 = A[i].to_ulong();
                break; // we're done
            }
        }
    }

    //cout <<  N1 << " & " << N2 << " = " <<  (N1 & N2) << endl;
    cout <<  (N1 & N2) << endl;
}
