#include <iostream>
using namespace std;

int main()
{
    string str = "1231234567890-sadfdghijk;l;x";
    cout << str.size() << endl;
    cout << str.length() << endl;
    cout << str.capacity();

    return 0;
}
