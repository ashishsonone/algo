#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<double> V;
    double sum = 0;
    double t;
    
    int io;
    for(io=0; io<N && cin>>t;io++){
       V.push_back(t);
    }
    if(io==N){
		sum = 0;
		for(int i=N-1; i>=0; i--){
			sum += V[i];
		}
		printf("%.3f\n", sum/N);
		while(cin >> t){
			double del = V[0];
			V.erase(V.begin());
			V.push_back(t);
			sum = 0;
			for(int i=N-1; i>=0; i--){
				sum += V[i];
			}
			printf("%.3f\n", sum/N);
		}
	}
    return 0;
}
