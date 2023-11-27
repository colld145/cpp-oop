#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


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

const char* FILENAME = "trains.txt";
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
    out << train.number << "," << train.departureTime.h << "." << train.departureTime.m << "." << train.departureTime.s << "," << train.destination;
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

    void WriteToFile(){
        ofstream out(FILENAME, ios_base::app);
        for(auto train : trains)
        {
            out << train << endl;
        }
        out.close();
    }

    void ReadFromFile(){
        ifstream in(FILENAME);
        while (!in.eof()){
            Train train;
            char number[5],h[5],m[5],s[5],destination[30];
            in.getline(number, 5, ',');
            if(in.eof()) break;
            in.getline(h, 5, '.');
            in.getline(m, 5, '.');
            in.getline(s, 5, ',');
            in.getline(destination, 30);
            in << endl;
            train.number = stoi(number);
            train.departureTime.h = stoi(h);
            train.departureTime.m = stoi(m);
            train.departureTime.s = stoi(s);
            train.destination = destination;
            AddTrain(train);
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

    Railway railway;
    railway.AddTrain(62, Train(Time(22,30,0), "Lviv"));
    railway.ShowTrains();










    return 0;
}
