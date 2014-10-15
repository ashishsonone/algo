#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <list>
using namespace std;

struct Node{
    char val;
    list<Node*> children;
    Node(char x){
        val = x;
    }
};

string seq = "";

void serialize(Node * n){
    list<Node*>::iterator it = n->children.begin();
    seq += n->val;
    for(; it != n->children.end(); it++){
        serialize(*it);
    }
    seq += ")";
}

Node* deserialize(string s)
{
    stack<Node*> S;
    Node * dummy = new Node('0');

    S.push(dummy);

    for(int i=0; i<s.length(); i++){
        if(s[i] == ')'){
            S.pop();
            continue;
        }
        Node * currp = S.top();
        Node * cur = new Node(s[i]);
        currp->children.push_back(cur);
        S.push(cur);
    }
    Node * root = dummy->children.front();
    delete(dummy);
    return root;
}

static int myindex = 0;
void des(Node *&n, string s){
    if(n == NULL){
        n = new Node(s[0]);
        myindex = 1;
    }
    while(s[myindex]!=')'){
        Node * child = new Node(s[myindex]);
        n->children.push_back(child);
        myindex++;
        des(child, s);
    }
    myindex++;
}

int main(){
    Node * a = new Node('A');
    Node * a1 = new Node('B');
    Node * a2 = new Node('C');
    Node * a11 = new Node('D');
    Node * a12 = new Node('E');
    Node * a13 = new Node('F');
    Node * a21 = new Node('G');

    a->children.push_back(a1);
    a->children.push_back(a2);

    a1->children.push_back(a11);
    a1->children.push_back(a12);
    a1->children.push_back(a13);

    a2->children.push_back(a21);

    serialize(a);

    cout<<seq<<endl;
    Node* root = NULL;
    myindex = 0;

    des(root, seq);

    Node * rootnew = deserialize(seq);

    seq = "";
    serialize(rootnew);
    cout<<seq<<endl;
}
