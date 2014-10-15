#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

int eval(vector<string> &tokens, int &index){
    cout << index << endl;
    if(tokens[index].compare("*") == 0){
        index--;
        int r = eval(tokens, index);
        int l = eval(tokens, index);
        return l * r;
    }
    else if(tokens[index].compare("/") == 0){
        index--;
        int r = eval(tokens, index);
        int l = eval(tokens, index);
        return l / r;
    }
    else if(tokens[index].compare("+") == 0){
        index--;
        int r = eval(tokens, index);
        int l = eval(tokens, index);
        return l + r;
    }
    else if(tokens[index].compare("-") == 0){
        index--;
        int r = eval(tokens, index);
        int l = eval(tokens, index);
        return l - r;
    }
    else{
        int val = atoi(tokens[index].c_str());
        index--;
        return val;
    }
}
    
using namespace std;
int main(){
    vector<string> v;
    v.push_back("2");
    v.push_back("3");
    v.push_back("-");
    v.push_back("9");
    v.push_back("+");
    int index = v.size()-1;
    int ans = eval(v, index);
    cout << ans << endl;
}
