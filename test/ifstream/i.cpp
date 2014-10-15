#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream infile;
    infile.open("c.txt");
    int op;
    int id;
    char msg[100];
    while(infile.good()){
        infile>> op;
        if(op == 1){
            infile>>id;
            infile.getline(msg, 100);
            cout << "op " << op << " id "<< id << "msg: " << msg << endl;
        }
        else if(op == 0){
            cout << "op " << op << endl;
        }
        op = -1;
    }
    
    infile.close();
}
