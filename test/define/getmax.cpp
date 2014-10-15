// function macro
#include <iostream>
using namespace std;

#define getmax(a,b) ((a)>(b)?(a):(b))
#define SELF(x) #x
typedef enum{
    v0,
    v1,
    v2
}registers;

int main()
{
  int x=5, y;
  y= getmax(x,2);
  cout << y << endl;
  cout << getmax(7,x) << endl;
  cout << SELF(v0) <<endl;
  return 0;
}
