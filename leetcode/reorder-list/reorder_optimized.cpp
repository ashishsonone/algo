#include <iostream>
#include <vector>
using namespace std;

#define DEBUG 0
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


ListNode * findMid(ListNode * head){
    //At the end, slow shoudl point to end to first half list
    ListNode * ghost = new ListNode(-1); //to keep slow 1 step behind
    ghost->next = head;

    ListNode * slow = ghost;
    ListNode * fast = head;
    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL && fast->next == NULL) slow = slow->next;

    IFBUG cout << "slow " << slow->val << endl; ENDBUG
    return slow;
}

ListNode * merge(ListNode *head1, ListNode * head2){
    ListNode * mergehead = head1;
    ListNode * curr = mergehead;
    head1 = head1->next;
    bool first = false;
    while(head1 != NULL || head2 != NULL){
        if(first){
            first = false;
            if(head1 != NULL){
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
        }
        else{
            first = true;
            if(head2 != NULL){
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }
    }

    IFBUG print_list(mergehead); ENDBUG
    return mergehead;
}

ListNode * reverse(ListNode * head){
    if(head == NULL) return head;
    if(head->next == NULL) return head;

    ListNode * prev = NULL;
    ListNode * curr = head;
    ListNode * temp;

    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    //print_list(prev);
    return prev;
}

void reorderList(ListNode *head){
    if(head == NULL) return;
    if(head->next == NULL) return;
    if(head->next->next == NULL) return; //upto 2 nodes

    ListNode * mid = findMid(head); //end of first half
    IFBUG cout << "mid->val " << mid->val << endl; ENDBUG

    ListNode * head2 = mid->next;
    IFBUG cout << "head2->val " << head2->val << endl; ENDBUG

    mid->next = NULL; //this makes first half a list(end poiting to NULL).
    //Now we have 2 lists : head and head2
    
    IFBUG cout<< "printing two lists" << endl; ENDBUG
    IFBUG print_list(head); ENDBUG
    IFBUG print_list(head2); ENDBUG

    //Reverse second list
    head2 = reverse(head2);
    IFBUG cout << "reversed second list : "; ENDBUG
    IFBUG print_list(head2); ENDBUG

    IFBUG cout << "merging : " << endl; ENDBUG
    head = merge(head, head2);
}

ListNode * input_list(){
    int n, val;
    cin >> n;
    if(n==0) return NULL;
    ListNode * head, *temp;
    cin >> val;
    head = new ListNode(val);
    temp = head;

    for(int i=1; i<n; i++){
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    return head;
}


int main(){

    ListNode * h = input_list();

    IFBUG print_list(h); ENDBUG

    reorderList(h);
    IFBUG cout << "final list : "; ENDBUG
    print_list(h); 

}
