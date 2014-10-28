#include <bits/stdc++.h>

using namespace std;

typedef struct point_t{
	int val;
	bool done;
	point_t(){
		val = 0;
		done = false;
	}
}point_t;

typedef struct direction_t{
	int x;
	int y;
	direction_t operator+(direction_t &d){
		direction_t ret;
		ret.x = x + d.x;
		ret.y = y + d.y;
		return ret;
	}
	void print(){
		printf("[%d, %d]\n", x, y);
	}
} direction_t;

direction_t dir[4];

int main(){
	
	dir[0].x = 0;
	dir[0].y = 1;
	
	dir[1].x = 1;
	dir[1].y = 0;
	
	dir[2].x = 0;
	dir[2].y = -1;
	
	dir[3].x = -1;
	dir[3].y = 0;
	
	int N, M; //n rows, m colums
	
	cin >> N >> M ;
	point_t A[N+2][M+2];
	
	for(int j=0; j<M+2; j++){
		A[0][j].done = true;
		A[N+1][j].done = true;
	}
	for(int i=0; i<N+2; i++){
		A[i][0].done = true;
		A[i][M+1].done = true;
	}
	
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			cin >> A[i][j].val;
		}
	}
	direction_t cur;
	cur.x = 1;
	cur.y = 1;
	
	int dindex = 0;
	
	dir[dindex].print();
	
	while(true){
		cout << A[cur.x][cur.y].val << " ";
		A[cur.x][cur.y].done = true;
		
		direction_t tempcur = cur + dir[dindex];
		if(A[tempcur.x][tempcur.y].done == true){ //already visited. change direction(turn right from cur)
			dindex = (dindex+1)%4;
			
			tempcur = cur + dir[dindex]; //turned right now check this
			
			if(A[tempcur.x][tempcur.y].done == true) break; //no more to visit
		}
		
		cur = tempcur;
	}
	
}
