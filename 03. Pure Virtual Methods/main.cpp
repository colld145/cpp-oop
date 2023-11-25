#include <iostream>

using namespace std;

/*1.Створити клас Піца з чисто віртуальним методом
Приготувати піцу
У класу піца є два наслідники: міланська піца та грецька піца
в яких має бути реалізовано віртуальний метод
батьківського класу
Створити клас Соус з чисто віртуальним методом
Приготувати соус
Наслідники : міланський соус та грецький соус
Створити клас Фабрика по приготуванню піци з
чисто віртуальними методами:
-Приготувати піцу та
-Приготувати  соус
Для класу Фабрика створити два наслідника :
ФабрикаМілан та ФабрикаГреція з реалізацією віртуальних
методів
В мейні реалізувати меню для роботи з програмою*/


class Pizza
{
public:
    virtual void CookPizza() = 0;
};

class MilanPizza : public Pizza
{
public:
    void CookPizza() override
    {
        cout << "Milan pizza has cooked!" << endl;
    }
};

class GreekPizza : public Pizza
{
public:
    void CookPizza() override
    {
        cout << "Greek pizza has cooked!" << endl;
    }
};

class Sauce
{
public:
    virtual void CookSauce() = 0;
};

class MilanSauce : public Sauce
{
public:
    void CookSauce() override
    {
        cout << "Milan sauce has cooked!" << endl;
    }
};

class GreekSauce : public Sauce
{
public:
    void CookSauce() override
    {
        cout << "Greek sauce has cooked!" << endl;
    }
};

class Factory
{
public:
    virtual void CreatePizza() = 0;
    virtual void CreateSauce() = 0;
};

class MilanFactory : public Factory
{
public:
    void CreatePizza() override
    {
        MilanPizza* milan_pizza = new MilanPizza;
        milan_pizza->CookPizza();
    }

    void CreateSauce() override
    {
        MilanSauce* milan_sauce = new MilanSauce;
        milan_sauce->CookSauce();
    }
};

class GreekFactory : public Factory
{
public:
    void CreatePizza() override
    {
        GreekPizza* greek_pizza = new GreekPizza;
        greek_pizza->CookPizza();
    }

    void CreateSauce() override
    {
        GreekSauce* greek_sauce = new GreekSauce;
        greek_sauce->CookSauce();
    }
};

int main()
{
    MilanFactory milan_factory;
    GreekFactory greek_factory;
    bool exit = false;
    while(!exit)
    {
        int choice = 0;
        cout << "-------------" << endl;
        cout << "1. Create Milan Pizza\n2. Create Milan Sauce\n\n3. Create Greek Pizza\n4. Create Greek Sauce\n\n0. Exit\n" << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                milan_factory.CreatePizza();
                break;
            case 2:
                milan_factory.CreateSauce();
                break;
            case 3:
                greek_factory.CreatePizza();
                break;
            case 4:
                greek_factory.CreateSauce();
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Incorrect choice. Try again" << endl;
                break;
        }
    }

    return 0;
}
