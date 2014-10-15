#include <iostream>
using namespace std;

void print_char(int count, char c){
    for(int i=0; i < count; i++){
        cout << c;
    }
}

void print_decent(int num){
    int num3 = 0 , num5 = 0;
    num3 = num % 3; 
    num5 = (num / 3) * 3;
    
    //cout << num3 << " " << num5 << endl;
    while(num3%5 != 0 && num5 >= 0){
        num5 -= 3;
        num3 += 3;
    }
    
    if(num3 % 5 != 0 || num5 < 0) {
        cout << -1 << endl;
        return;
    }
    
    print_char(num5, '5');
    print_char(num3, '3');
    cout << endl;
}
int main(){
    int T, num;
    cin >> T;
    for(int i=0; i< T; i++){
        cin >> num;
        print_decent(num);
    }
}
