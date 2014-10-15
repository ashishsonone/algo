#include <iostream>
#include <vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode * head = NULL;
    ListNode * curr = head;
    while(true){
        int mini = -1;
        
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                if(mini == -1){ //first time coming
                    mini = i;  
                }
                else if(lists[i]->val < lists[mini]->val){
                    mini = i;
                }
            }
        }
        //cout << "found the min "  <<endl;
        //found the min
        if(mini == -1) break;
        if(head == NULL) {
            head = lists[mini];
            curr = head;
            //cout << "head is NULL " << curr->val << endl;
            lists[mini] = lists[mini]->next;
        }
        else{
            curr->next = lists[mini];
            lists[mini] = lists[mini]->next;
            curr = curr->next;
            //cout << "head is NONNULL " << curr->val << endl;
        }
    }
    return head;
}

ListNode * input(){
    int N;
    cin >> N;
    ListNode * head = NULL;
    if(N == 0) return head;
    int v;
    cin >> v;
    head = new ListNode(v);
    ListNode * curr = head;
    
    for(int i=1; i<N; i++){
        cin >> v;
        ListNode * temp = new ListNode(v);
        curr->next = temp;
        curr = curr->next;
    }
    return head;
}

void print(ListNode * head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    /*
    int *a = NULL;
    int *&b = a;

    a = new int;
    *a = 2;
    cout << (*b) <<endl;
    vector<int*> v;
    v.push_back(a);

    int *&c = v[0];
    cout << (*c) <<endl;

    int *d = new int(3);
    c = d;
    cout << *v[0] << endl;
    */
    vector<ListNode*> lists;
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        ListNode * l = input();
        print(l);
        lists.push_back(l);
    }
    
    ListNode *min = mergeKLists(lists);
    print(min);
    
    
}
