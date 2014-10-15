#include <iostream>
#include <string>
using namespace std;

bool B[26];
bool W[26];

void reset(){
    for(int i=0; i<26; i++){
        B[i] = false;
        W[i] = false;
    }
}

int main(){
    int T;
    int count;
    cin >> T;
    for(int i=0; i<T; i++){
        reset();
        count = 0;
        string broken, word;
        cin >> broken;
        cin >> word;
        for(int index=0; index<broken.size(); index++){
            int m = ((int)broken[index]) - 97;
            if(B[m] == false) B[m] = true;
        }
        for(int index=0; index<word.size(); index++){
            int m = ((int)word[index]) - 97;
            if(W[m] == false && B[m] == true) count++;
            W[m] = true;
        }
        cout << count << endl;
    }
}
