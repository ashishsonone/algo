#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10002

int win[MAX][MAX]; //-1 undef, 0 loss, 1 win

void init(){
    for(int i=0; i<MAX;i++){
        for(int k=0; k<MAX; k++){
            win[i][k] = -1;
        }
    }
    win[1][0] = 1;
    win[0][1] = 1;
}

int count_active(int n){
    int c = 0;
    for(int i=0; i<32;i++){
        if(n & 1) c++;
        n = n >> 1;
    }
    return c;
}

int findresult(int one, int plus){
    cout << one << " " << plus << endl;
    if(win[one][plus] != -1) return win[one][plus];

    int moves[3];
    moves[0] = 0;
    moves[1] = 0;
    moves[2] = 0;

    if(one != 0){
        int r = findresult(one-1, plus);
        if(!r) moves[0] = 1;
    }
    if(plus != 0){
        int rall = findresult(one, plus-1);
        if(!rall) moves[1] = 1;
        int rmove = findresult(one+1, plus-1);
        if(!rmove) moves[2] = 1;
    }
    int result = moves[0] | moves[1] | moves[2];
    //store and return
    win[one][plus] = result;
    return result;
}

int main(){
    int N, num;
    scanf("%d", &N);
    int one = 0;
    int plus = 0;
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        int c = count_active(num);
        if(c == 1) one++;
        else if(c > 1) plus++;
    }
    init();
    //cout << one << " " << plus << endl;
    int result = findresult(one, plus);
    if(result) cout <<"Shaka :)" << endl;
    else cout << "The other player :(" << endl;
}
