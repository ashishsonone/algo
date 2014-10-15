#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector<int> factors;
int sqrtX;
int X;
int working[10];
int * store; //store how many keystokes needed to express this (without the final '=')
			 //the DP part
			 //10000 if can't be expressed just so we discard it

int is_valid(int X){ //returns how many digits in number if valid. else returns 0
	char str[30];
	sprintf(str, "%d", X);
	for(int i=0; i<strlen(str); i++){
		if(working[str[i]-48] == 0) return 0;
	}
	return strlen(str);
}

void fill_factors(){
	for(int i=2; i<=sqrtX; i++){
		if(X % i == 0 && is_valid(i) > 0){ //push only those factors > 1 upto sqrtX which can be expressed using broken keys
			factors.push_back(i);
		}
	}
}

int min_keystrokes(int N){
	if(store[N] != -1) return store[N];
	int min = 10000;
	if(is_valid(N) > 0) min = is_valid(N);
	for(int i=0; i<factors.size(); i++){
		int f = factors[i];
		if(f > (int)sqrt(N+1)) break;
		
		if(N % f != 0) break;//its not a factor
		
		//now it is factor.
		int cf = N/f; //complement factor
		//cost is #digits in f + 1(for *) + min_keystrokes(cf). f is implicitly valid as it is in factors vector
		int cost = is_valid(f) + 1 + min_keystrokes(cf);
		if(cost < min) min = cost;
	}
	store[N] = min;
}

void print_factors(){
	for(int i=0; i<factors.size();i++){
		cout << factors[i] << " ";
	}
	cout << endl;
}

void init_store(){
	for(int i=0; i<=X; i++){
		store[i] = -1;
	}
}

int main(){
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		factors.clear();
		for(int i=0;i<10;i++){
			cin >> working[i];
			//cout << working[i] << " ";
		}
		//cout << endl;
		
		cin >> X;
		sqrtX = (int)(sqrt(X)+1.0);
		//cout << "X = " << X << " sqrtX " << sqrtX << endl;
		
		store = new int[X+1];
		init_store();
		
		
		fill_factors();
		//print_factors();
		
		int minkeys = min_keystrokes(X);
		minkeys = minkeys + 1; //for the final =
		if(minkeys >= 9999){
			printf("Case #%d: Impossible\n", tc, minkeys);
		}
		else {
			printf("Case #%d: %d\n", tc, minkeys);
		}
		delete[] store;
	}
}
