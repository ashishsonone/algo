#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Frog{
    int x;
    int id; //1 - n 
    Frog(){
        x = -1;
        id = -1;
    }
    void print(){
        cout << "(" << x << ","  << id << ")  ";
    }
} Frog;

bool compareFrogs(Frog f1, Frog f2){
    return f1.x < f2.x;
}

int main(){
    int N, K, P;
    cin >> N >> K >> P;

    int x;

    Frog * line = new Frog[N];
    for(int i=0; i<N; i++){
        cin >> x;
        line[i].x = x;
        line[i].id = i+1;
    }

    //sort acc to x co-ordinte
    sort(line, line+N, compareFrogs);

    /*
    for(int i=0; i<N; i++){
        line[i].print();
    }
    */

    int * cluster = new int[N+1]; //for each id - store cluster id
    for(int i=1; i<N+1; i++){
        cluster[i] = -1;
    }

    int curr_cluster = 0;
    cluster[line[0].id] = curr_cluster; //starting frog gets cluster id 1
    int prevx = line[0].x;
    for(int i=1; i<N; i++){
        if(line[i].x > prevx + K){//time to create a new cluster
            curr_cluster++;
        }
        cluster[line[i].id] = curr_cluster;
        prevx = line[i].x;
    }

    int a, b;
    //now take queries
    for(int i=0; i<P; i++){
        cin >> a >> b;
        if(cluster[a] == cluster[b]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

