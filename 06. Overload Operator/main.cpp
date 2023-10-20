#include <iostream>

using namespace std;

class Point{
    int x;
    int y;
public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int value){
        x = y = value;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    Point(const Point &other){
        this->x = other.x;
        this->y = other.y;
    }

    void Print(){
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
        cout << endl;
    }

//    Point Plus(const Point& other){
//        Point result(this->x + other.x, this->y + other.y);
//        return result;
//    }

//    Point Minus(const Point& other){
//        Point result(this->x - other.x, this->y - other.y);
//        return result;
//    }

    Point operator+(const Point& other) const{
        Point result(this->x + other.x, this->y + other.y);
        return result;
    }

    Point operator+(int value) const{
        Point result(this->x + value, this->y + value);
        return result;
    }

    Point operator-(const Point& other) const{
        Point result(this->x - other.x, this->y - other.y);
        return result;
    }

    Point operator*(const Point& other) const{
        Point result(this->x * other.x, this->y * other.y);
        return result;
    }

    Point operator/(const Point& other) const{
        Point result(this->x / other.x, this->y / other.y);
        return result;
    }

    Point operator+=(const Point& other){
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Point operator-(){
        //Point result(this->x * -1, this->y * -1);
        //return result;
        return Point(-x, -y);
    }

    bool operator<(const Point& other){
//        if ((this->x + this->y) < (other.x + other.y)){
//            return true;
//        }
//        else{
//            return false;
//        }
        return (this->x + this->y) < (other.x + other.y);
    }

    bool operator>(const Point& other){
        return (this->x + this->y) > (other.x + other.y);
    }

    bool operator>=(const Point& other){
        return (this->x + this->y) >= (other.x + other.y);
    }

    bool operator<=(const Point& other){
        return (this->x + this->y) <= (other.x + other.y);
    }

    bool operator==(const Point& other){
        return (this->x == other.x) && (this->y == other.y);
    }

    bool operator!=(const Point& other){
        return !(*this == other);
    }

    Point operator ++(){ // prefix form of the increment
        ++this->x;
        ++this->y;
        return *this;
    }

    Point operator --(){ // prefix form of the decrement
        --this->x;
        --this->y;
        return *this;
    }

    Point operator ++(int){ // postfix form of the increment
        this->x++;
        this->y++;
        return *this;
    }

    Point operator --(int){ // postfix form of the decrement
        this->x--;
        this->y--;
        return *this;
    }

    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    friend bool operator> (const Point& point1, const Point& point2); // Friends
    friend Point operator ++(Point& point);
    friend ostream& operator << (ostream& out, const Point& point);
    friend istream& operator >> (istream& in, Point& point);
};

bool operator> (const Point& point1, const Point& point2){
    return (point1.x + point1.y) > (point2.x + point2.y);
}

Point operator ++(Point& point){
    point.x++;
    point.y++;
    return point;
}

ostream& operator << (ostream& out, const Point& point){
    out << "X: " << point.x << " Y: " << point.y << endl;
    return out;
}

istream& operator >> (istream& in, Point& other){
    in >> other.x;
    in >> other.y;
    return in;
}

/*Завдання 1:

Створити клас «Time», який буде описувати час 3-ма характеристиками:
 години, хвилини, секунди.

В класі потрібно реалізувати наступні конструктори:

Конструктор по замовчуванню () – встановлюватиме початкові дані
Параметризований (hours, minutes, seconds) – встановлює кожну властивість
Параметризований (seconds) – створює клас перевівши дану кількість
 секунд в години, хвилини, секунди. Наприклад: 5555 = 1год 32хв 35сек
5555/3600- h; 5555/60%60 – m; 5555%60 - s

Також передбачити методи:

Виводу часу на екран в форматі hh:mm:ss
Збільшення часу на одну секунду (11:59:59)++ -> 12:00:00

Клас повинен мати перевантаження наступних бінарних операторів:

    + – * /          виконується певна арифметична операція з часом
 та повертається результат у вигляді нового об'єкту Time

    > < >= <=           перевіряється, який об’єкт містить більшу/меншу
 кількість часу та повертається результат у вигляді типу bool

    == !=             перевіряється чи класи мають не/однаковий час

Використайте explicit для деяких конструкторів.*/

class Time{
    int hour;
    int minute;
    int second;
public:
    Time(){
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    explicit Time(int seconds){
        this->second = seconds % 60;
        this->minute = (seconds / 60) % 60;
        this->hour = seconds / 3600;
    }

    void Print(){
        if(hour < 10){
            cout << "0" << hour << ":";
        }
        else{
            cout << hour << ":";
        }
        if(minute < 10){
            cout << "0" << minute << ":";
        }
        else{
            cout << minute << ":";
        }
        if(second < 10){
            cout << "0" << second;
        }
        else{
            cout << second;
        }
        cout << endl;

    }

    Time PlusSecond(Time &time){
        time.second++;

        if(time.second == 60){
            time.second = 0;
            time.minute++;
        }
        if(time.minute == 60){
            time.minute = 0;
            time.hour++;
        }
        if(time.hour == 24){
            time.hour = 0;
        }
        return time;
    }

    int ReturnSeconds(int hour, int minute, int second) const {
        int seconds;
        seconds = hour * 3600;
        seconds+= minute * 60;
        seconds+= second;
        return seconds;
    }


    Time operator+(Time& other){
        int seconds1 = ReturnSeconds(hour, minute, second);
        int seconds2 = ReturnSeconds(other.hour, other.minute, other.second);
        Time new_time(seconds1 + seconds2);

        return new_time;
    }
};

int main() {

    /*int a = 5;
    a++;
    a--;
    //cout << -a; binar

    int b = 7;
    int c = a + b;
    int d = a - b;


    if (a > 0){ // unar
        cout << "More than 0" << endl;
    }
    else { // unar
        cout << "Less than 0" << endl;
    }

    (a > 0)? cout << "More than 0": cout << "Less than 0"; // unar*/

    /*Point p1;
    p1.Print();
    cout << endl;
    Point p2(5,7);
    p2.Print();
    cout << endl;
    Point p3(2);
    p3.Print();*/

    Point point1(3, 5);
    Point point2(7, 5);

//    point2.Print(); // postfix and prefix
//    ++point2;
//    point2.Print();
//    --point2;

//    if(point1 > point2){
//        cout << "p1 > p2" << endl;
//    }
//    else {
//        cout << "p1 < p2" << endl;
//    }
//
//    cin >> point1;
//    cout << point1;

//    Point result = point1.Plus(point2);
//    result.Print();
//    result = point2.Minus(point1);
//    result.Print();

//    Point result = point1 + point2;
//    result.Print();
//    result = point1 - point2;
//    result.Print();
//    result = point1 * point2;
//    result.Print();
//    result = point1 / point2;
//    result.Print();
//
//    result = point1 + point2;
//    result += 15;
//    result.Print();
//
//    result = -point1;
//    result.Print();
//
//    //result = point1 = point2;
//    result.Print();
//    point1.Print();
//    point2.Print();
//
//    if(point1 > point2){
//        cout << "point1 > point2" << endl;
//    }
//    else{
//        cout << "point1 < point2" << endl;
//    }
//
//    if(point1 != point2){
//        cout << "point1 != point2" << endl;
//    }
//    else{
//        cout << "point1 == point2" << endl;
//    }

//    Time time1(10, 50,55);
//    Time time2(10, 50,55);
//    Time time3 = time1 + time2;
//    time3.Print();




    return 0;
}
