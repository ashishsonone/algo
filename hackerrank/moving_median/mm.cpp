#include <iostream>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;

multiset<double> L; //smaller
multiset<double> R; //larger

typedef multiset<double>::iterator iterator_t;

void print(multiset<double> &l){
	for(iterator_t it=l.begin(); it != l.end(); it++){
		//cout << *it << " " ;
		printf("%.3f ", *it); 
	}
	cout << endl;
}

void balance(){
	while(true){
		//cout << L.size() << " " << R.size() << endl;
		if(L.size() > R.size()+1){
			iterator_t it = L.end();
			it--;
			double val = *it;
			L.erase(it);
			R.insert(val);
			continue;
		}
		if(R.size() > L.size()+1){
			iterator_t it = R.begin();
			double val = *it;
			R.erase(it);
			L.insert(val);
			continue;
		}
		break;
	}
}

double find_median(){
	if(L.size() == R.size()){
		iterator_t it1 = L.end();
		it1--;
		double n1 = *it1;
		iterator_t it2 = R.begin();
		double n2 = *it2;
		return (n1+n2)/2;
	}
	else if(L.size() > R.size()){
		iterator_t it = L.end();
		it--;
		return *it;
	} 
	else{
		iterator_t it = R.begin();
		return *it;
	}
}

void erase(double popped){
	//cout << "erasing " << popped << endl;
	iterator_t it;
	if((it = L.find(popped)) != L.end()){
		L.erase(it);
	}
	else if((it = R.find(popped)) != R.end()){
		R.erase(it);
	}
	else{
		cout << "element " << popped << " not found" << endl;
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    queue<double> stream;
    
    double t;
    int window;
    cin >> window;
    double error;
    cin >> error;
    //stream.push(error);
    //L.insert(error);
    for(int i=0; i<window; i++){
		cin >> t;
		stream.push(t);
		L.insert(t);
	}
	
	//cout << "balance" << endl;
	balance();
	//print(L);
	//print(R);
	
	double ref;
	while(cin >> ref){
		double median = find_median();
		//printf("ref %.3f , median %.3f\n", ref, median);
		if(abs(ref-median) > median*error){
			printf("%.3f\n", ref);
		}
		//process
		double popped = stream.front();
		stream.pop();
		
		erase(popped);//erase popped from the sets
		if(ref > median){
			R.insert(ref);
		}
		else{
			L.insert(ref);
		}
		balance(); //balance
		stream.push(ref);
	}
	
    return 0;
}
