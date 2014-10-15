#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

struct Token{
    string tok;
    int place;
    string value;
};

unordered_map<string, string> mapping = 
    {
        {"", ""},
        {"0", "zero"},
        {"1", "one"},
        {"2", "two"},
        {"3", "three"},
        {"4", "four"},
        {"5", "five"},
        {"6", "six"},
        {"7", "seven"},
        {"8", "eight"},
        {"9", "nine"},
        {"10", "ten"},
        {"11", "eleven"},
        {"12", "twelve"},
        {"13", "thirteen"},
        {"14", "fourteen"},
        {"15", "fifteen"},
        {"16", "sixteen"},
        {"17", "seventeen"},
        {"18", "eighteen"},
        {"19", "nineteen"},
        {"20", "twenty"},
        {"30", "thirty"},
        {"40", "forty"},
        {"50", "fifty"},
        {"60", "sixty"},
        {"70", "seventy"},
        {"80", "eighty"},
        {"90", "ninety"},
        {"*2", "hundred"},
        {"*3", "thousand"},
        {"*5", "lakh"},
        {"*7", "crore"},
    };

bool exists(string num){
    if(mapping.find(num) == mapping.end()) return false;
    return true;
}

string normalize(string input){
    int i;
    for(i=0; i<input.size(); i++){
        if(input[i] != '0') break;
    }
    return input.substr(i, input.size()-i+1);
}

void get_words(Token & token){
    string word = "";
    token.tok = normalize(token.tok);
    if(exists(token.tok)) word+= mapping[token.tok] + " ";
    else{
        //split into units and tens; its sure that it will be of length 2
        string tens = "00";
        tens[0] =token.tok[0];

        string units = "0";
        units[0] = token.tok[1];

        word += mapping[tens] + "-";
        word += mapping[units] + " ";
    }

    //now add word for place value if required;
    int place = token.place;
    if(place >1){
        char buf[5];
        sprintf(buf,"%d",place);
        string p = "*";
        p.append(buf);
        if(exists(p)) word+= mapping[p] + " ";
        else{
            cout << "word for place " << p << " does not exist in mapping" << endl;
        }
    }

    token.value = word;
}

list<Token> tokenize(string number){
    list<Token> tokens;
    int lastpos = number.size()-1;
    for(int i=lastpos; i>=0; i=i-2){
        Token t;
        t.place = lastpos-i;
        t.value = "";
        t.tok = "00";
        t.tok[1] = number[i]; //units digit of that token
        if(i!=lastpos-2 && i-1 >=0) {
            t.tok[0] = number[i-1]; //tens digit of token if present
        }

        tokens.push_front(t);

        if(i==lastpos-2) i++; //from hundred(2) to thousand place(3), instead of shifting left two places, we need to shift 1 place only
    }
    return tokens;
}

void apply(list<Token>& tokens, void (*f)(Token&)){
    for(list<Token>::iterator it=tokens.begin(); it != tokens.end(); it++){
        Token &t = *it;
        f(t);
    }
}

void print_debug(Token &t){
    cout << t.tok << ", " << t.place << ", " << t.value << endl;
}

void print(Token &t){
    cout << t.value ;
}


int main(){
    //char x[3];
    //sprintf(x,"%d",32);
    //cout << x << endl;
    //string str(x);
    //cout <<str << " " << str.size() << endl;
    //return 0;

    //Token t;
    //t.tok = "30";
    //t.place = 3;

    //get_words(t);
    //cout << t.value << endl;
    //return 0;
    string num;
    cout << "give a number : " ;
    cin >> num ;
    num = normalize(num);

    list<Token> tokens = tokenize(num);
    apply(tokens, get_words);
    apply(tokens, print);
    cout << endl;
}

