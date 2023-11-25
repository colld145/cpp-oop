#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
ostream &operator<<(ostream& out, vector<T> v)
{
    out << "[ ";
    for(auto n : v)
    {
        out << n << " ";
    }
    out << "]";
    return out;
}

// -------------------------------------------

/*Завдання:

Написати програму «Автоматизована інформаційна система залізничного вокзалу».

Система містить: відомості про відправлення потягів далекого прямування.

Для кожного потяга вказуємо:

номер;
час відправлення;
станцію призначення.

Забезпечити наступний функціонал:

Додати потяг в систему;
Виведення інформації по всіх потягах;
Виведення інформації по конкретному потяга (по номеру);

trains[i].getNumber() == number;

Відредагувати час відправлення потяга (по номеру);
Відсортувати список потягів по часу відправлення;*****
Показати список потягів по станції призначення;
Записати список в файл; ***********************
Зчитати список з файлу. *********

Використовувати контейнерний клас vector. Для запису/читання потяга з файла перевантажити оператори<< >>*/

struct Time
{
    short h, m, s;
};

class Train
{
private:
    int number;
    Time departureTime;
    string destination;
public:
    Train():number(0), destination("Empty") {}

    Train(int n, Time dt, string d):number(n), departureTime(dt), destination(d) {}

    int getNumber() const
    {
        return number;
    }

    friend ostream& operator << (ostream& out, const Train &train);
};

ostream& operator << (ostream& out, const Train &train){
    out << "Number: " << train.number << endl;
    out << "Departure time: " << train.departureTime.h << ":" << train.departureTime.m << ":" << train.departureTime.s << endl;
    out << "Destination: " << train.destination << endl;
    return out;
}




class Railway
{
    vector<Train> trains;

public:
    void AddTrain(Train& train)
    {
        trains.push_back(train);
    }

    void ShowTrains() const
    {
        for (int i = 0; i < trains.size(); ++i)
        {
            cout << trains[i] << endl;
        }
    }

    void ShowTrainByIndex(int number) const
    {
        for (Train train : trains)
        {
            if(train.getNumber() == number)
                cout << train << endl;
        }
    }

};



int main()
{

    /*// init vector
    vector<int> digits;
    digits = {3,685,34,85,46};
    cout << digits << endl;
    cout << "Capacity: " << digits.capacity() << endl;


    // add element
    digits.push_back(5);
    cout << digits << endl;
    cout << "Capacity: " << digits.capacity() << endl;


    // delete element
    digits.erase(digits.begin()+5);
    cout << digits << endl;
    cout << "Capacity: " << digits.capacity() << endl;

    // insert element
    digits.insert(digits.begin(), {7,8,9,10}); // add to the start
    cout << digits << endl;
    digits.insert(digits.end(), 777); // add to the end
    cout << digits << endl;
    digits.insert(digits.end(), 5,666); // add to the end 5 elements
    cout << digits << endl;
    digits.erase(digits.begin()+ 5, digits.end());
    cout << digits << endl;
    cout << "Capacity: " << digits.capacity() << endl;

    // resize
    digits.resize(30);
    cout << "Capacity: " << digits.capacity() << endl;*/

    // ----------------------------------------------












    return 0;
}
