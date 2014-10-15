#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int N;
	cin >> N;
	for(int caseno=1; caseno <= N; caseno++){
		map<int, int> items; //stores val, pos
		int C;
		cin >> C;
		int I;
		cin >> I;
		bool found = false;
		for(int i=1; i<=I; i++){ //index starts from 1
			int val;
			cin >> val;
			if(found) continue;
			
			int complement = C - val;
			//cout << "finding " << complement << endl;
			map<int, int>::iterator it = items.find(complement);
			if(it != items.end()){
				int pos2 = it->second;
				cout << "Case #" << caseno << ": " << pos2 << " " << i << endl;
				found = true;
			}
			else{//push to map
				//cout << "inserting " << val  << ", " << i << endl;
				items[val] = i;
			}
		}
	}
	return 0;
}
