#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

bool ispiece(char c){
	if(c != '#' && c!='0') return true;
	return false;
}

void print(char ** board){
	for(int i=0; i<12; i++){
			for(int j=0; j<12; j++){
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << endl;
}

int main(){
	int T;
	scanf("%d", &T);
	char ** board = new char*[8+4];
		for(int i=0; i<8+4; i++){
		board[i] = new char[8+4];
	}
		
	for(int tc=1; tc<=T; tc++){
		int N;
		scanf("%d",&N);
		//cout << " N " << N << endl;
		
		//empty board
		for(int i=0; i<12; i++){
			for(int j=0; j<12; j++){
				board[i][j] = '0';
			}
		}
		
		//boundary
		for(int i=0; i<12; i++){
			board[0][i] = '#';
			board[1][i] = '#';
			board[10][i] = '#';
			board[11][i] = '#';
			
			board[i][0] = '#';
			board[i][1]= '#';
			board[i][10] = '#';
			board[i][11]= '#';
		}
		
		for(int i=0; i<N; i++){
			string s;
			cin >> s;
			char row = s[0];
			char piece = s[3];
			char column = s[1];
			//cout << row << piece << " " << column << endl;
			int r, c;
			r = row - 'A' + 2;
			c = column - '1' + 2;
			//cout << "piece " << r << " " << c << endl;
			board[r][c] = piece;
		}
		
		//print(board);
		
		int totalcount = 0;
		
		//go to all non-empty pieces
		for(int i=2; i<10; i++){
			for(int j=2; j<10; j++){
				if(board[i][j] != '0'){
					//which piece
					if(board[i][j] == 'P'){
						if(ispiece(board[i+1][j+1])){
							totalcount++;
						}
						if(ispiece(board[i+1][j-1])){
							totalcount++;
						}
					}
					
					if(board[i][j] == 'K'){
						for(int x=-1; x<=1; x++){
							for(int y=-1; y<=1; y++){
								if(!(x==0 && y==0)){
									if(ispiece(board[i+x][j+y])){
										totalcount++;
									}
								}
							}
						}
					}
					
					if(board[i][j] == 'R'){
						for(int x=-1; x<=1; x++){
							for(int y=-1; y<=1; y++){
								if(!(abs(x)==abs(y))){
									//travel
									int cx = i+x, cy=i+y;
									while(board[cx][cy]=='0'){
										cx = cx+x;
										cy = cy+y;
									}
									if(ispiece(board[cx][cy])){
										totalcount++;
									}
								}
							}
						}
					}
					
					if(board[i][j] == 'B'){
						for(int x=-1; x<=1; x++){
							for(int y=-1; y<=1; y++){
								if(abs(x)==abs(y) && abs(x) != 0){
									//travel
									int cx = i+x, cy=i+y;
									while(board[cx][cy]=='0'){
										cx = cx+x;
										cy = cy+y;
									}
									if(ispiece(board[cx][cy])){
										totalcount++;
									}
								}
							}
						}
					}
					
					if(board[i][j] == 'Q'){
						for(int x=-1; x<=1; x++){
							for(int y=-1; y<=1; y++){
								if(!(x==0 && y==0)){
									//cout << x << " " << y << endl;
									//travel
									int cx = i+x, cy=i+y;
									while(board[cx][cy]=='0'){
										cx = cx+x;
										cy = cy+y;
									}
									//cout << "########" << cx << " " << cy << " " << board[cx][cy] << endl;
									
									if(ispiece(board[cx][cy])){
										totalcount++;
									}
								}
							}
						}
					}
					
					if(board[i][j] == 'N'){
						if(ispiece(board[i+2][j+1])) totalcount++;
						if(ispiece(board[i+2][j-1])) totalcount++;
						if(ispiece(board[i-2][j+1])) totalcount++;
						if(ispiece(board[i-2][j-1])) totalcount++;
						
						if(ispiece(board[i+1][j+2])) totalcount++;
						if(ispiece(board[i-1][j+2])) totalcount++;
						if(ispiece(board[i+1][j-2])) totalcount++;
						if(ispiece(board[i-1][j-2])) totalcount++;
					}
				}
			}
		}
		
		printf("Case #%d: %d\n", tc, totalcount);
	}
}
