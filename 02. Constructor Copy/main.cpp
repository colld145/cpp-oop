#include <iostream>
using namespace std;

/*Завдання 1:
Створіть клас Array – це клас динамічного масиву чисел з певним функціоналом.
 Властивостями класа буде вказівник на сам масив (int* arr) та його теперішній розмір (int size).
Клас повинен дозволяти наступний функціонал:
	•	Заповнити масив значеннями (випадковими, з клавіатури , по замовчуванню (заповнити масив 0))
	•	Відображати вміст масиву
	•	Додавати елемент в масив
	•	Видаляти елемент з масива (по значенню або по індексу)
	•	Відсортувати масив (по спаданню/зростанню)
	•	Визначати значення (мінімальне, максимальне та  середнє арифметичне)
Також передбачити набір конструкторів:
	•	Конструктор за замовчуванням, який встановлювтиме початкові значення(заповнити масив 0))
	•	Конструктор, який прийматиме розмір масиву та заповнюватиме нулем всі елементи
	•	Конструктор копіювання, який буде копіювати всі дані об'єкта включаючи масив
Також реалізувати деструктор в класі для уникнення втрати пам’яті. Врахувати можливі помилки
 (видалення не існуючого елемента, порожній масив і тд.). Успіхів!
Всі методі, які не змінюють оригінал мають бути CONST.*/

class Array{
    int size;
    int *arr;
public:
    Array(){
        arr = nullptr;
        size = 0;
    }

    explicit Array(int size){
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 30;
        }
    }

    Array(const Array &other){
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

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
            for (int j = i + 1; j < size; ++j) {
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void MinMaxAvgElements() const{
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
        int avg = 0;
        for (int i = 0; i < size; ++i) {
            avg += arr[i];
        }
        avg = avg / size;
        cout << "max: " << max << endl;
        cout << "min: " << min << endl;
        cout << "avg: " << avg << endl;

    }


    ~Array(){
        delete [] arr;
    };
};


int main() {
    Array arr(5);
    arr.Print();
    arr.Sort();
    arr.Print();
    arr.MinMaxAvgElements();
    cout << "--------" << endl;
    Array arr2(arr);
    arr2.Print();
    return 0;
}
