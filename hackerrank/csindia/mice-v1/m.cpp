#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int holes[131075];
int mice[131075];

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int n;
        scanf("%d", &n);
        for(int j=0; j<n; j++){
            scanf("%d", &mice[j]);
        }
        for(int j=0; j<n; j++){
            scanf("%d", &holes[j]);
        }
        sort(mice, mice+n);
        sort(holes, holes+n);

        int max = 0;
        int diff;
        for(int k=0; k<n; k++){
            diff = abs(mice[k] - holes[k]);
            if(diff > max) max = diff;
        }
        printf("%d\n", max);
    }
}
