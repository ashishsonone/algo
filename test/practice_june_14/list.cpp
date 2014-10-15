#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    Node * next;
    int val;
    Node(int x){
        next = NULL;
        val = x;
    }
};


void push(Node * & head, int x){
    Node * entry = new Node(x);
    if(head == NULL){
        head = entry;
        return;
    }
    Node * curr = head;
    while(curr->next != NULL) curr = curr->next;

    curr->next = entry;
}

void print(Node * head){
    cout << "LL : " ;
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void remove(Node *& head, int x){
    if(head == NULL) return;
    if(head->val == x) head = head->next;

    Node * curr = head;
    while(curr->next!=NULL){
        if(curr->next->val == x){
            curr->next = curr->next->next;
            return;
        }
        curr = curr->next;
    }
}

Node * nth_to_last(Node * head, int n){
    if(n<1) {
        cout << "n is < 1" << endl;
        return NULL;
    }
    Node * aage = head;
    Node * peeche = head;

    int i;
    for(i=0; i<n-1 ; i++){
        if(peeche == NULL){ 
            cout << "1) list size is smaller than given n " << n << endl;
            return NULL;
        }
        peeche = peeche->next;
    }

    if(peeche == NULL){
        cout << "2) list size is smaller than given n " << n << endl;
        return NULL;
    }

    while(peeche->next != NULL){
        peeche = peeche->next;
        aage = aage->next;
    }
    return aage;
}

Node * add(Node *n1, Node *n2, int carry){
    //cout << "rec " ;print(n1); print(n2);
    if(n1 == NULL && n2 == NULL){
        return NULL;
    }
    int val = carry;
    
    if(n1 != NULL) val+=n1->val;
    if(n2 != NULL) val+=n2->val;

    Node * ret = new Node(val);

    Node * rem = add(n1 ==NULL ? NULL : n1->next,
                    n2 == NULL ? NULL : n2->next,
                    val > 10 ? 1 : 0);
    ret->next = rem;
}

int main(){
    Node * LL = NULL;
    push(LL, 2);
    push(LL, 1);
    print(LL);
    Node * n = nth_to_last(LL, 3);
    if(n!=NULL) cout << "found " << n->val << endl;


    Node *N1 = NULL;
    Node *N2 = NULL;
    push(N1, 1);
    push(N1, 2);
    push(N2, 3);
    print(N1);
    cout << "+\n";
    print(N2);
    cout << "=\n";
    print(add(N1,N2,0));
}

