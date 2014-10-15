#include <cstdio>

int get_max(int n){
    int max = -1;
    int temp;
    for(int k=0; k<n; k++){
        scanf("%d", &temp);
        if(temp > max) max = temp;
    }
    return max;
}

int& max2(int &a, int &b){
    return a >= b ? a : b;
}
int& max3(int &a, int &b, int &c){
    return max2(max2(a, b), c); 
}

int main(){

    /*
    int a = 2, b = 3, c = -2;

    int &d = max3(a, b, c);
    printf("%d\n", d);
    d = d/2;
    d = max3(a, b, c);
    printf("%d\n", d);
    return 0;
    */


    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int R,G,B,M;
        scanf("%d", &R);
        scanf("%d", &G);
        scanf("%d", &B);
        scanf("%d", &M);
        int Rmax = -1, Gmax = -1, Bmax = -1;
        Rmax = get_max(R);
        Gmax = get_max(G);
        Bmax = get_max(B);

        for(int k=0; k<M; k++){
            int &max = max3(Rmax, Gmax, Bmax);
            max = max/2; //this is by reference ;)
        }
        printf("%d\n", max3(Rmax, Gmax, Bmax));
    }
}
