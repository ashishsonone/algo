#include <iostream>
#include <cstring>
using namespace std;


void reverse(char * str){
    char * end = str;
    char tmp;

    while(*end){
        end++;
    }

    end--;

    while(str < end){
        tmp = *str;
        *str = *end;
        *end = tmp;
        str++;
        end--;
    }
}

int main(){
    char * s = new char(100);
    strcpy(s, "hello");
    cout << s << endl;
    reverse(s);
    cout << s << endl;
}
