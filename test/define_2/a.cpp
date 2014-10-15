#include <iostream>
using namespace std;

enum {
#define DEFSYSCALL(name,code) syscall_code_##name = code,
#include "syscall.dat"
#undef DEFSYSCALL
    syscall_code_count
};

enum {
    a = 2,
    b = 3,
    c = 6,
    d
};
int main(){
    cout << "sys count " << syscall_code_count << endl;
    cout << d << endl;
}
