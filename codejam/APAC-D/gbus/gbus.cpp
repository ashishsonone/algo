#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(){
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		int numbuses;
		
		scanf("%d", &numbuses);
		int *start = new int[numbuses];
		int *end = new int[numbuses];

		//cout << numbuses << endl;
		for(int i=0; i<numbuses; i++){
			scanf("%d", &start[i]);
			scanf("%d", &end[i]);
		}
		
		int P;
		scanf("%d", &P);
		//cout << P << endl;
		printf("Case #%d: ", tc);
		for(int i=0; i<P; i++){
			int cityno;
			int count = 0;
			scanf("%d", &cityno);
			//cout << "city " << cityno << endl;
			for(int b=0; b<numbuses; b++){
				if(cityno >= start[b] && cityno <=end[b]){
					count++;
				}
			}
			printf("%d ", count);
		}
		printf("\n");
	}
}
