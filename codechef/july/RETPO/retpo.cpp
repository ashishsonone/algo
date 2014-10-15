#include <iostream>
#include <cmath>
using namespace std;

typedef struct point{
    long long x;
    long long y;

    void print(){
        cout << x << "," << y << endl;
    }
} point;

int signof(long long val){
    if(val < 0) return -1;
    return 1;
}

long long steps(bool scenario, long long len){
    long long dist = 0;
    if(scenario == 0){ //facing along same dir
        dist = (len/2) * 4 + (len%2) * 3;
    }
    else{
        dist = (len/2) * 4 + (len%2) * 1;
    }
    return dist;
}

point next_hop(point dest){
    point hop;
    if(abs(dest.x) <= abs(dest.y)){ //x is closer
        hop.x = abs(dest.x) * signof(dest.x);
        hop.y = abs(dest.x) * signof(dest.y);
    }
    else{//y is closer
        hop.x = abs(dest.y) * signof(dest.x);
        hop.y = abs(dest.y) * signof(dest.y);
    }
    return hop;
}

point subtract(point &dest, point &orig){
    point diff;
    diff.x = dest.x - orig.x;
    diff.y = dest.y - orig.y;
    return diff;
}

int main(){
    point origin;
    origin.x = 0;
    origin.y = 0;

    long long T;
    cin >> T;
    point dest;
    long long dist = 0;
    bool scenario;
    long long len;
    for(int i=0; i<T; i++){
        cin>> dest.x;
        cin>> dest.y;

        point next = next_hop(dest);
        //next.print();

        dist = abs(next.x) * 2; //staircase movement until min(x,y)
        //cout << "hop dist" << dist << endl;

        point diff = subtract(dest, next);
        //diff.print();
        
        scenario = diff.x != 0 ? 0 : 1; //after staircase movement till next hop, we will always face horizontally
        len = diff.x != 0 ? abs(diff.x) : abs(diff.y);

        dist += steps(scenario, len);

        cout << dist << endl;
    }
    return 0;
}
