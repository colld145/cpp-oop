#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int age;
    int* marks;
    int marksCount;

public:
    Student()
    {
        name = "";
        age = 0;
        marks = nullptr;
        marksCount = 0;
    }

    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
        this->marks = nullptr;
        this->marksCount = 0;

        cout << "Paramerized Constructor [" << name << "]...\n";
    }

    Student(const Student & other){
        this->name = other.name;
        this->age = other.age;
        //this->marks = other.marks; // -- error
        this->marks = new int[other.marksCount];
        for (int i = 0; i < other.marksCount; ++i) {
            marks[i] = other.marks[i];
        }
        this->marksCount = other.marksCount;
    }

    ~Student()
    {
        if (marks != nullptr)
            delete[] marks;
        cout << "Destructor [" << name << "]...\n";
    }


    void Print()
    {
        cout << "-------- STUDENT [" << name << "] ---------\n";
        cout << "Age: " << age << endl;
        cout << "Marks: ";
        for (size_t i = 0; i < marksCount; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    void AddMark(int value)
    {
        int* new_arr = new int[marksCount + 1];
        for (size_t i = 0; i < marksCount; ++i)
        {
            new_arr[i] = marks[i];
        }
        new_arr[marksCount] = value;
        if (marks != nullptr)
            delete[] marks;
        marks = new_arr;

        ++marksCount;
    }

};


struct Wagon{
    int number;
    int amount_of_places;
    int amount_of_passengers;
    Wagon(){
        number = 0;
        amount_of_places = 0;
        amount_of_passengers = 0;
    }

    Wagon(int number, int amount_of_places, int amount_of_passengers){
        this->number = number;
        this->amount_of_places = amount_of_places;
        this->amount_of_passengers = amount_of_passengers;
    }

    void Show(){
        cout << number << " --------------" << endl;
        cout << "Amount of places: " << amount_of_places << endl;
        cout << "Amount of passengers: " << amount_of_passengers << endl;
    }

};

class Train{
private:
    string model;
    Wagon * wagon;
    int amount_of_wagons;
public:
    Train(){
        model = "";
        wagon = nullptr;
        amount_of_wagons = 0;
    }

    Train(string model){
        this->model = model;
        wagon = nullptr;
        amount_of_wagons = 0;
    }

    Train(string model, Wagon*& wagon, int amount_of_wagons){
        this->model = model;
        this->wagon = wagon;
        this->amount_of_wagons = amount_of_wagons;
    }

    Train(const Train & other){
        this->model = other.model;
        this->amount_of_wagons = other.amount_of_wagons;
        this->wagon = new Wagon[other.amount_of_wagons];
        for (int i = 0; i < other.amount_of_wagons; ++i) {
            wagon[i] = other.wagon[i];
        }
    }

    void Show(){
        cout << "Model: " << model << endl;
        for (int i = 0; i < amount_of_wagons; ++i) {
            wagon[i].Show();
        }
    }

    void AddWagon(Wagon new_wagon){
        Wagon * temp = new Wagon[amount_of_wagons + 1];
        for (int i = 0; i < amount_of_wagons; ++i) {
            temp[i] = wagon[i];
        }
        temp[amount_of_wagons] = new_wagon;
        delete []wagon;
        wagon = temp;
        amount_of_wagons++;
    }

    void AddWagon(int number, int amount_of_places, int amount_of_passengers){
        Wagon new_wagon(number, amount_of_places, amount_of_passengers);
        Wagon * temp = new Wagon[amount_of_wagons + 1];
        for (int i = 0; i < amount_of_wagons; ++i) {
            temp[i] = wagon[i];
        }
        temp[amount_of_wagons] = new_wagon;
        delete []wagon;
        wagon = temp;
        amount_of_wagons++;
    }

    void AddPassenger(int wagon_number){
        for (int i = 0; i < amount_of_wagons; ++i) {
            if(wagon_number == wagon[i].number){
                wagon[i].amount_of_passengers++;
            }
        }
    }
};


int main() {

//    int number = 0; // init by copy
//    int value(42); // direct init - with constructor
//    int size{33}; // uniform init - check of correct data type

    // -------------------------------------------------------


//    Student st("Mykhailo", 20);
//    st.AddMark(5);
//    st.AddMark(4);
//    st.AddMark(5);
//    st.AddMark(3);
//
//    st.Print();
//
//    {
//        Student misha = Student(st);
//        misha.Print();
//    }
//
//    st.Print();

    // ---------------------------------

    /*Для масиву вагонів створити окрему структуру
з наступними полями:
struct Vagon
номер вагону
кількість місць
кількість пасажирів
class Train
Створити клас Потяг. У класі оголосити поля(змінні члени класу):
модель
кількість вагонів
вказівник на масив вагонів(динамічний).Vagon * vagon;
В класі потяг оголосити дефолтний конструктор
і перезавантажений конструктор.
Реалізувати метод Show()
Реалізувати метод додавання вагону до динамічного масиву
Реалізувати метод - додати 1 пасажира у вагон
Реалізувати конструктор копіювання*/

    Train ukrzaliz("ukrzaliz_train");
    Wagon new_wagon(1, 1, 0);
    ukrzaliz.AddWagon(new_wagon);
    Wagon new_wagon2(2, 10, 5);
    ukrzaliz.AddWagon(new_wagon2);
    ukrzaliz.Show();
    ukrzaliz.AddPassenger(2);
    ukrzaliz.AddPassenger(2);
    ukrzaliz.AddPassenger(1);
    cout << "############################" << endl;
    ukrzaliz.Show();
    //cout << "NEW UKRZALIZ2" << endl;
    //Train ukrzaliz2(ukrzaliz);
    //ukrzaliz2.Show();

    return 0;
}
