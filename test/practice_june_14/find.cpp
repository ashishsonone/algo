#include <iostream>
using namespace std;

int find(int *A, int l, int h, int x){
    while(l <= h){
        mid = (l + h)/2;
        if(A[mid] == x) return mid;
        else if(A[l] <= A[mid]){
            if(x > A[mid]) l=mid+1;
            else if(x >= A[l]) h=mid-1;
            else l = mid+1;
        }
        else if(x < A[mid]) h = mid-1;
        else if(x <= A[h]) l = mid+1;
        else h = mid-1;
    }
}
