class Solution {
public:
    int eat(string &s, int curr){//eats spaces
        while(curr >= 0 && s[curr] == ' '){
            curr--;
        }
        return curr;
    }

    int find_start(string &s, int curr){
        while(curr >=0 && s[curr] != ' '){
            curr--;
        }
        return curr+1;
    }

    void reverseWords(string &s) {
        //char * str = new char[s.size()+1];
        string str;
    
        int index = 0;
        int x = eat(s, s.size()-1);
        int y;
        while(x >= 0){
            y = find_start(s, x-1);
            //cout << s[y] << "..." << s[x] << " - " <<  "[" << y << "," << x << "]" << endl;
            for(int i=y; i<=x; i++){
                str.push_back(s[i]);
            }
            str.push_back(' ');
            x = eat(s, y-1);
        }
        if(str.size() > 0){
            str.pop_back();
        }
        s = str;
        //cout << str << endl;
    }
};
