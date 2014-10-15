#include <iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    int len(ListNode *head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    
    void loop(ListNode *head){
        ListNode * curr = head;
        if(curr == NULL) return;
        
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;
    }
    
    ListNode *rotateRight(ListNode *head, int k) {
        int l = len(head);
        //cout << l << endl;
        if(l == 0) return head;
        
        loop(head);
        
        //cout << "looped" << endl;
        k = k % l; //take modulo
        //cout << "k " << k << endl;
        ListNode * curr = head;
        for(int i=1; i< (l-k); i++){ //l-k-1 times
            curr = curr->next;
        }
        ListNode* headnew = curr->next;
        curr->next = NULL;
        return headnew;
    }
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

int main(){
    int x = -6, y = 4;
    cout << x/y << endl;
    ListNode * h = input_list();
    
    print_list(h);
    Solution S;
    h = S.rotateRight(h, 0);
    print_list(h);
}
