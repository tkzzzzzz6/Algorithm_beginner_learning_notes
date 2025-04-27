#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Animal
{
private:
    string name;
    bool gender;
    using type = int;

public:
    Animal(string name, bool gender) : name(name), gender(gender) {}
    void f();
};

class Cat : public Animal
{
    // 1.成员变量 2.成员函数 3.类型定义
};

void Animal::f()
{
    printf("%s",&name);
}

void main(){
    Animal a("xixi", true);
    a.f();
    return;
}