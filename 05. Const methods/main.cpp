#include <iostream>

using namespace std;

//class Date
//{
//private:
//    int day;
//    int month;
//    int year;
//public:
//
//    Date()
//    {
//        day = 0;
//        month = 0;
//        year = 0;
//    }
//
//    int getDay()const
//    {
//        return day;
//    }
//
//};


class Date{
    const int base_year;
    int current_year;
    int day;
    int month;
    int year;
public:
    Date(int current): base_year(2000), current_year(current), day(0), month(0), year(0){};
    Date(int base, int current): base_year(base), current_year(current), day(0), month(0), year(0){};

    void Print(){
        cout << "Base year: " << base_year << endl;
        cout << "Current year: " << current_year << endl;
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }
};


/*Конструктор копіювання, вказіник this

Завдання 1:

Створіть клас Array – це клас динамічного масиву чисел з
 певним функціоналом. Властивостями класа буде вказівник на
 сам масив (int* arr) та його теперішній розмір (int size).

Клас повинен дозволяти наступний функціонал:

Заповнити масив значеннями (випадковими, з клавіатури ,
 по замовчуванню (заповнити масив 0))
Відображати вміст масиву
Додавати елемент в масив
Видаляти елемент з масива (по значенню або по індексу)
Відсортувати масив (по спаданню/зростанню)
Визначати значення (мінімальне, максимальне та  середнє арифметичне)

Також передбачити набір конструкторів:

Конструктор за замовчуванням, який встановлювтиме початкові
 значення(заповнити масив 0))
Конструктор, який прийматиме розмір масиву та заповнюватиме
 нулем всі елементи
Конструктор копіювання, який буде копіювати всі дані об'єкта
 включаючи масив

Також реалізувати деструктор в класі для уникнення втрати
 пам’яті. Врахувати можливі помилки (видалення не існуючого
 елемента, порожній масив і тд.). Успіхів!

Всі методі, які не змінюють оригінал мають бути CONST.*/



class Array{
    int size;
    int *arr;
public:
    Array(){
        arr = nullptr;
        size = 0;
    }

    explicit Array(int size){ // explicit only with one argument
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 30;
        }
    }

//    int getSize() const{
//        return size;
//    }

//    void setArray(int value, int index){
//        arr[index] = value;
//    }
//
//    void Display(int index) const{
//        cout << arr[index] << " ";
//    }

    void InitByRandom(){
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 30;
        }
    }

    void InitByKeyboard(){
        for (int i = 0; i < size; ++i) {
            cout << "Enter an element: ";
            cin >> arr[i];
        }
    }

    void Print() const{
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void AddElement(int element){
        int *temp = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        temp[size] = element;
        delete[]arr;
        size++;
        arr = temp;
    }

    void DeleteElementByIndex(int index){
        int *temp = new int[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if(i != index){
                temp[j] = arr[i];
                j++;
            }
        }
        size--;
        delete []arr;
        arr = temp;
    }

    void Sort(){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    void MinMaxElements(){
        int min = arr[0];
        int min_i = 0;
        int max = arr[0];
        int max_i = 0;
        for (int i = 0; i < size; ++i) {
            if(arr[i] > max){
                max = arr[i];
                max_i = i;
            }
            if(arr[i] < min){
                min = arr[i];
                min_i = i;
            }
        }

    }


    ~Array(){
        delete [] arr;
    };
};

//void Print(const Array& arr){
//    for (int i = 0; i < arr.getSize(); ++i) {
//        arr.Display(i);
//    }
//}



int main()
{
//    const Date event{1, 1, 2024};
//    cout << "Day: " << event.getDay() << endl;

//    Date d(2023);
//    d.Print();
//    int base;
//    cout << "Enter a base year: ";
//    cin >> base;
//    Date d2(base, 2023);
//    d2.Print();

//    srand(time(0));
//
//    Array arr(5);
//    int size = arr.getSize();
//    for (int i = 0; i < size; ++i) {
//        arr.setArray(i + 1, i);
//    }
//
//    Print(arr);







    return 0;
}
