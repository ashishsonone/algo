typedef struct{
    int a;
    int b;
} P;

P f(){
    P x;
    x.a = 2;
    x.b = 4;
    return x;
}

int main(){
    P y = f();
    int a;
    int b;
    a = y.a;
    b = y.b;
}
