#include <iostream>
#include <fstream>
using namespace std;


/*
Struct Player{              // default public
    string full_name;
    unsigned short age;
    int games;
    int goals;
};

void InitPlayer(Player& player){
    cout << "Enter a name: ";
    cin >> player.full_name;
    cout << "Enter an age: ";
    cin >> player.age;
}
*/

class Player{
private:
    string full_name;
    short age;
    int games;
    int goals;

    bool IsValidGoals(int goals){
        return goals >= 0;
    }
public:
    void Initialize(){
        full_name = "noname";
        age = 0;
        games = 0;
        goals = 0;
    }

    void InitializeFromKeyboard(){
        cout << "Enter a name: ";
        getline(cin, full_name);
        cout << "Enter an age: ";
        cin >> age;
    }

    void Print(){
        cout << "Full name: " << full_name << endl;
        cout << "Age: " << age << endl;
        cout << "Games: " << games << endl;
        cout << "Goals: " << goals << endl;
    }

    void AddGame(int goals = 0){
        this->games++;
        if(IsValidGoals(goals)){
            this->goals+= goals;
        }
    }
};


class Student{
private:
    string name;
    float marks[3];
public:
    float GetAverageMark(){
        float sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += marks[i];
        }
        return sum / 3;
    }

    void setName(string name){
        this->name = name;
    }

    void setMark(float mark, int index){
        if(mark < 1 || mark > 12){
            mark = 0;
        }
        marks[index] = mark;
    }

    string getName(){
        return name;
    }

    float getMark(int index){
        return marks[index];
    }
};

/*Завдання №2
Реалізуйте клас «Точка». Необхідно зберігати координати
x, y, z в змінних-членах класу. Реалізуйте функції-члени
класу для введення даних, виведення даних, реалізуйте
аксесор для доступу до змінних-членів, реалізуйте збе-
реження в файл і завантаження даних з файлу.*/
const char* FILENAME = "point.txt";
class Point{
private:
    int x;
    int y;
    int z;
public:
    void Init(){
        x = 0;
        y = 0;
        z = 0;
    }

    void InitFromKeyboard(){
        cout << "Enter x, y, z: " << endl;
        cin >> x >> y >> z;
    }

    void Print(){
        cout << "X: " << x << "| Y: " << y << "| Z: " << z << endl;
    }

    void setX(int x){
        this->x = x;
    }

    void setY(int y){
        this->y = y;
    }

    void setZ(int z){
        this->z = z;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    int getZ(){
        return z;
    }

    void WriteToFile(){
        ofstream out(FILENAME, ios_base::app);
        out << x;
        out << ":";
        out << y;
        out << ":";
        out << z;
        out << "|";
        out.close();
    }

    void ReadFromFile(){
        ifstream in(FILENAME);

        while (!in.eof()){
            char x1[10], y1[10], z1[10];
            in.getline(x1, 10, ':');
            if(in.eof()) break;
            in.getline(y1, 10, ':');
            in.getline(z1, 10,'|');
            this->x = atoi(x1);
            this->y = atoi(y1);
            this->z = atoi(z1);
        }
    }

};

int main() {

    Point point;
    //point.Init();
    point.ReadFromFile();
    //point.InitFromKeyboard();
    point.Print();
    //point.WriteToFile();



//    Student steve;
//    steve.setName("Steven");
//    cout << steve.getName() << endl;
//    steve.setName("Steve");
//    cout << steve.getName() << endl;
//    steve.setMark(1, 0);
//    steve.setMark(5, 1);
//    steve.setMark(12, 2);
//
//    float avg_mark = steve.GetAverageMark();
//    cout << "Average mark: " << avg_mark << endl;


//    Player misha;
//    misha.Initialize();
//    misha.InitializeFromKeyboard();
//    misha.Print();
//
//    misha.AddGame(0);
//    misha.AddGame(0);
//    misha.AddGame(0);
//    misha.AddGame(0);
//    misha.AddGame(0);
//    misha.AddGame(0);
//    misha.AddGame(0);
//    misha.AddGame(1);
//
//    misha.Print();
    return 0;
}
