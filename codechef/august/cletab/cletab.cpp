#include <iostream>
#include <list>

#define CUSTOMERLIMIT 401 // 1 - 400 (leave 0)
#define ORDERLIMIT 400 

using namespace std;

void assert_equal(list<int> & l, int a){ //list's front is same as a
	if(l.front() != a) cout << "Something went wrong : list.front() != a" << endl;
}

int main(){
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++){
		int N, M; //n-tables, m-orders
		cin >> N >> M;
		int * orders = new int[M];
		int * customermap = new int[CUSTOMERLIMIT]; //which table the customer is occupying. -1 if none
		int * tablemap = new int[N]; //which customer is on table i;
		list<int> * customer_orderlist = new list<int>[CUSTOMERLIMIT]; //contains orders' index yet to be served corresponding to that customer
		
		//fill
		for(int i=0; i< N; i++) tablemap[i] = -1; //init tablemap(each table is free but dirty)
		for(int i=0; i< CUSTOMERLIMIT; i++) customermap[i] = -1;
		for(int i=0; i< M; i++){
			cin >> orders[i]; //input : take orders in sequence. Each order is a customer id
			customer_orderlist[orders[i]].push_back(i);
			//cout << "here" << customer_orderlist[orders[i]].front()  << endl;
		}
		
		//start
		int clean_count = 0;
		int freetableid = 0;
		
		int curr_cust; //current customer
		for(int ordi=0; ordi<M; ordi++){
			curr_cust = orders[ordi];
			if(customermap[curr_cust] != -1){ //no need to clean as customer is already seated
				assert_equal(customer_orderlist[curr_cust], ordi); //check if order index is same as customer's front
				customer_orderlist[curr_cust].pop_front(); //remove this order from customer's order list
				continue;
			}
			
			else if(freetableid < N){ //still there's free table. Give it to him
				tablemap[freetableid] = curr_cust;
				customermap[curr_cust] = freetableid;
				
				assert_equal(customer_orderlist[curr_cust], ordi);
				customer_orderlist[curr_cust].pop_front(); //remove this order from customer's order list
				
				freetableid++;//increment as this table is now occupied
				clean_count++; //As tables are dirty initially
			}
			
			else{//need to find a table from which customer has to be replaced
				int min_order_index = -1; //init it to minimum
				int customer_to_replace = -1;
				for(int t = 0; t < N; t++){
					int cust = tablemap[t]; // customer currently on table t
					if(customer_orderlist[cust].empty()){
						customer_to_replace = cust; //we're done as this customer won't return
						break;
					}
					
					if(customer_orderlist[cust].front() > min_order_index){ //his next order is farther than current candidate
						customer_to_replace = cust;
						min_order_index = customer_orderlist[cust].front();
					}
				}
				
				if(customer_to_replace == -1) cout << "customer to replace should be some natural number < 400" << endl;
				
				//here we have customer_to_replace set
				int tableid = customermap[customer_to_replace];
				//cout << "   " << ordi << "  replacing " << customer_to_replace <<" by new " << curr_cust << " on table" << tableid <<endl;
				customermap[curr_cust] = tableid; //new customer gets the table
				customermap[customer_to_replace] = -1; //old customer walks out
				tablemap[tableid] = curr_cust; //update tablemap old->new
				
				assert_equal(customer_orderlist[curr_cust], ordi);
				customer_orderlist[curr_cust].pop_front(); //remove this order from customer's order list
				
				clean_count++;
			}
		}
		
		cout << clean_count << endl;
		
		delete[] orders;
		
		delete[] tablemap;
		delete[] customermap;
		delete[] customer_orderlist;
	}
}
