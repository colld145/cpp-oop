#include <iostream>

using namespace std;

/*До раніше створеного класу Array додайте перевантаження оператора [], ()

[] – повертає елемент за вказаним індексом (по посиланню)
() – збільшує всі елементи масиву на зазначену величину*/

class Array
{
private:
    int size;
    int* arr;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 30;
        }
    }
    Array(int size, int a)
    {
        this->size = size;
        arr = new int[size];
        /* for (int i = 0; i < size; i++)
         {
             arr[i] = rand() % 30;
         }*/
    }
    ~Array()
    {
        delete[]arr;
    }

    int getSize()const
    {
        return size;
    }
    void setArray(int value, int index)
    {
        arr[index] = value;
    }
    void display(int index)const
    {
        cout << arr[index] << " ";
    }

    int operator [] (int index){
        return this->arr[index];
    }

    void operator () (int n){
        for (int i = 0; i < size; ++i) {
            this->arr[i] += n;
        }
    }
};

/*Завдання 1:
Створити клас Airplane (літак), який буде мати наступні характеристики:
• Модель
• Тип
• Кількість пасажирів
• Максимальна кількість пасажирів
За допомогою перевантаження операторів реалізувати:
1. Перевірку на рівність типів літаків (операція ==) friend
2. Збільшення і зменшення пасажирів в салоні літака (операції ++ та --
в префіксній формі)
3. Порівняння двох літаків по максимально можливій кількості пасажирів
на борту (операція >) friend
4. Збільшити кількість пасажирів на певне значення (оператор ())
Перевантаження логічних операцій виконати за допомогою дружніх функцій.
При виконанні операцій, потрібно перевіряти чи не перебільшено максимальну
кількість пасажирів.*/

class Airplane{
    string model;
    string type;
    int amount_of_passengers;
    int max_passengers;
public:
    Airplane(){
        model = " ";
        type = " ";
        amount_of_passengers = 0;
        max_passengers = 0;
    }

    Airplane(string model, string type, int amount_of_passengers, int max_passengers){
        this->model = model;
        this->type = type;
        this->amount_of_passengers = amount_of_passengers;
        this->max_passengers = max_passengers;
    }

    void Print(){
        cout << "Model: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "Amount of passengers: " << amount_of_passengers << endl;
        cout << "Max passengers: " << max_passengers << endl;

    }

    Airplane operator ++ (){
        ++this->amount_of_passengers;
        return *this;
    }

    Airplane operator -- (){
        --this->amount_of_passengers;
        return *this;
    }

    Airplane operator () (int amount){
        if((amount_of_passengers + amount) <= max_passengers){
            amount_of_passengers += amount;
            return *this;
        }
        else {
            return *this;
        }

    }

    friend bool operator == (const Airplane& first, const Airplane& second);
    friend bool operator > (const Airplane& first, const Airplane& second);
};

bool operator == (const Airplane& first, const Airplane& second){
    return (first.type == second.type);
}

bool operator > (const Airplane& first, const Airplane& second){
    return (first.type > second.type);
}

int main()
{

//    Array arr(5);
//    for (int i = 0; i < arr.getSize(); ++i) {
//        cout << arr.operator[](i) << " ";
//    }
//
//    cout << endl;
//
//    arr(5);
//    for (int i = 0; i < arr.getSize(); ++i) {
//        cout << arr.operator[](i) << " ";
//    }

    Airplane boeing("Boeing", "120", 0, 100);
    Airplane boeing2("Boeing", "120", 0, 100);
    boeing.Print();
    cout << endl;
    ++boeing;
    boeing.Print();
    cout << endl;
    boeing(50);
    boeing.Print();

    if(boeing == boeing2){
        cout << "EQUAL!" << endl;
    }
    else {
        cout << "Not equal:(" << endl;
    }


    return 0;
}
