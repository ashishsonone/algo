#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode * head){
    cout << "L : ";
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode * input_list(){
    ListNode * head = NULL, *curr;
    int n, val;
    cin >> n;
    if(n == 0) return head; 

    //atleast one node. So input head
    cin >> val;
    head = new ListNode(val);

    curr = head;

    for(int i=1; i<n; i++){
        cin >> val;
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return head;
}

ListNode * merge(ListNode *h1, ListNode *h2){
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    ListNode * mergehead;
    if(h1->val < h2->val){
        mergehead = h1;
        h1 = h1->next;
    }
    else{
        mergehead = h2;
        h2 = h2->next;
    }

    ListNode * curr = mergehead;

    while(h1 != NULL ||  h2 != NULL){
        if(h1 == NULL){
            curr->next = h2;
            break;
        }
        else if(h2 == NULL){
            curr->next = h1;
            break;
        }
        else if(h1->val < h2->val){
            curr->next = h1;
            curr = curr->next;
            h1 = h1->next;
        }
        else{
            curr->next = h2;
            curr = curr->next;
            h2 = h2->next;
        }
    }
    return mergehead;
}

ListNode * split(ListNode *head){ //gives head of second half list, while appending NULL to first half
    //head won't be null. Atleast one node
    if(head->next == NULL) return NULL;
    ListNode * fast = head->next, *slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *h2 = slow->next;
    slow->next = NULL;
    return h2;
}

int main(){
    ListNode *l1 = input_list();
    ListNode *l2 = input_list();
    print_list(l1);
    print_list(l2);
    ListNode * m = merge(l1, l2);
    print_list(m);

    ListNode* br = split(m);
    print_list(m);
    print_list(br);
}
 
