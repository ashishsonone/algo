typedef struct{
    int a;
    int b;
} P;

typedef int a[7][8][9];
P f(){
    P x;
    return x;
}

int main(){
    f();
    a x;
    int (*b)[8][9];
    b=x;
}
