#include <iostream>

using namespace std;

/*Завдання 2:
Створіть клас з ім'ям «Date» для зберігання дати (день, місяць, рік).
Напишіть необхідні конструктори та метод для збільшення дати на 1 день.
У класі повинні бути перевантажені операціїї:
•++, – – (інкремент та декремент) – додає чи відмінає один день від дати.
Реалізувати обидві форми оператора(постфіксна, префіксна).
•!=, ==, >, < (порівняння) – порівнюють два об’єкта по величині значень
•+=, –= (додавання та віднімання) – виконує додавання чи віднімання певної
кількості днів до об'єкта. Тобто другим операндом буде ціле число.
•() (круглі дужки) – додає до дати певне значення, має 3 перевантаження:
1.(int days) – додає певну кількість днів
2.(int months, int days) – додає певну кількість днів та місяців
3.(int years, int months, int days) – додає певну кількість днів, місяців та років
Оператори інкременту та декременту перевантажити за допомогою глобальних функцій.
Оператори порівняння – дружніми функціями, всі інші – методами класу.
*/

class Date {
private:
    int day, month, year;

public:
    Date(): day(0), month(0), year(0) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void AddOneDay()
    {
        day++;
        if (day > 30)
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }

    void DeleteOneDay()
    {
        day--;
        if (day < 1)
        {
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
            day = 30;
        }
    }

    Date operator ++()
    {
        AddOneDay();
        return *this;
    }

    Date operator +=(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            AddOneDay();
        }
    }

    Date operator -=(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            DeleteOneDay();
        }
    }

    Date operator ++(int)
    {
        AddOneDay();
        return *this;
    }

    Date operator --()
    {
        DeleteOneDay();
        return *this;
    }

    Date operator --(int)
    {
        DeleteOneDay();
        return *this;
    }

    Date operator()(int days)
    {
        for (int i = 0; i < days; ++i)
        {
            AddOneDay();
        }
        return *this;
    }

    Date operator()(int days, int months)
    {
        days += months*30;
        for (int i = 0; i < days; ++i)
        {
            AddOneDay();
        }
        return *this;
    }

    Date operator()(int days, int months, int years)
    {
        days += months*30;
        days += years*365;
        for (int i = 0; i < days; ++i)
        {
            AddOneDay();
        }
        return *this;
    }

    bool operator ==(const Date &other)
    {
        int date1 = this->day + (this->month * 30) + (this->year * 365);
        int date2 = other.day + (other.month * 30) + (other.year * 365);
        return date1 == date2;
    }

    bool operator !=(const Date &other)
    {
        int date1 = this->day + (this->month * 30) + (this->year * 365);
        int date2 = other.day + (other.month * 30) + (other.year * 365);
        return date1 != date2;
    }

    bool operator >(const Date &other)
    {
        int date1 = this->day + (this->month * 30) + (this->year * 365);
        int date2 = other.day + (other.month * 30) + (other.year * 365);
        return date1 > date2;
    }

    bool operator <(const Date &other)
    {
        int date1 = this->day + (this->month * 30) + (this->year * 365);
        int date2 = other.day + (other.month * 30) + (other.year * 365);
        return date1 < date2;
    }


    friend ostream& operator << (ostream& out, const Date& date);
};

ostream& operator << (ostream& out, const Date& date){
    out << date.day << "." << date.month << "." << date.year << endl;
    return out;
}




int main()
{
    Date date(29,11,2023);
    ++date;
    date++;
    cout << date;
    date(10);
    cout << date;



    return 0;
}
