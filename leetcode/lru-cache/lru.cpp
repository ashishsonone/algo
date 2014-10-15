#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


/*
class LRUCache{
public:
	typedef struct Node{
		int key; 
		int val; 
		int time;
	} Node;
	
	vector<Node> pq;
	int last_index; //last empty index
	int global_time;
	
	void swap(int i, int j){
		Node temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	} 
	
	void percolate_up(int index){//curr index
		int parent = index/2;
		while(index > 1){
			if(pq[index].time < pq[parent].time){
				swap(index, parent);
				index = parent;
				parent = parent/2;
			}
			else{
				break;
			}
		}
	}
	
	int find_min(int a, int b){ //index a < b
		if(a >= last_index) return -1;
		else if(b >= last_index) return a; //b is invalid
		else if(pq[a].time < pq[b].time) return a;
		else return b;
	}
	
	void percolate_down(int index){
		while(true){
			int c = find_min(index*2, index*2+1);
			if(c == -1) break;
			if(pq[index].time > pq[c].time){
				swap(index, c);
				index = c;
			}
		}
	}

    LRUCache(int capacity) {
        pq.resize(capacity+1);
        global_time = 0;
    }
    
    int get(int key) {
		    
    }
    
    void set(int key, int value) {
        Node temp;
        temp.key = key;
        temp.val = value;
        temp.time = global_time++;
    }
};
*/

class LRUCache{
public:
	typedef struct Node{
		int key;
		int val; 
	} Node;
	typedef list<Node>::iterator NodeItr;
	typedef map<int, NodeItr>::iterator MapItr;
	
	list<Node> pq;
	map<int, NodeItr> hash_map;
	int capacity;

    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
		MapItr mit = hash_map.find(key);
		if(mit == hash_map.end()) return -1;
		
		NodeItr nit = mit->second; //get node iterator in list 
		
		Node node = *nit; //get the node
		pq.erase(nit); //remove the node from list
		pq.push_back(node);
		
		nit = pq.end(); nit--; //get new iterator pos for this node(end of list)
		mit->second = nit;
		
		return node.val;
    }
    
    void set(int key, int value) {
		MapItr mit = hash_map.find(key);
		NodeItr nit;
		if(mit == hash_map.end()){
			//insert key into map if not already
			if(pq.size() >= capacity){
				//delete the first in list & map
				Node n = *(pq.begin());
				hash_map.erase(n.key); //removed from map
				pq.erase(pq.begin()); //removed from list
			}
			hash_map[key] = nit; //garbage value must be overwritten
		}
		else{
			//delete the existing Node from list
			NodeItr nit = mit->second; //get node iterator in list 
			pq.erase(nit);
		}
		
		//Here now we just have to insert the new node(key, val) at end and update the map
		
		mit = hash_map.find(key);
		Node newnode;
		newnode.key = key;
		newnode.val = value;
		
		pq.push_back(newnode);
		
		nit = pq.end(); nit--;
		mit->second = nit;
    }
};

int main(){
	list<int> l;
	l.push_back(2);
	l.push_back(3);
	
	list<int>::iterator it;
	it = l.end();
	it--;
	
	l.pop_front();
	l.push_back(5);
	
	cout << (*it) << endl;
	it++;
	cout << (*it) << endl;
	
	cout << "Start" << endl;
	
	LRUCache cache(2);
	cache.set(1, 3);
	cache.set(2, 4);
	int v = cache.get(1);
	cout << v << endl;
	cache.set(3, 10);
	v = cache.get(2);
	cout << v << endl;
	v = cache.get(3);
	cout << v << endl;
	
}
