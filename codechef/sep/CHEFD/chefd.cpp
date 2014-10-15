#include <cstdio>
#include <iostream>
using namespace std;

typedef struct op_t{
	int d[6];
	int rem;
	op_t(){
		d[2] = 0;
		d[3]= 0;
		d[5] = 0;
		rem = 0;
	}
	void print(){
		printf("%d, %d, %d, %d\n", d[2], d[3], d[5], rem);
	}
	op_t operator+(op_t &other){
		op_t ret;
		ret.d[2] = d[2] + other.d[2];
		ret.d[3] = d[3] + other.d[3];
		ret.d[5] = d[5] + other.d[5];
		return ret;
	}
} op_t;

op_t get_factorization(int num){
	op_t factorization;
	while(num % 2 == 0){
		factorization.d[2] += 1;
		num = num/2;
	}
	while(num % 3 == 0){
		factorization.d[3] += 1;
		num = num/3;
	}
	while(num % 5 == 0){
		factorization.d[5] += 1;
		num = num/5;
	}
	factorization.rem = num;
	return factorization;
}

typedef struct node_t{
	int val;
	op_t global; //applicable to itself and all right (children >= val)
	op_t local; //applicable only to itself
	node_t(int v){
		val = v;
	}
	node_t(){
		val = 0;
	}
	void print(){
		printf("%d g[%d, %d, %d] l[%d, %d, %d]\n", val, global.d[2], global.d[3], global.d[5],
			local.d[2], local.d[3], local.d[5]);
	}
}node_t;



int main(){
	int N;
	scanf("%d", &N);
	node_t * array = new node_t[N+1];
	
	for(int i=1; i<=N; i++){
		int num;
		scanf("%d", &num); 
		node_t node(num);
		array[i] = node;
	}
	
	int ops;
	scanf("%d", &ops);
	
	for(int i=0; i<ops; i++){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int l, r, div;
			scanf("%d", &l);
			scanf("%d", &r);
			scanf("%d", &div);
			printf("%d %d %d %d\n",type, l, r, div);
			
			array[l].global.d[div] += 1;
			
			int cur = l;
			while(cur > 0){
				if(cur % 2 == 0){ //it is left child of parent, then this effect will carry over to parent(&its right children) also
					array[cur].global.d[div] += 1;
				}
				cur = cur/2;
			}
			//we're done
			array[l].print();
		}
		else{
			int l, newval;
			scanf("%d", &l);
			scanf("%d", &newval);
			printf("%d %d %d\n",type, l, newval);
			
			array[l].val = newval;
			op_t local = array[l].global; //reset using its own global values and add all the parents global which has it 
										  //as its right child
			int cur = l;
			while(cur > 1){
				if(cur%2 == 1){ //if odd i.e right child  of its parent
					local = local + array[cur/2].global; //add parent's global
				}
				cur = cur/2;
			}
			array[l].local = local;
			//its local and value is all set
			array[l].print();
		}
	}
	
	//delete[] array;
}

