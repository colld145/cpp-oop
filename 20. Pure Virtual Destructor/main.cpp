#include <iostream>

using namespace std;


class Person
{
    string name;
public:
    Person(): name("No name") {}

    Person(string name): name(name) {}

    virtual void Print() const
    {
        cout << "Name: " << name << endl;
        cout << endl;
    }

    virtual ~Person(){}

};


class Aspirant: public Person
{
    string *subjects;
    int sub_count;
public:
    Aspirant(string name, initializer_list<string> list):Person(name)
    {
        this->sub_count = list.size();
        subjects = new string[sub_count];
        int i = 0;
        for(string sub : list)
        {
            subjects[i] = sub;
            i++;
        }
    }

    void Print() const override
    {
        cout << "----------- Aspirant ------------" << endl;
        Person::Print();
        cout << "Subjects: " << endl;
        for (int i = 0; i < sub_count; ++i)
        {
            cout << i + 1 << ". " << subjects[i] << endl;
        }
    }

    ~Aspirant()
    {
        if(subjects != nullptr)
            delete [] subjects;
    }
};


int main()
{
    srand((unsigned)time(NULL));

    cout << "---------------- Group ------------------" << endl;
    Person* people[3]
    {
        new Aspirant("Vasyl", {"Recuperation","Hydroelectric Power Plant","Something else.."}), new Aspirant("Grisha", {"Engines"})
    };

    for (int i = 0; i < 2; ++i)
    {
        people[i]->Print();
        cout << endl;
        delete people[i];
    }


    return 0;
}
