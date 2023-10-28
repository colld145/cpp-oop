#include <iostream>
#include <fstream>
using namespace std;


/*Створити клас Rectangle, який буде описувати прямокутник.
  * Клас містить розміри: ширина, висота, символ, який відображатиме
  * прямокутник на екрані та координати розміщення. Для збереження
  * координат створити структуру Coord, яка міститиме X та Y координату.

 Клас повинен містити наступні конструктори:

 Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
 Параметризований конструктор, який приймає один параметр «розмір» та
  ініціалізує ним ширину та висоту
 Параметризований конструктор, який приймає два параметри «ширину» та «висоту»,
  які являються розмірами об’єкта

 Та наступні методи:

 Вивід фігури на екран, відповідного розміру, символом та у
  відповідних координатах
 Зміна розміру прямокутника. Метод приймає два парметри:
  1 – зміна висоти, 2 – ширини
 Переміщення прямокутника. Метод приймає два парметри: 1 – величина переміщення
  по осі X, 2 – по осі Y

 Методи повинні включати перевірку на коректність даних (від’ємна ширина,
  координати і тд). Створити екземпляр об’єкту та протестувати написаті методи.*/

struct Coord{
    int x;
    int y;
};

class Rectangle{
private:
    int width;
    int height;
    char symbol;
    Coord coordinates;
public:

    Rectangle(){
        width = 0;
        height = 0;
        symbol = ' ';
        coordinates.x = 0;
        coordinates.y = 0;
    }

    Rectangle(int width, int height, char symbol){
        this->width = width;
        this->height = height;
        this->symbol = symbol;
        coordinates.x = 0;
        coordinates.y = 0;
    }

    void Print(){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << symbol << " ";
            }
            cout << endl;
        }
    }

    void ChangeSize(int width, int height){
        if(width >= 0 && height >= 0){
            this->width = width;
            this->height = height;
        }
        else {
            this->width = 0;
            this->height = 0;
        }

    }

};


/*Створити клас Student який буде містити характеристики: ім’я, вік, колекція оцінок, кількість оцінок
  та середню оцінку.
В класі повинні буди реалізовані наступні конструктори:
	•	Конструктор по замовчуванню () – встановлюватиме початкові дані
	•	Параметризований конструктор (const char* name, int age) – ініціалізує клас значеннями з параметрів
Також створити деструктор для звільнення ресурсів та наступні методи:
	•	Print () – виводить інформацію про студента на екран
	•	AddMark (int mark) – додає оцінку для студента
	•	SetAverageMark () – приватний метод для обрахунку та встановлення середньої оцінки студента
 (викликається всередині класа при додаванні оцінки)
	•	Save () – збереження студента в файл
	•	Load () – зчитування студента в файла
Забезпечити клас необхідними методами для доступа до властивостей (getters, setters).
 По можливості застосувати делегування конструкторів.*/

const char* FILENAME = "students.txt";
class Student
{
private:
    string name;
    int age;
    int* marks;
    int marksCount;
    float avg;
    void SetAverage(){
        float sum = 0;
        for (int i = 0; i < marksCount; i++) {
            sum+= marks[i];
        }
        avg = (float) sum / marksCount;
    }
public:
    void WriteToFile(){
        ofstream out(FILENAME, ios_base::app);
        out << name << ":";
        out << age << ":";
        out << marksCount << ":";
        for (int i = 0; i < marksCount; ++i) {
            out << marks[i] << ":";
        }
        out.close();
    }

    void ReadFromFile(){
        ifstream in(FILENAME);
        while (!in.eof()){
            char name[20], age[5], marksCount[5], avg[5], mark[5];
            in.getline(name, 20, ':');
            if(in.eof()) break;
            in.getline(age, 5, ':');
            in.getline(marksCount, 5, ':');
            this->name = name;
            this->age = atoi(age);
            this->marksCount = atoi(marksCount);
            this->marks = new int[this->marksCount];
            for (int i = 0; i < this->marksCount; ++i) {
                in.getline(mark, 5, ':');
                this->marks[i] = atoi(mark);
            }
        }
    }

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



int main() {

//    Rectangle a(10, 10, '*');
//    Rectangle b(5, 7, '&');
//    a.Print();
//    b.Print();
//
//    cout << endl;
//    a.ChangeSize(10, 5);
//    a.Print();

    Student st1;
    st1.ReadFromFile();
    st1.Print();
    //st1.WriteToFile();




    return 0;
}
