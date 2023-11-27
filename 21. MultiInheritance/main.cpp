#include <iostream>

using namespace std;


class Car
{
public:
    void Driving()
    {
        cout << "I'm driving" << endl;
    }

    void Use()
    {
        cout << "I use" << endl;
    }
};


class Airplane
{
public:
    void Flying()
    {
        cout << "I'm flying" << endl;
    }

    void Use()
    {
        cout << "I use" << endl;
    }
};


class FlyingCar : public Car, public Airplane
{
};


class A
{
public:
    int a;
    void Show()
    {
        cout << "A" << endl;
    }
};


class B : public A{};
class C : public A{};


class D1 : public B, public C
{
public:
    int getValue() { return a; }
};

class D2 : public A{};


class D3 : public D1, public D2{};



int main()
{

    FlyingCar fc;
    ((Car)fc).Use();


    D3 d;



    return 0;
}
