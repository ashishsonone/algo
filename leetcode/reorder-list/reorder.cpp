#include <iostream>
using namespace std;

#define DEBUG 1
#define IFBUG if(DEBUG==1){
#define ENDBUG }           

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode * head){
    ListNode * p = head;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void reorder(ListNode * head, ListNode * tail){
    IFBUG cout << "head " << head->val << endl;  ENDBUG
    IFBUG cout << "tail " << tail->val << endl; ENDBUG

    if(head == tail) return;
    if(head->next == tail) return;

    ListNode * headdash, *taildash;
    headdash = head->next;
    taildash = head->next;
    while(taildash->next != tail){
        taildash = taildash->next;
    }

    IFBUG cout << "headdash " << headdash->val << endl; ENDBUG
    IFBUG cout << "taildash " << taildash->val << endl; ENDBUG

    head->next = tail;
    tail->next = headdash;
    taildash->next = NULL;

    IFBUG print_list(head); ENDBUG
    reorder(headdash, taildash);
}

ListNode* findtail(ListNode * head){
    ListNode * tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail; 
}

void reorderList(ListNode *head) {
    if(head == NULL) return;
    ListNode * tail = findtail(head);
    IFBUG cout << "checking findtail " << tail->val << endl; ENDBUG
    reorder(head, tail);
}


int main(){
    ListNode * h = new ListNode(0);
    ListNode * n1 = new ListNode(1);
    h->next = n1;
    ListNode * n2 = new ListNode(2);
    n1->next = n2;

    n2->next = NULL;
    reorderList(h);
    IFBUG cout << "final list : "; ENDBUG
    IFBUG print_list(h); ENDBUG
    return 0;

    ListNode * n3 = new ListNode(3);
    n2->next = n3;
    ListNode * n4 = new ListNode(4);
    n3->next = n4;
    ListNode * n5 = new ListNode(5);
    n4->next = n5;
    ListNode * n6 = new ListNode(6);
    n5->next = n6;
    n6->next = NULL;

    IFBUG print_list(h); ENDBUG
    reorderList(h);
    IFBUG cout << "final list : "; ENDBUG
    IFBUG print_list(h); ENDBUG

}
