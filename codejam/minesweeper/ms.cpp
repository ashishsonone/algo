#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


typedef struct cell_t{
	int count;
	char c;
	bool revealed;
	bool recursed;
	cell_t(){
		count = 0;
		c = '#';
		revealed = false;
		recursed = false;
	}
}cell_t;

cell_t ** board; //global

void print(cell_t ** B, int N){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << B[i][j].c;
		}
		cout << endl;
	}
}
void print_c(cell_t ** B, int N){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << B[i][j].count << " ";
		}
		cout << endl;
	}
}

bool is_mine(cell_t cell){
	return (cell.c == '*');
}

bool is_valid(cell_t cell){
	return (cell.c == '.');
}

void count_mines(cell_t ** B, int i, int j){
	int count;
	if(!is_valid(B[i][j])){
		count = -1;
	}
	else{	
		count = is_mine(B[i-1][j-1]) + is_mine(B[i-1][j]) + is_mine(B[i-1][j+1]) + 
				is_mine(B[i][j-1]) + is_mine(B[i][j+1]) + 
				is_mine(B[i+1][j-1]) + is_mine(B[i+1][j]) + is_mine(B[i+1][j+1]) ;
	}
	
	B[i][j].count = count;
}

void sweep(int i, int j){
	if(!is_valid(board[i][j])) return; //if a mine or side cell just return
	
	if(board[i][j].recursed) return; //if already recursed
	
	if(!board[i][j].revealed){
		//cout << "rev " << i << " " << j << endl;
		board[i][j].revealed= true;
	}
	//now recurse if its a 0
	if(board[i][j].count != 0) return;
	
	board[i][j].recursed = true; //setting this is important as internal recursion might trigger this also
	
	for(int a=i-1; a<=i+1; a++){
		for(int b=j-1; b<=j+1; b++){
			if(!(i==a && j==b)){
				sweep(a, b);
			}
		}
	}
	
}

int main(){
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		int N;
		cin >> N;
		board = new cell_t*[N+2]; //boundary of mines
		int sweep_calls = 0; //no of unique zero sweeps
		
		for(int i=0; i<N+2; i++){
			board[i] = new cell_t[N+2];
		}
		int validcells = 0;
		for(int i=1; i<=N; i++){
			string row;
			cin >> row;
			for(int j=1; j<=N; j++){
				board[i][j].c = row[j-1];
				if(row[j-1] == '.') validcells++;
			}
		}
		//print(board, N);
		
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				count_mines(board, i, j);
			}
		}
		//print_c(board , N);
		
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(is_valid(board[i][j]) && board[i][j].count == 0 && board[i][j].revealed == false){
					//cout <<"SWEEP" << endl;
					sweep(i, j);
					sweep_calls++;
				}
			}
		}
		
		
		int number_orphans = 0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(is_valid(board[i][j]) && board[i][j].count > 0 && board[i][j].revealed == false){
					number_orphans++;
				}
			}
		}
		
		//cout << sweep_calls <<  "+" << number_orphans << endl;
		printf("Case #%d: %d\n", tc, sweep_calls+number_orphans);
		
		for(int i=0; i<N+2; i++){
			delete[] board[i];
		}
	}
}
