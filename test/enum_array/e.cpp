#include <iostream>
using namespace std;

typedef enum{
    a = 0,
    b = 1,
    c = 2
} alpha;

int main(){
    bool status[3];
    status[b] = false;
    cout << status[b]  <<endl;
}
