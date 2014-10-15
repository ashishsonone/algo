#include <iostream>
#include <cstring>
using namespace std;

void replace(char * str){
    int len = strlen(str);
    int numspaces = 0;
    for(int i=0;i<len;i++){
        if(str[i]==' ') numspaces++;
    }

    int newlen = len + 2*numspaces;

    str[newlen] = 0;

    for(int i=len-1;i>=0;i--){
        if(str[i]==' '){
            str[newlen-1] = '0';
            str[newlen-2] = '2';
            str[newlen-3] = '%';
            newlen = newlen-3;
        }
        else{
            str[newlen-1] = str[i];
            newlen = newlen-1;
        }
    }
}

int main(){
    char str[100] = "hello world i am here";
    replace(str);
    cout << str << endl;
}
