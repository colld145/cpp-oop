#include <iostream>

using namespace std;


class Enemy
{
protected:
    string name;
    int health;
    float damage;
    int level;
    float defence;
public:
    Enemy():name("no name"), health(0), damage(0), level(0), defence(0) {}
    Enemy(string n, int h, float d, int l, float def):name(n), health(h), damage(d), level(l), defence(def) {}
    void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
        cout << "Level: " << level << endl;
        cout << "Defence: " << defence << endl;
    }

    void DecreaseHealth(int value)
    {
        if(health - (value - defence) < 0)
            health = 0;
        else
            health -= (value - defence);
    }

    bool isAlive() const
    {
        return health > 0;
    }
};

class Dragon : public Enemy
{
    float fire;
public:
    Dragon():fire(0), Enemy() {}

    Dragon(string n, int h, float d, int l, float def, float f):fire(f), Enemy(n, h, d, l, def) {}

    float Attack() const
    {
        cout << "Attacking with damage " << damage << endl;
        return damage;
    }

    void Defence(int damage)
    {
        cout << "Getting " << damage << " damage " << endl;
        DecreaseHealth(damage - fire);
        cout << "Health after damage: " << health << " hp"<< endl;
    }

    void Print() const
    {
        cout << "-------------- Dragon ----------------" << endl;
        Enemy::Print();
        cout << "Fire strength: " << fire << endl;
    }
};

class Monster : public Enemy
{
    float run_speed;
public:
    Monster(): run_speed(0), Enemy(){}

    Monster(string n, int h, float d, int l, float def, float rs):run_speed(rs), Enemy(n,h,d,l,def){}

    void Run()
    {
        cout << "Run with speed : " << run_speed << " km/h" << endl;
    }

    void Print() const
    {
        cout << "------------------ Monster -------------------" << endl;
        Enemy::Print();
        cout << "Run speed: " << run_speed << endl;
    }
};

/*Завдання N1
Створіть клас Student, який міститиме інформацію
про студента.
За допомогою механізму успадкування, реалізуйте клас
Aspirant (аспірант — студент, який готується до захисту
кандидатської роботи) похідний від Student.
Завдання N2
Створіть клас Passport (паспорт), який буде містити
паспортну інформацію про громадянина України.
За допомогою механізму успадкування, реалізуйте
клас ForeignPassport (закордонний паспорт) похідний
від Passport.
Нагадаємо, що закордонний паспорт містить крім
паспортних даних, також дані про візи, номер закордон-
ного паспорта.*/


class Student
{
protected:
    string name;
    int age;
    string spec;
public:
    Student():name("no name"), age(0), spec("no specialty") {}

    Student(string name, int age, string spec):name(name), age(age), spec(spec) {}

    void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Specialty: " << spec << endl;
    }
};

class Aspirant: public Student
{
private:
    int mark;
    string theme;
public:
    Aspirant(): mark(0), theme("no theme"), Student() {}
    Aspirant(string name, int age, string spec, int mark, string theme):mark(mark), theme(theme), Student(name, age, spec){}

    void Print() const
    {
        Student::Print();
        cout << "Mark: " << mark << endl;
        cout << "Theme: " << theme << endl;
    }
};

// ------------------------------------

class Passport
{
protected:
    string full_name;
    int age;
    int id;
public:
    Passport(): full_name("no name"), age(0), id(0) {}

    Passport(string name, int age, int id): full_name(name), age(age), id(id){}

    void Print() const
    {
        cout << "Full name: " << full_name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

class ForeignPassport: public Passport
{
private:
    bool visa;
public:
    ForeignPassport():visa(0), Passport() {}

    ForeignPassport(string name, int age, int id, bool visa):visa(visa), Passport(name, age, id) {}

    void Print() const
    {
        cout << "------------ Foreign Passport -------------" << endl;
        Passport::Print();
        cout << "Visa: " << visa << endl;
    }
};

int main()
{
//    Monster monster("Grisha", 2 ,0 ,1 ,100, 150);
//    monster.Run();
//    monster.Print();
//    Dragon boss("Boss", 100, 5, 80, 1, 2);
//    boss.Print();
//
//    Dragon dragon("Alex", 100, 4, 60, 1, 1);
//
//    int i = 1;
//    do {
//        cout << "-------------- Round " << i << " -------------------" << endl;
//        boss.Defence(dragon.Attack());
//        dragon.Defence(boss.Attack());
//        cout << endl;
//        i++;
//    }
//    while(dragon.isAlive() && boss.isAlive());
//
//    boss.Print();
//    dragon.Print();

    //  -------------------- Task 1 --------------------------

//    Aspirant steve("Steve Jobs", 22, "Automation Engineer", 4, "New technology of Automation");
//    steve.Print();

    //  -------------------- Task 2 --------------------------

//    ForeignPassport my_pass("Steve Jobs", 22, 3427, 1);
//    my_pass.Print();



    return 0;
}
