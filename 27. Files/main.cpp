#include <iostream>
#include <fstream>
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

    void ShowInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Place: " << place << endl;
        cout << "Weight: " << weight << endl;
    }

    friend ostream &operator << (ostream & out, const Animal& animal);
    friend istream &operator >> (istream & out, Animal& animal);
};

ostream &operator << (ostream & out, const Animal& animal)
{
    out << animal.name << " " << animal.place << " " << animal.weight;
    return out;
}

istream &operator >> (istream& in, Animal& animal)
{
    in >> animal.name >> animal.place >> animal.weight;
    return in;
}

class Zoo
{
private:
    string name;
    Animal* animals;
    int amount_of_animals;
public:
    Zoo(string name):name(name), animals(nullptr), amount_of_animals(0) {}
    void AddAnimal(Animal animal)
    {
        Animal* temp = new Animal[amount_of_animals + 1];
        for (int i = 0; i < amount_of_animals; ++i)
        {
            temp[i] = animals[i];
        }
        temp[amount_of_animals] = animal;
        if(animals != nullptr)
            delete [] animals;
        amount_of_animals++;
        animals = temp;
    }

    void ShowZoo() const
    {
        for (int i = 0; i < amount_of_animals; ++i)
        {
            animals[i].ShowInfo();
        }
    }
    
    ~Zoo()
    {
        for (int i = 0; i < amount_of_animals; ++i)
        {
            if(animals != nullptr)
                delete [] animals;
        }
    }

    void Save() const
    {
        ofstream out("zoo.txt", ios_base::out);
        out << name << endl;
        out << amount_of_animals << endl;
        for (int i = 0; i < amount_of_animals; ++i)
        {
            out << animals[i] << endl;
        }
        out.close();
    }

    void Load()
    {
        ifstream in("zoo.txt", ios_base::in);
        //char buff[255];
        getline(in, name);
        in >> amount_of_animals;
        if(animals != nullptr)
            delete [] animals;

        animals = new Animal[amount_of_animals];
        for (int i = 0; i < amount_of_animals; ++i)
        {
            in >> animals[i];
        }
        in.close();
    }

    void SaveBinary()
    {
        ofstream out("Zoo.bin", ios_base::out | ios_base::binary);
        out.write((char*)&name, sizeof(name));
        out.write((char*)&amount_of_animals, sizeof(amount_of_animals));
        for (int i = 0; i < amount_of_animals; ++i)
        {
            out.write((char*)&animals[i], sizeof(animals[i]));
        }
        out.close();
    }

    void LoadBinary()
    {
        ifstream in("Zoo.bin", ios_base::in | ios_base::binary);
        in.read((char*)&name, sizeof(name));
        in.read((char*)&amount_of_animals, sizeof(amount_of_animals));
        if(animals != nullptr)
            delete [] animals;

        animals = new Animal[amount_of_animals];
        for (int i = 0; i < amount_of_animals; ++i)
        {
            in.read((char*)&animals[i], sizeof(animals[i]));
        }
        in.close();
    }

};



int main()
{
//    Animal animal("Tom", "Flat", 6);
//
//    Zoo zoo("Rivne Zoo");
//    zoo.AddAnimal(animal);
//    zoo.AddAnimal(Animal("Lion Alex", "Madagascar", 150));
//    zoo.AddAnimal(Animal("Marty", "Madagascar", 100));
//    zoo.AddAnimal(Animal("Skeeper", "Madagascar", 10));
//
//    zoo.ShowZoo();
//    zoo.SaveBinary();
    Zoo test("Rivne Zoo");
    test.LoadBinary();
    test.ShowZoo();


    //zoo.Save();


    return 0;
}
