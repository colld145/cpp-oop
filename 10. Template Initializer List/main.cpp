#include <iostream>
using namespace std;


//template <typename T_coll, typename T_value>
template <class T_coll, class T_value>
class MyClass{
    T_coll* collection;
    int size;
    T_value value;
public:
    MyClass(){
        collection = nullptr;
        size = 0;
        //point;
    }
    MyClass(T_coll* coll, T_value value):collection(coll), value(value){}

    ~MyClass(){
        if(collection != nullptr){
            delete [] collection;
        }
    }

    void SetCollection(T_coll* coll);

    void SetValue(T_value value){
        this->value = value;
    }

    void Print(){
        cout << "Collection: " << collection << endl;
        cout << "Value: " << value << endl;
    }
};

template <class T_coll, class T_value>
void MyClass<T_coll, T_value>::SetCollection(T_coll *coll) {
    collection = coll;
}


template <typename T_arr>
class Array{
    T_arr* arr;
    int size;
public:
    Array(){
        arr = nullptr;
        size = 0;
    }

    explicit Array(int size){
        this->size = size;
        arr = new T_arr[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

    Array(const initializer_list<T_arr> &list){
        this->size = list.size();
        arr = new T_arr[size];
        /*for (int i = 0; i < size; ++i) { // default for
            arr[i] = list[i];
        }*/
        int i = 0;
        for(T_arr element : list){ // foreach
            arr[i++] = element;
        }
    }

    void Fill(const initializer_list<T_arr> &list){
        if(arr != nullptr) delete []arr;
        this->size = list.size();
        arr = new T_arr[size];
        int i = 0;
        for(T_arr element : list){
            arr[i++] = element;
        }
    }

    void Print(){
        cout << "Array size: " << size << endl;
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Array(){
        if(arr != nullptr){
            delete [] arr;
        }
    }

    T_arr FindMax();
    T_arr FindMin();
    void Sort();
    int FindElement(T_arr element);
    void ChangeElement(T_arr element, int index);
};

template<typename T_arr>
T_arr Array<T_arr>::FindMax() {
    T_arr max = arr[0];
    for (int i = 0; i < size; ++i) {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


template<typename T_arr>
T_arr Array<T_arr>::FindMin() {
    T_arr min = arr[0];
    for (int i = 0; i < size; ++i) {
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

template<typename T_arr>
void Array<T_arr>::Sort() {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if(arr[i] > arr[j]){
                T_arr temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<typename T_arr>
int Array<T_arr>::FindElement(T_arr element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element)
            return i;
    }
}

template<typename T_arr>
void Array<T_arr>::ChangeElement(T_arr element, int index) {
    for (int i = 0; i < size; ++i) {
        if(i == index){
            arr[i] = element;
        }
    }
}

int main() {

    /*Шаблони класів. initializer_list
    Завдання 1:
    Перетворити раніше створений клас Array на шаблон, який дозволить
    зберігати елементи будь-якого типу. Функціональність залишити на
    тому ж рівні.
    Додати можливість створювати об'єкт та присвоювати йому
    значення шляхом спискової ініціалізації: { 1, 2, 3...}
    Реалізуйте шаблонні функції для пошуку максимуму,
    мінімуму, сортування масиву (будь-яким алгоритмом
    сортування), двійкового пошуку в масиві, заміни елемента
    масиву на передане значення. Ці методи винести за межі класу*/

    Array<int> arr({35,5,42,7,46,23});
    arr.Print();
    cout << "Max = " << arr.FindMax() << endl;
    cout << "Min = " << arr.FindMin() << endl;
    cout << "Find the index of the element '5': " << arr.FindElement(5) << endl;
    cout << "SORT! -------" << endl;
    arr.Sort();
    arr.Print();
    cout << "Change element -------" << endl;
    arr.ChangeElement(777, 0);
    arr.Print();


    // -----------------------------------

    //Array arr(5);
    //arr.Print();

    //Array arr2({5,76,23,4,9,0,34});
    //arr2.Print();
    //arr2.Fill({3,2,1});
    //arr2.Print();

    //Point <float> point(4.3, 6.77);
    // point.Print();

    //Point <int> point2(4, 6);
    // point2.Print();

    //NewPoint <double, long> point3(2.25, 10);
    // point3.Print();

    long* long_arr = new long[6];
    for (int i = 0; i < 6; ++i) {
        long_arr[i] = i + 1;
        //cout << long_arr[i] << " ";
    }
    cout << endl;

    char* char_arr = new char[6];
    for (int i = 0; i < 6; ++i) {
        char_arr[i] = 'a' + i;
        //cout << char_arr[i] << " ";
    }
    cout << endl;


    MyClass<long, string> my_class(long_arr, "Class with long collection");
    MyClass<char, string> my_class2(char_arr, "Class with char collection");

    //my_class.Print();
    //my_class2.Print();


    //delete [] long_arr; // Destructor is deleting
    //delete [] char_arr;


    const int size = 10;

    int numbers[size] = {11,56,3,89,34,73,23,91,0,85};
    //cout << "Max = " << FindMax(numbers, size) << endl;

    string colors[5] = {"red", "white", "blue", "green", "black"};
    //cout << "Max color: " << FindMax(colors, 5) << endl;


    return 0;
}
