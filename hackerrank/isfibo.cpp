#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


typedef long long int myint;

int main() {
    
    int N;
    cin>>N;
    myint vm, vp, root;
    for(int i=0;i<N;i++){
        myint num;
        cin >> num;
        vm = 5*num*num -4 ;
        vp = vm + 8;
        //cout << vm << " "<<vp <<endl;
        root = sqrt(vm);
        if(root*root == vm) {cout<<"IsFibo" <<endl;continue;}
        root = sqrt(vp);
        if(root*root == vp) {cout<<"IsFibo" <<endl;continue;}
        cout<<"IsNotFibo" <<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
