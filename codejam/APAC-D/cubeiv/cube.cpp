#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define BORDER -1

void print(int** maze, int size){
	for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
}


int ** maze;
int ** best;
int S;

int max(int a, int b){
	return a > b ? a : b;
}

int maxlen(int i, int j){
	if(best[i][j] != -1) return best[i][j];
	
	int cur = maze[i][j];
	int maximum = 1; //no extra travelling
	
	
	for(int x=-1; x <=1; x++){
		for(int y=-1; y<=1 ; y++){
			//cout << "maxlen1 " << i+x << " " << j+y << " " << maze[i+x][j+y] << "  cur+1 " << cur+1 <<endl;
			if(!(abs(x) == abs(y)) && maze[i+x][j+y] == cur+1){
				maximum = 1 + maxlen(i+x, j+y);
				//cout << "maxlen " << maximum << endl;
			}
		}
	}
	
	best[i][j] = maximum;
	return best[i][j];
}

int main(){
	int T;
	scanf("%d", &T);
	
	for(int tc=1; tc<=T; tc++){
		scanf("%d", &S);
		
		maze = new int*[S+2];
		for(int i=0; i<S+2; i++){
			maze[i] = new int[S+2];
		}
		
		//take input
		for(int i=1; i<S+1; i++){
			for(int j=1; j<S+1; j++){
				scanf("%d", &maze[i][j]);
			}
		}
		
		//init the borders
		for(int i=0; i<S+2; i++){
			maze[i][0] = BORDER; //left col
			maze[i][S+1] = BORDER;
		}
		
		for(int j=0; j<S+2; j++){
			maze[0][j] = BORDER; //left col
			maze[S+1][j] = BORDER;
		}
		
		//dp matrix
		best = new int*[S+2];
		for(int i=0; i<S+2; i++){
			best[i] = new int[S+2];
		}
		
		for(int i=0; i<S+2; i++){
			for(int j=0; j<S+2; j++){
				//scanf("%d", maze[i][j]);
				best[i][j] = -1;
			}
		}
		
		
		//print(maze, S+2);
		
		int besti=1, bestj=1, bestlen=-1;
		for(int i=1; i<S+1; i++){
			for(int j=1; j<S+1; j++){
				int t= maxlen(i, j);
				//cout << t << endl;
				if(t > bestlen){
					//cout << "yes " << t << " " << i << " " << j << endl;
					besti = i;
					bestj = j;
					bestlen = t;
				}
				else if(t == bestlen && maze[i][j] < maze[besti][bestj]){
					//cout << "rep " << t <<  " " << i << " " << j << endl;
					besti = i;
					bestj = j;
					bestlen = t;
				}
				else{
					//cout << "no " << t << " " <<i << " " << j << endl;
				}
			}
		}
		printf("Case #%d: %d %d\n", tc, maze[besti][bestj], bestlen);
		//cout << maze[besti][bestj] << " "  << bestlen << endl; 
	}
}
