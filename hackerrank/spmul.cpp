#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

typedef long long int myint;



myint find(int f){
    vector<myint> v;
    v.push_back(0);
    v.push_back(9);
    if(9%f == 0 ) return 9;
    int vsize;
    myint base = 9;
    myint temp;
    while(1){
        vsize = v.size();
        base = base * 10;
        for(int i=0;i<vsize;i++){
            temp = base + v[i];
            //cout <<"in -- "<< temp <<endl;
            if(temp % f == 0) return temp;
            v.push_back(temp);
        }
    }
}
int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int f;
        cin >> f;
        myint ans = find(f);
        cout << ans <<endl;
        
    }
    //base cases
    return 0;
}

