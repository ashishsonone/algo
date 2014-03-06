#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct interval{
    int start;
    int end;
    int cost;
    /*bool operator < (const interval & i){
        if(start < i.start) return true;
        return false;
    }
    */
    void print(){
        printf("<%2d,%2d,%2d>", start, end, cost);
    }
    void print_visual(){
        print();
        cout <<" | ";
        for(int i=0; i<start;i++){
            cout<<"  ";
        }
        //cout << "|";
        for(int i=start; i<end;i++){
            cout<<"__";
        }
        //cout <<"|";
        cout <<endl;
    }
};

bool operator<(const interval& lhs, const interval& rhs){
    if(lhs.start < rhs.start) return true;
    return false;
}

void printvec(vector<interval> & vec){
    for(int i=0; i<vec.size(); i++){
        vec[i].print();
        cout << " ";
    }
    cout <<endl;
}
void printvec_visual(vector<interval> & vec){
    for(int i=0; i<vec.size(); i++){
        vec[i].print_visual();
    }
    cout <<endl;
}

string getkey(interval in){
    return (to_string(in.start) + "," + to_string(in.end));
}

vector<interval> vec; //will store sorted intervals

//vector<vector<int> > memo;

//stores union cost for (next_int_no, last_seen_point)
unordered_map<string, int> memo_map;
//if(graph.find(key) == graph.end()){
//graph[key]=n1;

bool can_skip(int index, int covered){
    int end = vec[index].end;
    if(vec[index].start > covered){ //i.e index'th interval has gap from last covered  --c|  |----|
        covered = vec[index].start;
    }
    cout << "END " << end <<endl;
    cout << "COVERED " << covered <<endl;
    for(int i=index + 1; i<vec.size(); i++){
        if(vec[i].start <= covered){
            if(vec[i].end > covered){
                covered = vec[i].end;
            }
        }
        else{//it's start leaves a gap from covered
            return false;
        }
        cout << "i " << i << " covered "<< covered <<endl;
        if(covered >= end) return true;
    }
    if(covered >= end) return true;
    return false; //still covered < end (valid also if index is the last element. won't go into loop, trivally wrong i.e can't skip this last interval)
}

int next_valid(int index){//if you take index-interval which is the next index to recurse on(removing the submerged intervals)
    int end = vec[index].end;
    int i;
    for(i=index+1; i< vec.size(); i++){
        if(vec[i].end > end) break;
    }
    return i; //i==size-1 if all remaining are subsumed under this index
}

int cost(int next_index, int covered){
    if(next_index == vec.size()) return 0;

    int c = 0;
    int n_valid = next_valid(next_index);
    bool skip = can_skip(next_index, covered);
    if(skip){//min of pick & not pick
        int ctake = vec[next_index].cost + cost(n_valid, vec[next_index].end); //new covered
        int cleave = cost(next_index + 1, covered);
        c = ctake < cleave ? ctake : cleave;
    }
    else{//has to pick
        c = vec[next_index].cost + cost(n_valid, vec[next_index].end); //new covered
    }
    return c;
}

int main(){
    int N; //no of intervals
    cin >> N;

    //memo = *(new vector<vector<int> >(N, vector<int>(N, -1))); //init memo with -1

    for(int i=0; i<N; i++){
        interval in;
        cin >> in.start;
        cin >> in.end;
        cin >> in.cost;
        //cout << "key " << getkey(in) <<endl;
        vec.push_back(in);
    }

    /*
    interval i1 = {1,3};
    interval i2 = {2,5};
    interval i3 = {0,4};
    interval i4 = {7,10};
    interval i5 = {3,7};


    vector<interval> vec = {i1,i2,i3,i4,i5};
    cout << "comp " << (i1<i2) <<endl;
    */
    sort(vec.begin(), vec.end());
    printvec_visual(vec);
    cout << "can skip " << can_skip(3,5) << endl;
    cout << "next_valid  " << next_valid(1) << endl;
    cout << "cost total  " << cost(0,0) << endl;

    //cout << memo[4][4] <<endl;
}
