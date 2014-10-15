#include <iostream>
using namespace std;

int gN, *garray, *gcost;

get_best_cost(){
    int N;
    cin >> N;
    int * array = new int[N];
    for(int i=0; i<N; i++){
        cin >> array[i];
    }
    
    int * cost = new int[N];
    for(int i=0; i<N;i++){
        cost[i] = 0;
    }
    
    //set globals
    gN = N;
    garray = array;
    gcost = cost;
    
    for(int i=)
}

int main(){
    int T;
    cin >> T;
    
    for(int i=0; i< T; i++){
        get_best_cost();
    }
}
