#include <iostream>
#include <string>
using namespace std;

int start, end;
string s;
    
    
    bool isAN(char c){
        //cout << (int) c << endl;
        if((c >= 48 && c <=57) || (c >= 65 && c <=90) || (c >= 97 && c<=122)) return true;
        return false;
    }
    
    char normalize(char c){
        if(c >= 65 && c <=90) c += 32;
        return c;
    }
    
    bool compare(char a, char b){
        if(normalize(a) == normalize(b)) return true;
        return false;
    }
    
    int next(){
        int i;
        for(i=start; i<s.size(); i++){
            if(isAN(s[i])) break;
        }
        return i;
    }
    
    int prev(){
        int i;
        for(i=end; i>=0; i--){
            if(isAN(s[i])) break;
        }
        return i;
    }
    bool isPalindrome(string str) {
        if(str.empty()) return true;
        s = str;
        start = 0; end = str.length()-1;
        while(true){
            start = next();
            end = prev();
            
            if(start > end) return true;
            //cout << s[start] << " " << s[end] << endl;
            if(!compare(s[start], s[end])) return false;
            
            start++;
            end--;
        }
    }
    
    int main(){
        char c;
        cin >> c;
        cout << "isAN " << c << " " << isAN(c) << endl;
        cout << "normalized " << c << " " << normalize(c) << endl;
        
        string str = "A man, a plan, a canal: Panama";
        cout << str << " " << endl;
        cout << isPalindrome(str);
    }
