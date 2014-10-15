#include <iostream>
#include <string>

using namespace std;

void allparen(int l, int r, string s){
    if(l > 0) allparen(l-1, r, s + "(");
    if(r > l) allparen(l, r-1, s + ")");
    if( l == 0 && r == 0) cout << s << endl;
}

int main(){
    string s = "";
    allparen(3,3,s);
}
