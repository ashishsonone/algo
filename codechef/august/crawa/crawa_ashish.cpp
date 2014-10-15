#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define PI 3.14159265
int len = 1, degree = 0;

void gen(){
	int x = 0, y = 0;
	cout << x << " " << y << endl;
	for(int i=1; i<10000; i++){
		x+= len * ((int)(cos(degree*PI/180.0)));
		y+= len * ((int)(sin(degree*PI/180.0)));
		cout << x << " " << y << endl;
		len++;
		degree = (degree+90)%360;
	}
}

long long y_getstart_n(long long y){
	if(y <= 0) return (abs(y)*2);
	return abs(y)*2 - 2;
}

long long x_getstart_n(long long x){
	return abs(x)*2 - 1;
}

long long find_x(long long n){
	if(n == 0) return 0;
	long long x = (n + 1)/2;
	if(x % 2 == 0) return -x;
	return x;
}

long long find_y(long long n){
	long long p = n/2;
	long long yhalf = (p+1)/2;
	long long y = yhalf*2;
	if(p%2 == 0) return -y;
	return y;
}

bool lie_inside(long long a, long long b, long long test){
	if(test <= a && test >= b) return true; // a > b
	if(test <= b && test >= a) return true; // a < b
	return false;
}

void print(bool yes){
	if(yes) cout << "YES" << endl;
	else cout << "NO" << endl;
}

bool is_x_candidate(long x){
	if(x > 0) return (x % 2 == 1);
	return (abs(x) % 2 == 0);
}

int main(){
	int T;
	cin >> T;
	
	long long startn;
	long long x,y;
	
	/*for(int i=0; i<30; i++){
		cout<< find_x(i) << ",";
		cout << x_getstart_n(find_x(i)) << "|";
	}
	cout << endl;
	for(int i=0; i<30; i++){
		cout << find_y(i) << ",";
		cout << y_getstart_n(find_y(i)) << "|";
	}
	cout << endl;
	return 0;
	*/
	for(int i=0; i< T; i++){
		bool printed = false; //whether printed or not till now
		cin >> x >> y;
		if(abs(y) % 2 == 0){ //horizontal line
			startn = y_getstart_n(y);
			long long x1 = find_x(startn);
			long long x2 = find_x(startn + 1);
			printed = lie_inside(x1, x2, x);
		}
		if((!printed) && is_x_candidate(x)){ //vertical
			
			startn = x_getstart_n(x);
			
			long long y1 = find_y(startn);
			long long y2 = find_y(startn + 1);
			//cout << startn << "  here" << y1 << "  " << y2 << endl;
			printed = lie_inside(y1, y2, y);
		}
		print(printed);
	}
}
