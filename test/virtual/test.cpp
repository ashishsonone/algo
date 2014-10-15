#include <iostream>
using namespace std;

class Animal
{        
    public: 
      // turn the following virtual modifier on/off to see what happens
      virtual std::string Says() { return "?\n"; }  
};

class Dog: public Animal
{
    public: std::string Says() { return "Woof\n"; }
};

int main()
{
    Dog* d = new Dog();
    Animal* a = d;       // refer to Dog instance with Animal pointer
    Animal* animal = new Animal();

    cout << d->Says();   // always Woof
    cout << a->Says();   // says Woof if virtual; says ? if not virtual.
    cout << animal->Says();   // says Woof if virtual; says ? if not virtual.
    return 0;
}
