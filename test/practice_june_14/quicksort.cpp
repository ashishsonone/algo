#include<iostream>
using namespace std;

void print(int *A, int n){
    for(int i=0; i< n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void slowsort(int *A, int l, int h){
    int min, minindex;
    for(int i=l;i<=h;i++){
        min = A[i];
        minindex = i;
        for(int j= i+1; j<=h; j++){
            if(A[j] <  min) {
                min = A[j];
                minindex = j;
            }
        }
        A[minindex] = A[i];
        A[i] = min;
    }
}

int partition(int *A, int low, int high){
    int pivotvalue = A[high];

    int ptr = low;
    for(int i=low; i<= high-1;i++){
        if(A[i] <= pivotvalue){
            swap(&A[ptr], &A[i]);
            ptr++;
        }
    }
    swap(&A[ptr], &A[high]);
    return ptr;
}

void quicksort(int *A, int l, int h){
    int temp;
    if(h - l <=2) {
        cout << "slow " << l << " " << h << endl;
        slowsort(A,l,h);
        return;
    }
    int p = partition(A,l,h);
    quicksort(A, l, p-1);
    quicksort(A, p+1, h);
}

int main(){
    int A [] = {12, 1, 4, 5 , 22, 3};
    print(A, 6);
    quicksort(A, 0, 5);
    print(A, 6);
}
