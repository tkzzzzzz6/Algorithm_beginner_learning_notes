class Base1
{
public:
    virtual void func() { cout << "Base1::func()" << endl; }
};

class Base2
{
public:
    virtual void func() { cout << "Base2::func()" << endl; }
};

class Derived : public Base1, public Base2
{
public:
    virtual void func()
    {
        Base1::func();
        Base2::func();
    }
};