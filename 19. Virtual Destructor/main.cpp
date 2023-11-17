#include <iostream>

using namespace std;


class Student
{
    string name;
    string specialty;
    int* marks;
    int mark_count;
public:
    Student():name("No name"), specialty("No specialty"), marks(nullptr), mark_count(0) {}

    Student(string name, string sp):name(name), specialty(sp)
    {
        mark_count = 1 + rand() % 9;

        marks = new int[mark_count];
        for (int i = 0; i < mark_count; ++i)
        {
            marks[i] = 1 + rand() % 11;
        }
    }

    virtual void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Specialty: " << specialty << endl;
        cout << "Marks: ";
        for (int i = 0; i < mark_count; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    virtual ~Student()
    {
        if(marks != nullptr)
            delete [] marks;
    }
};


class Aspirant: public Student
{
    string *subjects;
    int sub_count;
public:
    Aspirant(string name, string sp, initializer_list<string> list):Student(name, sp)
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
        Student::Print();
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
    Student st("Alex", "Programmer");
    st.Print();

    Aspirant asp("Vasyl", "Water Engineer", {"Recuperation", "Hydroelectric Power Plant","Something else.."});
    asp.Print();

    cout << "---------------- Group ------------------" << endl;
    Student* group[3]
    {
        new Student("Anton", "Programmer"),
        new Aspirant("Vasyl", "Water Engineer",
                     {"Recuperation","Hydroelectric Power Plant","Something else.."}),
                     new Aspirant("Grisha", "Car Engineer", {"Engines"})
    };

    for (int i = 0; i < 3; ++i)
    {
        group[i]->Print();
        cout << endl;
        delete group[i];
    }


    return 0;
}
