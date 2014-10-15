#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

#define MAXDIST 1000000009
using namespace std;
//utils
int abs(int x){
	return x < 0 ? (-x) : (x);
}

class edge_t;
class station_t;

//graph strutures
class edge_t{
public:
	station_t * end;
	int cost;
	edge_t(int c, station_t* e){
		cost = c;
		end = e;
	}
};

class station_t{
public:
	bool visited;
	int distance;
	int snum;
	int lnum;
	vector<edge_t> adjacent;
	station_t(int l, int s){
		visited = false;
		lnum = l;
		snum = s;
		distance = MAXDIST;
	}
	
	void print(){
		printf("[%d, %d] ==> ", lnum, snum);
		for(int i=0; i<adjacent.size(); i++){
			printf("{%d, %d, %d} ", adjacent[i].end->lnum, adjacent[i].end->snum, adjacent[i].cost);
		}
		printf("\n");
	}
};



//Aux structures storing direct mapping to station_t in graph

struct point_t{
	station_t * station;
	int time; //cum time
	point_t(int t, int l, int s){
		station = new station_t(l, s);
		time = t;
	}
	void print(){
		cout << "[" << station->lnum <<","<<station->snum << ","<< time << "]";
	}
};

class line_t{
public:
	int W;
	vector<point_t> points;
	void print(){
		cout << "W=" << W << " : ";
		for(int i=1; i<points.size(); i++){
			points[i].print();
		}
		cout << endl;
	}
	void reset(){
		for(int i=1; i<points.size(); i++){
			points[i].station->visited = false;
			points[i].station->distance = MAXDIST;
		}
	}
	
	void make_links(){
		for(int i=1; i<points.size(); i++){
			for(int j=1; j<points.size(); j++){ //edge from i to j
				if(i==j) continue;
				edge_t edge(W + abs(points[i].time - points[j].time), points[j].station); //waiting time added
				points[i].station->adjacent.push_back(edge);
			}
		}
	}
};

vector<line_t> network; //store time

void print_network(){
	for(int i=1; i<network.size(); i++){
		network[i].print();
	}
}

void reset_network(){//go to each station and reset visited bool
	for(int i=1; i<network.size(); i++){
		network[i].reset();
	}
}

void make_links(){
	for(int i=1; i<network.size(); i++){
		network[i].make_links();
	}
}

station_t * find_min_non_visited(){
	int min = MAXDIST+10;
	station_t * curr = NULL;
	for(int i=1; i<network.size(); i++){
		for(int j=1; j<network[i].points.size(); j++){
			//cout << network[i].points.size() << " "<< i << " " <<j << endl;
			station_t * station = network[i].points[j].station;
			if(station->visited == false && station->distance < min){
				min = station->distance;
				curr = station;
			}
		}
	}
	return curr;
}

int dijkstra(station_t* source, station_t* dest){//return distance
	reset_network();
	source->distance = 0;
	station_t * curr;
	while(true){
		curr = find_min_non_visited();
		//printf("curr [%d, %d] %d \n", curr->lnum, curr->snum, curr->distance);
		curr->visited = true;
		if(curr == dest) return curr->distance;
		for(int i=0; i<curr->adjacent.size(); i++){
			edge_t edge = curr->adjacent[i];
			station_t * neigh = edge.end;
			if(curr->distance + edge.cost < neigh->distance){//update
				neigh->distance = curr->distance + edge.cost;
			}
		}
	}
	return curr->distance;
}
int main(){
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		network.clear();
		line_t linedummy;
		network.push_back(linedummy);
		int N;
		cin >> N;
		for(int l=1; l <= N; l++){ //l is line #
			line_t line;
			int S, W;
			cin >> S >> W; //waiting time
			line.W = W;
			
			//dummy
			point_t pdummy(-1,-1,-1);
			line.points.push_back(pdummy);
			int cumtime = 0;
			int s; //station #
			for(s=1; s<=S-1; s++){ //S-1 times
				int t;
				cin >> t;
				point_t point(cumtime, l, s);
				line.points.push_back(point);
				cumtime += t;
			}
			point_t point(cumtime, l, s);
			
			line.points.push_back(point);
			
			network.push_back(line);
		}
		//print_network();
		
		make_links(); //make link(edges) from each station to every other station in each line
		
		
		//add tunnels
		int M;
		cin >> M;
		for(int i=0; i<M; i++){
			int m1, s1, m2, s2, t;
			cin >> m1 >> s1 >> m2 >> s2 >> t;
			//cout << m1 << " " << s1 << endl;
			station_t * station1 = network[m1].points[s1].station;
			station_t * station2 = network[m2].points[s2].station;
			edge_t e12(t, station2); //no waiting time
			edge_t e21(t, station1);
			station1->adjacent.push_back(e12);
			station2->adjacent.push_back(e21);
		}
		
		//network[1].points[2].station->print();
		//network[2].points[2].station->print();
		
		int Q;
		cin >> Q;
		printf("Case #%d:\n", tc);
		for(int i=0; i<Q; i++){
			int m1, s1, m2, s2;
			cin >> m1 >> s1 >> m2 >> s2;
			int dist = dijkstra(network[m1].points[s1].station, network[m2].points[s2].station);
			if(dist >= MAXDIST) dist = -1;
			//printf("[%d, %d] to [%d, %d] : %d\n", m1, s1, m2, s2, dist);
			printf("%d\n", dist);
		}
	}
}
