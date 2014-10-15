#include <iostream>
using namespace std;
#define MOD 1000000007

long long * store_g_one;
long long * store_fcom;
long long * store_f;
long long * store_g;

long long f(long long N, long long M);
//**************
long long mod(long long num){
	long long ans = num % MOD;
	if(ans < 0 ) ans = ans + MOD;
	return ans;
}

long long g_one(int M){
	if(M < 0) return 0;
	if(store_g_one[M] != -1) return store_g_one[M];
	
	long ans = 0;
	ans = mod(ans + g_one(M-1));
	ans = mod(ans + g_one(M-2));
	ans = mod(ans + g_one(M-3));
	ans = mod(ans + g_one(M-4));
	store_g_one[M] = ans;
	return ans;
}

long long power(long long base, long long exp){
	//cout << "into power" << endl;
	if(exp == 0) return 1;
	if(exp == 1) return mod(base);
	
	long long left = power(base, exp/2);
	long long right;
	if(exp % 2 == 0){
		right = left;
	}
	else{
		right = mod(left * base);
	}
	long long ans = mod(left * right);
	//cout << "power out" << endl;
	return ans;
}

long long g(long long N,long long M){
	//cout  << "here g" << endl;
	if(store_g[M] != -1) return store_g[M];
	long long ans = power(g_one(M), N);
	store_g[M] = ans;
	return store_g[M];
}

long long fcom(long long N,long long M){ //there exists atleast one slicing vertical
	if(store_fcom[M] != -1) return store_fcom[M];
	
	long long ans = 0;
	for(int i=1; i<= M-1; i++){ //first vertical slice at i
		ans = mod(ans + mod(f(N, i) * g(N, M-i)));
	}
	//cout << ans << endl;
	store_fcom[M] = ans;
	return store_fcom[M];
}

long long f(long long N, long long M){
	if(store_f[M] != -1) return store_f[M];
	long long total = mod(g(N, M) - fcom(N, M));
	store_f[M] = total;
	return store_f[M];
}

void init(int N, int M){
	store_g_one = new long long[M+1];
	store_fcom = new long long[M+1];
	store_f = new long long[M+1];
	store_g = new long long[M+1];
	
	for(int i=0; i<M+1; i++){
		store_g_one[i] = -1;
		store_f[i] = -1;
		store_fcom[i] = -1;
		store_g[i] = -1;
	}
	store_g_one[0] = 1; //base for g_one
	store_f[1] = 1;
	store_fcom[1] = 0;
}

int main(){
	int T;
	cin >> T;
	//cout<< mod(T) << endl;
	//return 0;
	while(T--){
		int N, M;
		cin >> N >> M;
		init(N, M);
		cout << f(N, M) << endl;
		
		delete[] store_g_one;
		delete[] store_fcom;
		delete[] store_f;
		delete[] store_g;
	}
}
