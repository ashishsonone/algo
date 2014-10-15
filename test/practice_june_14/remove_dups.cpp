#include <iostream>
#include <cstring>
using namespace std;

void remove_dups(char * str){
    bool check[256];
    for(int i=0;i<256;i++){
        check[i] = false;
    }
    if(str == NULL) return;

    int tail = 0;
    for(int i=0;i<strlen(str);i++){
        if(!check[(int)str[i]]){
            str[tail] = str[i];
            tail++;
        }
        check[(int)str[i]] = true;
    }
    str[tail] = 0;
}

int main(){
    char str[] = "aaaaabbbb";
    remove_dups(str);
    cout << str << endl;
}
