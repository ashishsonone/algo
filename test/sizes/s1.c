typedef int a[7][8][9];

void f(int a[][9])
{
}

 main ()
{
    a j;       // essentially int (*)[8][9]
    f(j[1]); //   passing int(*)[9]
}
