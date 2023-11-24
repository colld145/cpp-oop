#include <iostream>

using namespace std;


class Animal // Abstract class
{
    string name;
    string place;
    float weight;
public:
    Animal(): name("no name"), place("no place"), weight(0){}

    Animal(string name, string place, float weight):name(name), place(place)
    {
        this->weight = weight > 0 ? weight : 0;
    }

    virtual void ShowInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Place: " << place << endl;
        cout << "Weight: " << weight << endl;
    }

    // Pure virtual method
    virtual void MakeSound() = 0;

    virtual void Move() const
    {
        cout << "I'm moving..." << endl;
    }
};


class Lion : public Animal
{
    float run_speed;
public:
    Lion(): run_speed(0), Animal(){}

    Lion(string name, string place, float weight, float run_speed):run_speed(run_speed), Animal(name, place, weight){}

    void ShowInfo() const
    {
        Animal::ShowInfo();
        cout << "Run speed: " << run_speed << " km/h" << endl;
    }

    void Move() const override
    {
        cout << "I'm running with speed " << run_speed << " km/h" << endl;
    }

    void MakeSound() override
    {
        cout << "Roar!" << endl;
    }
};

class Duck : public Animal
{
    float balance;
    float fly_height;
public:
    Duck():balance(0), fly_height(0), Animal(){}

    Duck(string name, string place, float weight, float balance, float fly_height):balance(balance), fly_height(fly_height), Animal(name, place, weight) {}

    void Move() const override
    {
        cout << "I'm swimming and flying up to " << fly_height << " m" << endl;
    }

    void MakeSound() override
    {
        cout << "Quack-quack!" << endl;
    }

    void ShowInfo() const
    {
        Animal::ShowInfo();
        cout << "Balance: " << balance << " $"<< endl;
        cout << "Fly height: " << fly_height << " m" << endl;
    }
};

void RollCall(Animal& animal)
{
    animal.MakeSound();
    animal.ShowInfo();
    cout << endl;
}

class Reptile : public Animal
{
    float swim_deep;
public:
    Reptile(): swim_deep(0), Animal() {}

    Reptile(string n, string p, float w, float d): swim_deep(d), Animal(n,p,w) {}

    void Move() const override
    {
        cout << "I'm crawling and swimming up to " << swim_deep << " m" << endl;
    }

    void ShowInfo() const
    {
        Animal::ShowInfo();
        cout << "Swim deep: " << swim_deep << " m" << endl;
    }


};

class Turtle : public Reptile
{
public:
    Turtle(): Reptile(){}
    Turtle(string n, string p, float w, float d): Reptile(n,p,w,d){}
    void MakeSound() override
    {
        cout << "Chirps-chirps!" << endl;
    }
};


/*1. Створити клас тварини з місцем проживання (можна взяти
створений на парі).Визначити наступні класи наслідники —
лисиця, кролик. Створити клас Рослини і наслідник-трава.
Лисиця їсть кролика. Кролик їсть траву. Лисиця може
вмерти — визначений вік. Кролик теж може
померти.Крім цього визначений клас — життя, у якому вони взаємодіють
між собою. Якщо в околицях більше трави,
ніж кроликів, то трава залишається, інакше трава зїдена.
Якщо лисиця занадто стара, вона може вмерти . якщо
лисиць дуже багато (більше 5 в околиці ) лисиці
більше не з'являються. Якщо кроликів меньше ніж лисиць,
то лис їсть кролика.*/

class Fox : public Animal
{
    int age;
public:
    Fox():age(0), Animal(){}
    Fox(string n, string p, float w, int age):age(age), Animal(n,p,w){}

    void ShowInfo() const
    {
        Animal::ShowInfo();
        cout << "Age: " << age << endl;
    }

    void MakeSound()
    {
        cout << "shw..." << endl;
    }

    int getAge()
    {
        return age;
    }

    void AddAge()
    {
        age = age + 1;
    }

    void Eat()
    {
        cout << "The fox had a dinner." << endl;
    }

    void Death()
    {
        cout << "The fox dead." << endl;
    }
};

class Rabbit : public Animal
{
public:
    Rabbit():Animal(){}

    Rabbit(string n, string p, float w): Animal(n,p,w){}

    void MakeSound()
    {
        cout << "nwss.." << endl;
    }

    void Eat()
    {
        cout << "The rabbit had a dinner." << endl;
    }

    void Death()
    {
        cout << "The Rabbit dead." << endl;
    }
};



class Plant
{
    string name;
public:
    Plant():name("No name") {}
    Plant(string name):name(name) {}
};

class Grass : public Plant
{
public:
    Grass():Plant() {}
    Grass(string name): Plant(name) {}
};


class Life
{
    Fox* foxes;
    int amount_of_foxes;
    Rabbit* rabbits;
    int amount_of_rabbits;
    Grass* grass;
    int amount_of_grass;
public:
    Life():foxes(nullptr), amount_of_foxes(0), rabbits(nullptr), amount_of_rabbits(0), grass(nullptr), amount_of_grass(0){}

