#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int search(char c, map<char, int> m)
{
    for(char s = c+1; s<='z'; s++)
    {
        map<char, int>::iterator it = m.find(s);
        if (it!=m.end())
            return it->second;
    }
    return -1;
}

string swap(string r, int i, int j)
{
    string s = r;
    char a = s[i];
    s[i] = s[j];
    s[j] = a;
    
    int size = s.size();
    
    for(int k=0; k< (size-i-1)/2; k++){
		char temp = s[size - 1- k]; 
		s[size - 1 - k] = s[i+1+k];
		s[i+1+k] = temp;
	}
    return s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        map<char, int> m;
        int find;
        bool c=false;
        for(int i= s.length()-1;i>=0;i--)
        {
            find = search(s[i], m);
            if (find!=-1) {
                cout << swap(s, i, find) << endl;
                c=true;
                break;
            }
                pair<char, int> p;
                p.first = s[i];
                p.second = i;
                m.insert(p);
        }
        if(!c)
            cout << "no answer"<<endl;
    }
    return 0;
}
