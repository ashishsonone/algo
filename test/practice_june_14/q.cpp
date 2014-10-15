#include <iostream>
using namespace std;
#define MAX 100

struct Queue{
    int array[MAX];
    int head, tail;

    Queue(){
        head = 0;
        tail = 0;
    }

    bool empty(){
        if(head == tail) return true;
        return false;
    }

    bool full(){
        if((tail + 1) % MAX == head) return true;
        return false;
    }

    void enqueue(int x){
        if(!full()){
            array[tail] = x;
            tail = (tail+1)%MAX;
 //           cout << "head : " << head << "tail : "<< tail << endl;
        }
        else{
            cout << "Queue overflow" <<endl;
        }
    }

    int dequeue(){
        if(!empty()){
            int temp = head;
            head = (head + 1)%MAX;
//            cout << "head : " << head << "tail : "<< tail << endl;
            return array[temp];
        }
        cout << "Queue underflow" <<endl;
    }
};


int main(){
    Queue S;
    S.enqueue(2);
    S.enqueue(6);
    S.enqueue(-6);
    cout << S.dequeue() << endl;
    cout << S.dequeue() << endl;
    S.enqueue(33);
    cout << S.dequeue() << endl;
    S.enqueue(2);
    S.enqueue(6);
    S.enqueue(-6);
    cout << S.dequeue() << endl;

}
