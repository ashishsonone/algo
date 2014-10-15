#include <iostream>
#include <string>

using namespace std;

void join(int* A, int* B, int la, int lb){//A is bigger
    while(!(la ==0 && lb ==0)){
        int i = la + lb -1;
        if(la == 0){
            A[i] = B[lb-1];
            lb--;
        }
        else if(lb == 0){
            A[i] = A[la-1];
            la--;
        }
        //i.e both arrays are non-empty
        else if(A[la-1] >= B[lb-1]){
            A[i] = A[la-1];
            la--;
        }
        else{
            A[i] = B[lb-1];
            lb--;
        }
    }
}

void print(int *A, int len){
    for(int i=0;i<len;i++){
        cout << A[i] << ", " ;
    }
    cout << endl;
}

int main(){
    int *A = new int[10];
    A[0] = 1;
    A[1] = 4;
    A[2] = 5;
    A[3] = 7;
    
    int *B = new int[3];
    B[0] = 2;
    B[1] = 6;
    B[2] = 8;

    join(A, B, 4,3);
    print(A, 7);

}
