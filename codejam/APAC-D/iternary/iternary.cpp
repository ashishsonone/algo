#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

typedef struct ticket_t{
	string start;
	string end;
} ticket_t;

int main(){
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		int numtickets;
		scanf("%d", &numtickets);
		map<string, ticket_t> tickets; //store tickets using start city
		map<string, int> ocount; //how many times a city appeared
		
		for(int i=0; i<numtickets; i++){
			ticket_t ticket;
			cin >> ticket.start;
			cin >> ticket.end;
			tickets[ticket.start] = ticket;
			if(ocount.find(ticket.start) == ocount.end()){
				//cout << ticket.start << " 1 " << endl;
				ocount[ticket.start] = 1;
			}
			else{
				ocount[ticket.start]++;
			}
			
			if(ocount.find(ticket.end) == ocount.end()){
				//cout << ticket.end << " 2 " << endl;
				ocount[ticket.end] = 1;
			}
			else{
				ocount[ticket.end]++;
			}
			//cout << ticket.start << " " << ticket.end << endl;
		}
		
		//now map ocount has count for each city. find 2 cities with count 1(start, end);
		
		string endpoints[2];
		int index=0;
		
		for(map<string, int>::iterator it=ocount.begin(); it != ocount.end(); it++){
			string city = it->first;
			int c = it->second;
			if(c == 1){
				endpoints[index++] = city;
			}
		}
		//cout << endpoints[0] << " $$ " << endpoints[1] << endl;
		
		string begining, ending;
		if(tickets.find(endpoints[0])!= tickets.end()){
			begining = endpoints[0];
			ending = endpoints[1];
		}
		else{
			begining = endpoints[1];
			ending = endpoints[0];
		}
		//cout << "begining " << begining <<  " "  << ending << endl;
		
		map<string, ticket_t>::iterator it = tickets.find(ending);
		if(it != tickets.end()){
			cout << "Someting wrong " << endl;
		}
		
		cout << "Case #" << tc << ": ";
		while(true){//traverse through next hops until reach end
			ticket_t t = tickets[begining];
			cout << t.start << "-" <<t.end<< " ";
			map<string, ticket_t>::iterator it = tickets.find(t.end);
			if(it != tickets.end()){//next hop exists
		//		cout << "next " << t.end << endl;
				begining = t.end ;
			}
			else{
				break;
			}
		}
		cout << endl;
		//cout << endl << "###########"  << endl;
		//break;
	}
}
