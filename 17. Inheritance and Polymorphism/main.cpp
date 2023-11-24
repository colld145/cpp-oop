#include <iostream>

using namespace std;

class Car
{
protected:
    string mark;
    string model;
    int year;
    float volume;
    string type_fuel;
    int max_speed;
    int horse_power;
public:
    Car():mark(""),model(""),year(0),volume(0),type_fuel(""),max_speed(0),horse_power(0){}

    Car(string mark, string model, int year, float volume, string type_fuel, int max_speed, int horse_power):mark(mark),model(model),year(year),volume(volume),type_fuel(type_fuel),max_speed(max_speed),horse_power(horse_power){}

    virtual void Drive() const
    {
        cout << "I'm a car! I can drive with speed " << max_speed << " km/h" << endl;
    }

    virtual void Print() const
    {
        cout << "Mark: " << mark << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Volume: " << volume << endl;
        cout << "Type fuel: " << type_fuel << endl;
        cout << "Max speed: " << max_speed << endl;
        cout << "Horse power: " << horse_power << endl;
    }

    void SetSpeed(int speed)
    {
        if(speed >= 0)
            max_speed = speed;
    }
};

class PoliceCar : public Car
{
    int sound_volume;
public:
    PoliceCar(): sound_volume(0), Car() {}

    PoliceCar(string mark, string model, int year, float volume, string type_fuel, int max_speed, int horse_power, int sound_volume): sound_volume(sound_volume), Car(mark, model, year, volume, type_fuel, max_speed, horse_power){}

    void Drive() const override
    {
        cout << "I'm a Police car! I can drive with speed " << max_speed << " km/h" << endl;
    }

    void Print() const override
    {
        Car::Print();
        cout << "Sound volume: " << sound_volume << endl;
    }

};

class SportCar : public Car
{
    int turbo;
public:
    SportCar(): turbo(0), Car() {}

    SportCar(string mark, string model, int year, float volume, string type_fuel, int max_speed, int horse_power, int sound_volume): turbo(turbo), Car(mark, model, year, volume, type_fuel, max_speed, horse_power){}

    void Drive() const override
    {
        cout << "I'm a Sport car! I can drive with speed " << max_speed << " km/h" << endl;
    }

    void Print() const override
    {
        Car::Print();
        cout << "Nitro: " << turbo << endl;
    }

    void Nitro()
    {
        max_speed+= turbo;
        cout << "Enable turbo speed: " << max_speed << " km/h" << endl;
    }

};

void TestDrive(Car& car)
{

    car.SetSpeed(60);
    car.Drive();
}

/*Завдання 1:
Створіть клас Shape який містить загальні параметри
будь-якої фігури (ім,я, тип і тд). Визначте віртуальні методи:
•Show – вивід на екран інформації про фігуру;
•GetArea – обчислення площі фігури;
Визначте похідні класи: прямокутник, коло, прямокутний трикутник,трикутник,
трапеція зі своїми функціями площі. – кожний з яких буде
містити притаманні даній фігурі характеристики та перевизначати (override)
алгоритми методів базового класу Shape.
Також створити функцію TestShape, яка приймає фігуру та відображає її
інформацію включаючи площу.
В main протестувати роботу, передавши в функцію різні фігури.*/

class Shape
{
protected:
    string name;
    string type;
    int side;
public:
    Shape():name("no name"), type("no type"), side(0){}

    Shape(string name, string type, int side):name(name), type(type), side(side) {}

    virtual void Show() const
    {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Side: " << side << endl;
    }

    virtual void GetArea() const
    {
        int area;
        area = side * side;
        cout << "Area: " << area << endl;
    }
};



class Rectangle : public Shape
{
    int side2;
public:
    Rectangle():side2(0), Shape(){}

    Rectangle(string name, string type, int side, int side2):side2(side2), Shape(name, type, side){}

    void Show() const override
    {
        cout << "--------- Rectangle ----------" << endl;
        Shape::Show();
        cout << "Side 2: " << side2 << endl;
    }

    void GetArea() const override
    {
        int area;
        area = side * side2;
        cout << "Area: " << area << endl;
    }
};

class Circle : public Shape
{
public:

    Circle(string name, string type, int side):Shape(name, type, side){}


    void Show() const override
    {
        cout << "--------- Circle ----------" << endl;
        Shape::Show();
    }


    void GetArea() const override
    {
        int area;
        float pi = 3.14159265358979323846;
        area = pi * pow(side, 2);
        cout << "Area: " << area << endl;
    }
};

class RightTriangle : public Shape
{
    int side2;
public:

    RightTriangle(string name, string type, int side, int side2):side2(side2), Shape(name, type, side){}

    void Show() const override
    {
        cout << "--------- RightTriangle ----------" << endl;
        Shape::Show();
        cout << "Side 2: " << side2 << endl;
    }


    void GetArea() const override
    {
        int area;
        area = (1/2)*side*side2;
        cout << "Area: " << area << endl;
    }
};

class Triangle : public Shape
{
    int height;
public:

    Triangle(string name, string type, int side, int height):height(height), Shape(name, type, side){}

    void Show() const override
    {
        cout << "--------- Triangle ----------" << endl;
        Shape::Show();
        cout << "Height: " << height << endl;
    }


    void GetArea() const override
    {
        int area;
        area = (1/2)*side*height;
        cout << "Area: " << area << endl;
    }
};

class Trapeze : public Shape
{
    int height;
    int side2;
public:

    Trapeze(string name, string type, int side, int height, int side2):height(height), side2(side2), Shape(name, type, side){}

    void Show() const override
    {
        cout << "--------- Trapeze ----------" << endl;
        Shape::Show();
        cout << "Side2: " << side2 << endl;
        cout << "Height: " << height << endl;
    }


    void GetArea() const override
    {
        int area;
        area = (1/2)*(side*side2)*height;
        cout << "Area: " << area << endl;
    }
};


void TestShape(Shape& shape)
{
    shape.Show();
    shape.GetArea();
}


int main()
{

//    Car simple_car("Daewoo", "Lanos", 2010, 1.5, "Petrol", 160, 75);
//
//    simple_car.SetSpeed(70);
//    simple_car.Drive();
//    simple_car.Print();
//    cout << endl;
//
//    PoliceCar police("Toyota", "Prius", 2015, 1.3, "Electric/Petrol", 200, 90, 500);
//    police.SetSpeed(120);
//    police.Drive();
//    police.Print();
//
//
//    SportCar sport("Porsche", "911", 2022, 2.5, "Petrol", 320, 500, 40);
//    sport.Drive();
//
//    TestDrive(police);
//    TestDrive(sport);
//
//    Car * car_salon[3]
//    {
//        new Car("Daewoo", "Lanos", 2010, 1.5, "Petrol", 160, 75),
//        new PoliceCar("Toyota", "Prius", 2015, 1.3, "Electric/Petrol", 200, 90, 500),
//        new SportCar("Porsche", "911", 2022, 2.5, "Petrol", 320, 500, 40)
//    };
//
//    cout << "--------------- Autosalon ----------------" << endl;
//    for (int i = 0; i < 3; ++i)
//    {
//        car_salon[i]->Print();
//        cout << endl;
//    }
//
//    for (int i = 0; i < 3; ++i)
//    {
//        delete car_salon[i];
//    }

    // ------------------------------------

    Rectangle rect("rectangle1", "Rectangle", 5, 5);
    TestShape(rect);
    Circle circle("circle1", "Circle", 5);
    TestShape(circle);


    return 0;
}
