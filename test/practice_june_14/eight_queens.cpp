#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

static int Count = 0;

int column_for_row[8];

void printRow(int Q){
    int i=0;
    for(; i< Q;i++){
        cout << "_ ";
    }
    cout << "Q ";
    i++;
    for(; i< 8;i++){
        cout << "_ ";
    }
    cout << endl;
}

void printBoard(){
    cout << "Arrangement " << Count++ << ": " << endl;
    for(int i=0;i<8;i++) 
        printRow(column_for_row[i]);
}

bool check_row(int row){
    for(int i=0; i< row; i++){
        int distance = abs(column_for_row[row] - column_for_row[i]);
        if(distance == 0 || distance == row-i) return false;
    }
    return true;
}

void place(int row){
    //cout << "row  " << row << endl;
    if(row == 8){//we go from 0 - 7. When row=8 we're done
        printBoard();
        return;
    }

    for(int i=0; i< 8; i++){
        column_for_row[row] = i;
        if(check_row(row)){
            //cout << " yes" << row << " " << i << endl;
            place(row+1);
        }
        else{
            //cout << "no" <<endl;
        }
    }
}


int main(){
    for(int i=0;i<8;i++){
        column_for_row[i] = -1;
    }
    place(0);
}

