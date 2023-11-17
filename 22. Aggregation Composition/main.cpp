#include <iostream>
using namespace std;


class Document
{
private:
    string name;
    string format;
    int pages;
public:
    Document():name("None"), format("No format"), pages(0) {}

    Document(string n, string f, int p):name(n), format(f)
    {
        this->pages = p > 0 ? p : 0;
    }

    void ShowInfo() const
    {
        cout << "------- Document " << name << " --------" << endl;
        cout << "Format: " << format << endl;
        cout << "Pages: " << pages << endl;
    }
};


class Cartridge
{
public:
    enum Type{None, Standard, XL};
private:
    string color;
    float volume;
    Type type;
public:
    Cartridge():color("None"), volume(0), type(None){}

    Cartridge(string color, float volume, Type type):color(color), volume(volume), type(type){}

    void ShowInfo() const
    {
        cout << "Color: " << color << endl;
        cout << "Volume: " << volume << endl;
        cout << "Type: ";
        switch (type)
        {
            case Cartridge::None:
                cout << "None" << endl;
                break;
            case Cartridge::Standard:
                cout << "Standard" << endl;
                break;
            case Cartridge::XL:
                cout << "XL" << endl;
                break;
        }
    }

};


class Scanner
{
private:
    float resolution;
    float height, width;
public:
    Scanner():resolution(0), height(0), width(0) {}

    Scanner(float r, float h, float w):resolution(r), height(h), width(w) {}

    void ShowInfo() const
    {
        cout << "Scan Resolution" << resolution << " dpi" << endl;
        cout << "Scan Area: height = " << height << " mm, width = " << width << " mm" << endl;

    }
};


class Printer
{
    string model;
    Cartridge* cartridges;
    int count_cartridges;
    Scanner scanner;
    Document* doc;
public:
    Printer():model("None"), cartridges(nullptr), count_cartridges(0), doc(nullptr) {}

    Printer(string model, float r, float h, float w):doc(nullptr)
    {
        this->model = model;
        scanner = Scanner(r,h,w);

        count_cartridges = 4;
        cartridges = new Cartridge[count_cartridges];

        cartridges[0] = Cartridge("Black", 300, Cartridge::XL);
        cartridges[1] = Cartridge("Red", 100, Cartridge::Standard);
        cartridges[2] = Cartridge("Green", 100, Cartridge::Standard);
        cartridges[3] = Cartridge("Blue", 100, Cartridge::Standard);
    }

    void AddToQueue(Document* doc)
    {
        this->doc = doc;
    }

    void Scan()
    {
        cout << "Scanning..." << endl;
    }

    void PrintDocument()
    {
        if(doc == nullptr)
            cout << "There aren't any documents to Print..." << endl;
        else
        {
            cout << "Printing a document..." << endl;
            doc->ShowInfo();
        }

    }

    void Cancel()
    {
        doc = nullptr;
    }


    void Setting()
    {
        cout << "Printing with setting..." << endl;
        for (int i = 0; i < count_cartridges; ++i)
        {
            cartridges[i].ShowInfo();
        }
    }

    ~Printer()
    {
        if(cartridges != nullptr)
            delete [] cartridges;
    }
};


// -----------------------


class Driver
{
    string full_name;
    int age;
    int drive_exp;
public:
    Driver():full_name("No name"), age(0), drive_exp(0) {}

    Driver(string full_name, int age, int drive_exp):full_name(full_name), age(age), drive_exp(drive_exp) {}

    void ShowInfo() const
    {
        cout << "Full name: " << full_name << endl;
        cout << "Age: " << age << endl;
        cout << "Drive experience: " << drive_exp << endl;
    }
};


class Engine
{
private:
    float volume;
    string fuel_type;
public:
    Engine():volume(0), fuel_type("No fuel type") {}

    Engine(float v, string fuel_type):volume(v), fuel_type(fuel_type){}

    void ShowInfo() const
    {
        cout << "Engine volume: " << volume << " l" << endl;
        cout << "Fuel type: " << fuel_type << endl;
    }
};

class Wheel
{
private:
    float radius;
public:
    Wheel():radius(0) {}

    Wheel(float r):radius(r) {}

    void ShowInfo() const
    {
        cout << "Wheel radius: " << radius << " cm" << endl;
    }
};

class Door
{
private:
    string color;
public:
    Door():color("No color") {}

    Door(string c): color(c) {}

    void ShowInfo() const
    {
        cout << "Door color: " << color << endl;
    }
};

class Body
{
private:
    string body_type;
    string color;
public:
    Body():body_type("No body"), color("No color") {}

    Body(string b, string c):body_type(b), color(c) {}

    void ShowInfo() const
    {
        cout << "Color: " << color << endl;
        cout << "Body type: " << body_type << endl;
    }
};

class Headlight
{
private:
    string headlight_type;
public:
    Headlight():headlight_type("No headlight") {}

    Headlight(string h):headlight_type(h) {}

    void ShowInfo() const
    {
        cout << "Lights type: " << headlight_type << endl;
    }
};

class Car
{
private:
    Driver* driver;
    string brand;
    string model;
    Headlight* lights;
    Door* doors;
    Engine engine;
    Wheel* wheels;
    Body body;
    const int count_doors = 4;
    const int count_lights = 4;
    const int count_wheels = 4;

public:
    Car():driver(nullptr),brand("No brand"),model("No model"), lights(nullptr), doors(nullptr), wheels(nullptr) {}

    Car(string brand, string model, string color, string body,  float engine, string fuel_type): driver(nullptr)
    {
        this->brand = brand;
        this->model = model;
        this->engine = Engine(engine, fuel_type);
        this->body = Body(body, color);

        string light_types = "LED";
        lights = new Headlight[count_lights];
        lights[0] = Headlight(light_types);
        lights[1] = Headlight(light_types);
        lights[2] = Headlight(light_types);
        lights[3] = Headlight(light_types);

        doors = new Door[count_doors];
        doors[0] = Door(color);
        doors[1] = Door(color);
        doors[2] = Door(color);
        doors[3] = Door(color);

        int wheel_radius = 30;
        wheels = new Wheel[count_wheels];
        wheels[0] = Wheel(wheel_radius);
        wheels[1] = Wheel(wheel_radius);
        wheels[2] = Wheel(wheel_radius);
        wheels[3] = Wheel(wheel_radius);


    }

    void ShowInfo() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        body.ShowInfo();
        engine.ShowInfo();
        wheels[0].ShowInfo();
        lights[0].ShowInfo();
        doors[0].ShowInfo();

    }

    void AddDriver(Driver* driver)
    {
        this->driver = driver;
    }

    void PrintDriver()
    {
        if(driver == nullptr)
            cout << "There isn't a driver." << endl;
        else
        {
            cout << "--------- Driver -----------" << endl;
            driver->ShowInfo();
        }
    }

    ~Car()
    {
        delete [] lights;
        delete [] doors;
        delete [] wheels;
    }
};



int main()
{
//    Printer printer("Canon", 300, 50, 40);
//    printer.Scan();
//
//    Document doc("C++ for Beginners", "A4", 1500);
//    Document doc2("Passport", "A5", 4);
//
//    printer.AddToQueue(&doc);
//    printer.Cancel();
//
//    printer.PrintDocument();
//
//    printer.AddToQueue(&doc2);
//
//    printer.PrintDocument();

    // ----------------------------------

    Car car("BMW", "3", "Gray", "Sedan", 3, "Diesel");
    car.ShowInfo();
    Driver driver = Driver("Alex", 23, 5);
    car.AddDriver(&driver);
    car.PrintDriver();

    return 0;
}
