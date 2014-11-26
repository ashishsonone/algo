#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int binary(vector<int>&num, int start, int x){
        int low = start;
        int high = num.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(num[mid] == x) return mid;
            else if(x < num[mid]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    
    bool equal(vector<int> a, vector<int> b){
        for(int i=0; i<3; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    
    int next(vector<int>& num, int index){
		int val = num[index];
		while(index < num.size() && num[index] == val){
			index++;
		}
		return index;
	}
	
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > triplets;
        sort(num.begin(), num.end());
        for(int i=0; i<num.size(); ){
            for(int j=i+1; j<num.size(); ){
                int target = -(num[i] + num[j]);
                int ind = binary(num, j+1, target);
                //cout << ind << " index " << endl;
                if(ind >=0){
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[ind]); //v contains sorted because i, j and ind are in increasing order and num is sorted
                    if(triplets.size() == 0 || !equal(triplets[triplets.size()-1], v)){
                        triplets.push_back(v);    
                    }
                }
                j = next(num, j);
            }
            i = next(num, i);
        }
        return triplets;
    }
    
void print(vector<vector<int> > vecs){
	for(int i=0; i<vecs.size(); i++){
		for(int j=0; j<vecs[i].size(); j++){
			cout << vecs[i][j] << " ";
		}
		cout << endl;
	}
}
    
int main(){
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(arr[0]));
    
    vector<vector<int> > three = threeSum(num);
    print(three);
    return 0;
}
