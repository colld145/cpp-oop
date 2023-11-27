#include <iostream>

using namespace std;

class Human{
    string name;
    int age;
    int weight;
    static int countHuman;
public:
    static int getStaticCount(){ // Use without objects
        return countHuman;
    }
    // DEFAULT
    Human() //:name("no name"), age(0), weight(0) {}
    {
        name = "no name";
        age = 0;
        weight = 0;
        countHuman++;
    }

    Human(string name): Human()
    {
        this->name = name;
        //age = 0;
        //weight = 0;
    }

    Human(string name, int age): Human(name)
    {
        //this->name = name;
        this->age = age;
        //weight = 0;
    }

    Human(string name, int age, int weight): Human(name, age)
    {
        //this->name = name;
        //this->age = age;
        this->weight = weight;
    }

    Human(int age): Human()
    {
        //name = "no name";
        this->age = age;
        //weight = 0;
    }



    void Show(){
        cout << countHuman << " -------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }

    ~Human(){
        --countHuman;
    }


};

int Human::countHuman = 0;

/*Тема: Конструктори, деструктори
Завдання
Створіть додаток «Телефонна книга». Необхідно збері-
гати дані про абонента (ПІБ, домашній телефон, робочий
телефон, мобільний телефон, додаткова інформація про
контакт) всередині відповідного класу(Abonent). Наповніть клас
змінними-членами, функціями-членами, конструкторами,
використовуйте ініціалізатор.Створити статичну змінну для
кількості абонентів. Використати делегування конструкторів.
class PhoneBook
{
Abonent * abonents
int countAbonent
}
Надайте користувачеві мож-
ливість додавати нових абонентів, видаляти абонентів,
шукати абонентів за ПІБ, показувати всіх абонентів.

***зберігати інформацію в файл і завантажувати з файлу.*/

struct Name{
    string first_name;
    string last_name;
    string surname;
};

class Abonent{
    Name name;
    int home_phone;
    int work_phone;
    int mobile_phone;
    string info;
public:
    Abonent(){
        name.first_name = "empty";
        name.last_name = "empty";
        name.surname = "empty";
        home_phone = 0;
        work_phone = 0;
        mobile_phone = 0;
        info = "empty";
    }

    Abonent(Name name):Abonent(){
        this->name.first_name = name.first_name;
        this->name.last_name = name.last_name;
        this->name.surname = name.surname;
    }

    Abonent(int home_phone, int work_phone, int mobile_phone):Abonent()
    {
        this->home_phone = home_phone;
        this->work_phone = work_phone;
        this->mobile_phone = mobile_phone;
    }

    Abonent(Name name, string info):Abonent(){
        this->name.first_name = name.first_name;
        this->name.last_name = name.last_name;
        this->name.surname = name.surname;
        this->info = info;
    }

    void Show(){
        cout << "---------------------" << endl;
        cout << "First name: " << name.first_name << endl;
        cout << "Last name: " << name.last_name << endl;
        cout << "Surname: " << name.surname << endl;
        cout << "Home phone: " << home_phone << endl;
        cout << "Work phone: " << work_phone << endl;
        cout << "Mobile phone: " << mobile_phone << endl;
        cout << "Info: " << info << endl;

    }

    Name GetName(){
        return name;
    }

    ~Abonent(){};
};

class PhoneBook{
    Abonent* abonents;
    static int count_abonents;
public:
    void AddAbonent(Abonent new_abonent){
        Abonent* temp = new Abonent[count_abonents + 1];
        for (int i = 0; i < count_abonents; ++i) {
            temp[i] = abonents[i];
        }
        temp[count_abonents] = new_abonent;
        delete []abonents;
        count_abonents++;
        abonents = temp;
    }

    void DeleteAbonent(int index){
        index--;
        Abonent* temp = new Abonent[count_abonents - 1];
        for (int i = 0, j = 0; i < count_abonents; ++i) {
            if(i != index){
                temp[j] = abonents[i];
                j++;
            }
        }
        count_abonents--;
        delete[] abonents;
    }

    void PrintAbonents(){
        for (int i = 0; i < count_abonents; ++i) {
            cout << i + 1 << "..." << endl;
            abonents[i].Show();
        }
    }

    void FindByName(Name name){
        for (int i = 0; i < count_abonents; ++i) {
            Name temp = abonents[i].GetName();
            if(name.first_name == temp.first_name && name.last_name == temp.last_name && name.surname == temp.surname){
                abonents[i].Show();
            }
        }
    }
};

int PhoneBook::count_abonents = 0;

int main() {

//    Human h1;
//    h1.Show();
//    Human h2("Andrii");
//    h2.Show();
//    Human h3("Olena", 15);
//    h3.Show();
//    Human h4("Yura", 10, 40);
//    h4.Show();
//    Human h5(100);
//    h5.Show();

    // -------------------------------
    Name name;
    name.first_name = "Andrii";
    name.last_name = "Valeriyovych";
    name.surname = "Trofimchuk";
    Abonent h1(name, "Hello world");
    h1.Show();
    Abonent h2(2523525,356346357,36346346);
    h2.Show();




    return 0;
}
