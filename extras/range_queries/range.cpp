#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node_t{
	int start;
	int end; //inclusive
	int val; //for leaf start = end
	
	node_t *left;
	node_t *right;
	
	node_t(int s, int e, node_t *l, node_t *r){
		start = s;
		end = e;
		left = l;
		right = r;
	}
	node_t(int s, int e, int v, node_t *l, node_t *r){
		start = s;
		end = e;
		val = v;
		left = l;
		right = r;
	}
} node_t;

node_t* create(int s, int e, int * array){
	node_t * root;
	if(s == e){
		root = new node_t(s, s, array[s], NULL, NULL);
		return root;
	}
	
	int mid = s + (e-s)/2;
	node_t * left = create(s, mid, array);
	node_t * right = create(mid+1, e, array);
	root = new node_t(s, e, left->val + right->val, left, right);
	return root;
}

void print(int * array, int N){
	for(int i=0; i<N; i++){
		printf("%2d ", i);
	}
	printf("\n");
	
	for(int i=0; i<N; i++){
		printf("%2d ", array[i]);
	}
	printf("\n");
}

int query(node_t *root, int start, int end){
	//printf("query() node[%d, %d] Q[%d, %d]\n", root->start, root->end, start, end);
	if(root->start == start && root->end == end){
		return root->val;
	}
	
	int sum;
	if(end <= root->left->end){ //lies entirely in left
		sum = query(root->left, start, end);
	}
	else if(start > root->left->end){//ies entirely right
		sum = query(root->right, start, end);
	}
	else{
		int sep = root->left->end;  //seperator  [start, sep], [sep+1, end]
		sum = query(root->left, start, sep) + query(root->right, sep+1, end);
	}
	return sum;
}
int main(){
	int N;
	cin >> N;
	int * array = new int[N];
	for(int i=0; i<N; i++){
		cin >> array[i];
	}
	print(array, N);
	node_t * root = create(0, N-1, array);
	//cout << root->right->left->left->right->val  << endl;
	//cout << root->val  << endl;
	
	int Q; //no of queries
	cin >> Q;
	for(int i=0; i<Q; i++){
		int l, r;
		cin >> l >> r;
		printf("query [%d, %d]\n", l, r); 
		int sum = query(root, l, r);
		cout << sum << endl;
	}
	
}
