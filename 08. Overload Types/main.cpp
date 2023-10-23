#include <iostream>
#include <string>
using namespace std;

/*Завдання:
До раніше створеного класу Array додайте перетворення типів до int і string
• Перетворення до int повертає суму елементів масиву.
• Перетворення до string повертає значення елементів масива у вигляді рядка.*/

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

    operator int(){
        int res = 0;
        for (int i = 0; i < size; ++i) {
            res += arr[i];
        }
        return res;
    }

    operator string(){
        string res{};
        for (int i = 0; i < size; ++i) {
            res += to_string(arr[i]) + " ";
        }
        return res;
    }

};

/*До раніше створеного класу Airplane додайте
• Перетворення об’єкту до типу string який буде повертати модель літака
• Вивід об'єкта на екран за допомогою потоку ostream (оператор <<)
• Заповнення об'єкта з клавіатури за допомогою потоку istream (оператор >>)*/

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

    operator string(){
        return model;
    }


    friend ostream& operator << (ostream& out, const Airplane &plane);
    friend istream& operator >> (istream& in, Airplane &plane);


};

ostream& operator << (ostream& out, const Airplane &plane){
    out << "Model: " << plane.model << endl;
    out << "Type: " << plane.type << endl;
    out << "Amount of passengers: " << plane.amount_of_passengers << endl;
    out << "Max passengers: " << plane.max_passengers << endl;
    return out;
}

istream& operator >> (istream& in, Airplane &plane){
    in >> plane.model;
    in >> plane.type;
    in >> plane.amount_of_passengers;
    in >> plane.max_passengers;
    return in;
}


int main() {
    Array arr(5);
    cout << arr.operator int();
    cout << arr.operator string();

    Airplane plane("boeing", "120M", 1, 100);
    cout << "Enter a plane: ";
    cin >> plane;
    cout << plane;

    return 0;
}
