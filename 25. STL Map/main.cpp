#include <iostream>
#include <map>

using namespace std;

map<string, int>::iterator FindByValue(map <string, int>& m, int value)
{
    for(map<string, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        if(i->second == value)
            return i;
    }
    return m.end();
}

int main()
{
    map<string, int> m;
    pair<string, int> p("Alex", 5);
    m.insert(p);
    m.insert(pair<string, int>("Oleg", 7));
    m.insert(make_pair("Petro",3));

    for(auto i : m)
    {
        cout << "Key: " << i.first << " Value: " << i.second << endl;

    }

    auto res = m.insert(pair<string, int>("Oleg", 15));

    if(res.second)
        cout << "Was added!" << endl;
    else
        cout << "Wasn't added.." << endl;

    cout << "Value: " << m["Oleg"] << endl;

    auto it = m.find("Oleg");

    if(it == m.end())
        cout << "Not found!" << endl;
    else
    {
        cout << "Was found!" << endl;
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        //it->first = "Ivanka";    !CONST
        it->second = 333;
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }

    it = FindByValue(m, 333);


    if(it != m.end())
        cout << "Key: " << it->first << " Value: " << it->second << endl;

    if(it != m.end())
        m.erase(it);

    cout << endl;

    for(auto i : m)
    {
        cout << "Key: " << i.first << " Value: " << i.second << endl;
    }










    return 0;
}
