#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <list>
#include <utility>
using namespace std;

static int Event = 0;

struct Node{
    int val;
    Node * lc;
    Node * rc;
    Node * sibling;
    Node(int x){
        val = x;
        lc = NULL;
        rc = NULL;
        sibling = NULL;
    }
    Node(int x, Node *l, Node *r){
        val = x;
        lc = l;
        rc = r;
        sibling = NULL;
    }
};

typedef pair<Node*, Node*> Nodepair;
/*********************/
void connect_list(list<Node*> * l){
    if(l->empty()) return;
    list<Node*>::iterator it = l->begin();
    Node * prev, *next;
    prev = *it;
    it++;
    for(;it!=l->end(); it++){
        next = *it;
        prev->sibling = next;
        prev = next;
    }
    prev->sibling = NULL;
}

void print_siblings(Node *n){
    while(n!= NULL){
        cout << n->val << " ";
        n = n->sibling;
    }
    cout << endl;
}

void connect_siblings(Node *root){
    list<Node*> *q1 = new list<Node*>();
    list<Node*> *q2 = new list<Node*>();

    if(root == NULL) return;

    root->sibling = NULL;
    q1->push_back(root);

    while(!q1->empty()){
        while(!q1->empty()){
            Node * n = q1->front();
            q1->pop_front();
            if(n->lc) q2->push_back(n->lc);
            if(n->rc) q2->push_back(n->rc);
        }
        connect_list(q2);
        list<Node *> * temp = q1;
        q1 = q2;//q1 now contains next level of parents
        q2 = temp; //now q2 is empty; ready to contain next set of children
    }
}
/*********************/

Nodepair get_next_sibling(Node * parent){//parent level has already been connected by sibling
    Nodepair P;
    P.first = NULL;
    P.second = NULL;

    Node * temp = parent->sibling;
    while(temp != NULL){
        if(temp->lc){
            P.first = temp;
            P.second = temp->lc;
            return P;
        }
        if(temp->rc){
            P.first = temp;
            P.second = temp->rc;
            return P;
        }
        temp = temp->sibling;
    }
    return P;
}

void connect_siblings_constant(Node *root){
    if(root == NULL) return;
    root->sibling = NULL;

    Node * parent = root;
    Node * child, *futurechild, *futureparent;

    futureparent = root;
    if(root->lc) futurechild = root->lc;
    else if(root->lc) futurechild = root->rc;
    else return; //we are done

    while(futurechild != NULL){
        cout << "outer " << futurechild->val <<endl;
        child = futurechild;
        parent = futureparent;

        futurechild = NULL;
        futureparent = NULL;
        while(child != NULL){
            cout << "inner " << child->val <<endl;
            if(futurechild == NULL){
                if(child->lc) {
                    futurechild = child->lc;
                    futureparent = child;
                    cout << "new futurechild " << futurechild->val <<endl;
                }
                else if(child->rc) {
                    futurechild = child->rc;
                    futureparent = child;
                    cout << "new futurechild " << futurechild->val <<endl;
                }
            }

            if(parent->rc != NULL && parent->rc != child){
                child->sibling = parent->rc;
                child = parent->rc;
                cout << "Event 1: " << Event++  <<" : " << (child ? child->val : -1) << endl;
                //parent remains the same
            }
            else{
                Nodepair P = get_next_sibling(parent);
                child->sibling = P.second;

                child = P.second;
                parent = P.first;
                cout << "Event 2 " << Event++ <<" : "  << (child ? child->val : -1) << endl;
            }
        }
    }
}

/*************************/

int get_height(Node *n){
    if(n == NULL) return 0;
    int lh = get_height(n->lc);
    int rh = get_height(n->rc);
    if(lh == -1 or rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;
    return lh > rh ? lh+1 : rh+1;
}

void print(vector<int> buffer, int a, int b){
    for(int i=a; i<=b; i++){
        cout << buffer[i] << " ";
    }
    cout << endl;
}

void findsum(Node *head, int sum, vector<int> buffer, int level){
    if(head == NULL) return;

    int tmp = sum;
    buffer.push_back(head->val);
    for(int i=level; i>-1; i--){
        tmp -= buffer[i];
        if(tmp == 0) print(buffer, i, level);
    }

    findsum(head->lc, sum, buffer, level+1);
    findsum(head->rc, sum, buffer, level+1);
}


int main(){
    Node * a = new Node(2);
    Node * b = new Node(4);
    Node * c = new Node(1);
    Node * d = new Node(6);
    Node * e = new Node(12);
    Node * f = new Node(5);
    Node * g = new Node(2);

    a->lc = b;
    a->rc = c;

    b->lc = d;
    d->lc = e;
    
    c->rc = f;
    b->rc = g;

    cout << "isbalanced " << get_height(a) << endl;

    vector<int> B;
    findsum(a, 6, B, 0);
    
    cout << "Connect Siblings " << endl;

    connect_siblings_constant(a);

    print_siblings(a);
    print_siblings(b);
    print_siblings(d);
    print_siblings(e);
}
