#include <iostream>
using namespace std;

#define MOD 1000000007

long long * store;

long long fact(long long num){
	long long ans = 1;
	while(num > 0){
		ans = (ans * num) % MOD;
		num--;
	}
	return ans;
}

int main(){
	int T;
	cin >> T;
	//cout << fact(T) << endl;
	//return 0;
	long long A[110][110];
	for(int i=0; i<110; i++){
		for(int j=0; j<110; j++){
			if(i==j) A[i][j] = fact(i);
			else if(j==1) A[i][j] = 1;
			else{
				A[i][j] = ( j * ((A[i-1][j-1] + A[i-1][j])%MOD) )%MOD;
			}
		}
	}
	
	for(int i=1;i<=T; i++){
		int M, N;
		cin >> M >> N;
		cout << "Case #" << i << ": " << A[N][M] << endl;
	}
}
