
#include<iostream>
#include<cstdio>
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main(int argc, char *argv[])
{  
    if(strcmp(argv[1],'f')){
        int n,k;
        scanint(n);
        scanint(k);
        int cnt=0;
        while(n--)
        {
         int num;
         scanint(num);
         if(num%k==0)cnt++;
        }
        printf("%d",cnt);
    }
    return 0;            
}
