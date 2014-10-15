#include <stdio.h>
struct allocated_frame{
    struct allocated_frame * next;
    int val;
};
struct allocated_frame * HEAD;

struct allocated_frame* pop_free_allocated_frame(){
    struct allocated_frame* prev = NULL;
    struct allocated_frame* head = HEAD;

    while(head!=NULL){
        printf("in %d\n", head->val);
        if(head->val == 0){
            if(prev == NULL){
                HEAD = HEAD->next;
            }
            else {
                prev->next = head->next;
            }
            return head;
        }
        prev = head;
        head = head->next;
    }
    return NULL;
}

void print(struct allocated_frame* h){
    while(h != NULL){
        printf("%d,", h->val);
        h=h->next;
    }
    printf("\n");
}


int main(){
    struct allocated_frame * e1 = malloc(sizeof(struct allocated_frame));
    struct allocated_frame * e2 = malloc(sizeof(struct allocated_frame));
    struct allocated_frame * e3 = malloc(sizeof(struct allocated_frame));
    HEAD = e1;
    e1->val = 1;
    e2->val = 0;
    e3->val = 3;
    e1->next = e2;
    e2->next = e3;
    e3->next = NULL;
    print(HEAD);
    
    struct allocated_frame * pop = pop_free_allocated_frame();
    print(HEAD);
}
