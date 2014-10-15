#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Point;
class PointF;

class Point{
public:
	int x;
	int y;
	
	Point operator-(const Point &other);
	Point operator+(const Point &other);
};

Point Point::operator-(const Point &other){
	Point ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	return ret;
}

Point Point::operator+(const Point &other){
	Point ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	return ret;
}

void print(vector<Point> points){
	for(int i=0; i<points.size(); i++){
		printf("(%d, %d) ", points[i].x, points[i].y);
	}
	printf("\n");
}

void print(Point point){
		printf("(%d, %d) \n", point.x, point.y);
}


int compare(Point a, Point b){
	if(a.x < b.x) return 1; //less
	else if(a.x > b.x) return -1; //greater
	else{//both have same x
		if(a.y < b.y) return 1;
		else if(a.y > b.y) return -1;
		else return 0; //equal
	}
}

void find(Point &P1, Point &P2, Point &P31, Point &P41, Point &P32, Point &P42){
	Point diag = P1 - P2;
	Point perp; 
	perp.x = diag.y;
	perp.y = -diag.x;
	
	//printf("perp :"); print(perp);
	
	P31 = P2 + perp;
	//printf("fp2 and fp41 :"); print(fP2); print(fP31); printf("**\n");
	P41 = P1 + perp;
	
	P32 = P2 - perp;
	P42 = P1 - perp;
}

bool point_compare(Point a, Point b){
	if(compare(a, b) >= 0) return true; //less or equal
	return false;
}


bool binary_search(Point p, vector<Point> &vec){
	int start = 0, end = vec.size()-1;
	int mid;
	while(start <= end){
		mid = (start + end)/2;
		int v = compare(p, vec[mid]);
		if(v == 0){
			//printf("%d : (%d, %d)\n", mid, vec[mid].x, vec[mid].y);
			return true; //found match
		}
		if(v > 0){ //p < mid point. Search left half
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return false;
}

int present(Point p1, Point p2, vector<Point> &vec){
	bool c1 = binary_search(p1, vec);
	bool c2 = binary_search(p2, vec);
	return (int)c1 + (int)c2;
}

int main(){
	int N;
	vector<Point> points;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		Point p;
		scanf("%d", &p.x);
		scanf("%d", &p.y);
		points.push_back(p);
	}
	
	//print(points);
	sort(points.begin(), points.end(), point_compare);
	//print(points);
	
	int max;
	//now for each pair of points nC2
	if(points.empty()) max = 0;
	else max = 1; //only 1 point is confirmed, what if other points are exaclty same as this. Then we need to add 3 points
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i == j) continue; //we must take 2 points
			int comp = compare(points[i], points[j]);
			if(comp == 0) continue; //again these two points are exactly same coordianates
			
			//Now we got two distinct points. Find 2 pairs forming square point candidates
			Point P31, P41, P32, P42;
			find(points[i], points[j], P31, P41, P32, P42);
			
			if(2+present(P31, P41, points) > max) max = 2+present(P31, P41, points);
			if(2+present(P32, P42, points) > max) max = 2+present(P32, P42, points);
			if(max == 4) break;
			/*
			print(points[i]);
			print(points[j]);
			print(P31);
			print(P41);
			print(P32);
			print(P42);
			print(P3d);
			print(P4d);
			break;
			*/
		}
	}
	
	//printf("precison %d", numeric_limits<double>::digits);
	printf("%d\n", 4-max);
}
