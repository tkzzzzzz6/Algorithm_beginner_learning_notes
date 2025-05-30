#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void shout()
    {
        cout << "动物叫了一声\n";
    }
};

class Cat : public Animal
{
public:
    void shout() override
    {
        cout << "喵喵喵\n";
    }
};


int main(){

    Animal *animal = new Animal();
    Animal *cat = new Cat();
    Animal *dog = new Dog();

    animal->shout();
    cat->shout();
    dog->shout();
    return 0;
}