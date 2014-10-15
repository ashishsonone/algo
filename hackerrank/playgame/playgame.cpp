#include <iostream>
using namespace std;

struct Optimum{
    long val;
    long jump; //valid : 1,2,3

    void print(){
        cout << "<v:" << val << ",j:" << jump << ">";
    }
    Optimum(long v, long j){
        val = v;
        jump = j;
    }
    Optimum(){
    }
};

Optimum ZERO;

// ===================

long play_optimally(long i, long jump);
Optimum max(long i);

long * gstack, gN;
Optimum * gscore;

Optimum get_max3(long a, long b, long c){
    Optimum opt;
    if(a > b){
        if(a > c) {
            opt = Optimum(a, 1);
        }
        else{
            opt = Optimum(c, 3);
        }
    }
    else{
        if(b > c) {
            opt = Optimum(b, 2);
        }
        else{
            opt = Optimum(c, 3);
        }
    }
    return opt;
}

long play_optimally(long i, long jump){
    Optimum you;
    long result = 0;
    if(i+jump-1 < gN) {
        for(long a = i; a < i+jump; a++){ //I take 'jump' numbers
            result += gstack[a];
        }
        you = max(i+jump); //You play optimally
        if(you.jump != 0){
            result += (max((i+jump) + you.jump)).val; //I play starting with new index if your jump is > 0 o/w game ends there
        }
        return result;
    }
    return -1;
}

Optimum max(long i){
    Optimum opt;
    
    if(i >= gN) return ZERO;
    if(gscore[i].jump != -1) return gscore[i];
    
    //cout << "processed "  << i << " " << gN << endl;
    //compute
    long nums[3];
    nums[0] = play_optimally(i, 1);//take just 1
    nums[1] = play_optimally(i, 2);//take 1,2
    nums[2] = play_optimally(i, 3);//take 1,2,3
    opt = get_max3(nums[0], nums[1], nums[2]);
    gscore[i] = opt;
    return opt;
}

void get_max_score(){
    Optimum ans;
    long N;
    cin >> N;
    long * stack = new long[N];

    //input
    for(long i=0; i< N; i++){
        cin >> stack[i];
    }

    /****
    cout << "input taken " << endl;
    for(long i=0; i< N; i++){
        cout << i << " : " << stack[i] << " ";
    }
    cout << endl;
    ****/
    
    //setting up
    Optimum *score = new Optimum[N];
    for(long i=0; i< N; i++) score[i].jump = -1; //i.e invalid(since jump can be 1,2 or 3)

    //setting global variables
    gstack = stack;
    gscore = score;
    gN = N;
    
    ans = max(0);
    cout << ans.val << endl;

    delete[] stack;
    delete[] score;
}

int main(){
    ZERO.val = 0;
    ZERO.jump = 0;

    //get_max3(0, 1, 2).print(); cout << endl;
    //get_max3(1, 0, 2).print(); cout << endl;
    //get_max3(1, 2, 0).print(); cout << endl;
    //get_max3(2, 1, 0).print(); cout << endl;
    
    long T;
    cin >> T;
    for(long i=0; i< T; i++){
        get_max_score();
    }
}
