#include <set>
#include <iostream>
using namespace std;

struct node{
    int f;
    node(int x){
        f =x;
    }
};

struct lt {
 bool operator()(const node* v1, const node * v2){
      if(v1->f < v2->f) return true;
      return false;
  }
};

int main(){
    multiset<node*, lt> S;
    node* n1 = new node(4);
    node* n2 = new node(5);
    node* n3 = new node(2);
    S.insert(n1);
    S.insert(n2);
    S.insert(n3);
    std::multiset<node*, lt>::iterator it;
    it=S.begin();
    cout << ((*it)->f) <<endl;
}
