#include <iostream>


using namespace std;

struct COORD
{
    int X;
    int Y;
};

class Hero
{
private:
    int hp;
    int h, w;
    COORD position;
    string name;
    char symbol;
public:
    Hero(): hp(0), h(0), w(0), position({0, 0}), name("No Name"),
    symbol('#') {}

    Hero(string name, int h, int w, char symbol): hp(100), position({0, 0}),
    name(name), symbol(symbol)
    {
        this->h = h >= 1 ? h : 1;
        this->w = w >= 1 ? w : 1;
    }

    void ShowInfo() const
    {
        cout << "------------ Player [" << name << "] Hp : " << hp << "------------" << endl;
    }

    void Print() const
    {
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }

    void Move(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }

};


int main()
{




    return 0;
}
