#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

#define MOD 1000000009
using namespace std;
typedef struct color_t{
	int p;
	char c;
} color_t;

bool compare(color_t a, color_t b){
	return a.p < b.p;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N, M;
		scanf("%d", &N);
		scanf("%d", &M);
		color_t A[M];
		for(int i=0; i<M; i++){
			scanf(" %c", &A[i].c);
			scanf("%d", &A[i].p);
			//cout << (unsigned int)A[i].c << " " << A[i].p <<endl;
		}
		//cout << " ***** "  <<  endl;
		sort(A, A+M, compare);
		/*for(int i=0; i<M; i++){
			cout << A[i].p << endl;
		}*/
		
		long long count = 1;
		int cur = 0;
		int next = 1;
		while(true){
			while(next < M){
				if(A[next].c != A[cur].c) break;
				cur = next;
				next++;
			}
			//cout << cur << " " << next << " " << (unsigned int) A[cur].c << " "<< A[cur].p << endl;
			if(next == M) break;
			int cases = A[next].p - A[cur].p;
			//cout << cases << endl;
			count = (count * cases) % MOD;
			cur = next;
			next++;
		}
		int count_i = count;
		printf("%d\n", count_i);
	}
}