    void LifeCycle()
    {
        AddFox();
        AddRabbit();
        AddGrass();
        for(int i = 1; i <= 50;i++)
        {
            cout << "------------- Day " << i << " ----------------" << endl;
            Print();
            cout << endl;

            AddFoxAge();

            if(amount_of_foxes <= 5)
                AddFox();

            CheckOld();

            if(amount_of_rabbits >= amount_of_foxes)
            {
                RemoveRabbit();
                foxes->Eat();
            }
            else
                AddRabbit();


            if(amount_of_grass >= amount_of_rabbits)
            {
                RemoveGrass();
                rabbits->Eat();
            }
            else
                AddGrass();



        }

    }

    void AddFox()
    {
        Fox* temp = new Fox[amount_of_foxes+1];
        for (int i = 0; i < amount_of_foxes; ++i)
        {
            temp[i] = foxes[i];
        }
        int weight = 1 + rand() % 10;
        temp[amount_of_foxes] = Fox("Fox", "Earth", weight, 0);
        delete [] foxes;
        amount_of_foxes++;
        foxes = temp;
    }

    void AddFoxAge()
    {
        for (int i = 0; i < amount_of_foxes; ++i)
        {
            foxes[i].AddAge();
        }
    }

    void RemoveFox()
    {
        Fox* temp = new Fox[amount_of_foxes-1];
        for (int i = 0; i < amount_of_foxes-1; ++i)
        {
            temp[i] = foxes[i];
        }
        delete [] foxes;
        amount_of_foxes--;
        foxes = temp;
    }

    void RemoveFoxByIndex(int index)
    {
        Fox* temp = new Fox[amount_of_foxes-1];
        for (int i = 0, j = 0; i < amount_of_foxes; ++i)
        {
            if(i != index)
            {
                temp[j] = foxes[i];
                j++;
            }
        }
        delete [] foxes;
        amount_of_foxes--;
        foxes = temp;
    }

    void CheckOld()
    {
        for (int i = 0; i < amount_of_foxes; ++i)
        {
            if(foxes[i].getAge() > 10 )
            {
                foxes[i].Death();
                RemoveFoxByIndex(i);
            }
        }
    }

    void AddRabbit()
    {
        Rabbit* temp = new Rabbit[amount_of_rabbits+1];
        for (int i = 0; i < amount_of_rabbits; ++i)
        {
            temp[i] = rabbits[i];
        }
        int weight = 1 + rand() % 5;
        temp[amount_of_rabbits] = Rabbit("Rabbit", "Earth", weight);
        delete [] rabbits;
        amount_of_rabbits++;
        rabbits = temp;
    }

    void RemoveRabbit()
    {
        Rabbit* temp = new Rabbit[amount_of_rabbits-1];
        for (int i = 0; i < amount_of_rabbits-1; ++i)
        {
            temp[i] = rabbits[i];
        }
        delete [] rabbits;
        amount_of_rabbits--;
        rabbits = temp;
    }

    void AddGrass()
    {
        Grass* temp = new Grass[amount_of_grass+1];
        for (int i = 0; i < amount_of_grass; ++i)
        {
            temp[i] = grass[i];
        }
        temp[amount_of_grass] = Grass("Grass");
        delete [] grass;
        amount_of_grass++;
        grass = temp;
    }

    void RemoveGrass()
    {
        Grass* temp = new Grass[amount_of_grass-1];
        for (int i = 0; i < amount_of_grass-1; ++i)
        {
            temp[i] = grass[i];
        }
        delete [] grass;
        amount_of_grass--;
        grass = temp;
    }

    void Print() const
    {
        cout << " ---- Foxes ----: " << endl;
        for (int i = 0; i < amount_of_foxes; ++i)
        {
            foxes[i].ShowInfo();
        }
        cout << endl;
        cout << " ---- Rabbits ----: " << endl;
        for (int i = 0; i < amount_of_rabbits; ++i)
        {
            rabbits[i].ShowInfo();
        }
        cout << endl;
        cout << " ---- Grass ----: " << endl;
        cout << "Amount of grass: " << amount_of_grass << endl;
        cout << endl;
    }
};

int main()
{
    srand((unsigned)time(NULL));
//    Lion lion("Simba", "Africa", 190, 81);
//    lion.ShowInfo();
//    lion.Move();
//    lion.MakeSound();
//    cout << "--------------------------" << endl;
//    Duck duck("Scrooge", "The USA", 1.2, 44000000000, 2000);
//    duck.ShowInfo();
//    duck.Move();
//    duck.MakeSound();
//
//    RollCall(lion);
//    RollCall(duck);
//
//
//    Turtle leonardo("Leonardo", "Ocean", 35, 290);
//    RollCall(leonardo);

    Life life;
    life.LifeCycle();

    return 0;
}
