#include <iostream>
#include <map>
#include <list>
#include <fstream>
using namespace std;

/*Використовуючи контейнер map реалізувати програму - словник.
Програма повинна у вигляді меню надавати наступні можливості:
- додати слово з перекладами;
- знайти переклади слова;
- додати переклад до існуючого слова;
- видалити слово разом зі всіма перекладами;
- показавати всі слова які наявні в словнику;
- *читання і запис словника в файл.

Для реалізації даного функціоналу, створити клас Dictionary
який містить
колекцію слів зі списком перекладів та всі необхідні методи.*/

class Dictionary
{
private:
    string name;
    map<string, list<string>> words;
public:
    Dictionary(string name):name(name) {}

    void Print() const
    {
        cout << "Dictionary: " << name << endl;
        for(auto pair : words)
        {
            cout << pair.first << " - ";
            for(string t : pair.second)
            {
                cout << t << ", ";
            }
            cout << endl;
        }
    }

    void AddWord(string word, initializer_list<string> translate)
    {
        words.insert(make_pair(word, list<string>(translate)));
    }

    void AddTranslate(string word, string translate)
    {
        words[word].push_back(translate);
    }

    bool isExist(string word)
    {
        return words.find(word) != words.end();
    }


    friend ostream &operator << (ostream& out, const Dictionary& d);
    friend istream &operator >> (istream& in, Dictionary& d);
};

ostream &operator << (ostream& out, const Dictionary& d)
{
    out << d.name << endl;
    for(auto pair : d.words)
    {
        out << pair.first << endl;
        for(string t : pair.second)
        {
            out << t << endl;
        }
        out << "|" << endl;
    }
    return out;
}

istream &operator >> (istream& in, Dictionary& d)
{
    string end = "|";
    getline(in, d.name);
    while(!in.eof())
    {
        string word;
        getline(in, word);
        if(word.empty()) break;
        list<string> list;
        string translate = end;
        do
        {
            getline(in, translate);
            if(translate != end)
                list.push_back(translate);

        } while(translate != end);
        d.words.insert(make_pair(word, list));
    }
    return in;
}

int main()
{


//    Dictionary dict("English-Ukrainian");
//    dict.AddWord("run", {"bigty", "zapustyty", "keruvaty"});
//    dict.AddWord("make", {"robyty", "vyrib", "forma"});
//    dict.AddWord("mind", {"rozum", "hluzd", "dumka"});
//    dict.AddWord("ride", {"jizdyty", "katannia", "oblava"});
//    dict.AddWord("bad", {"pohano", "amoralno", "zipsovanyi", "brydkii"});
//
//    dict.Print();
//
//    string input = "";
//    cout << "Enter a word to add a translate: ";
//    getline(cin, input);
//
//    if(!dict.isExist(input))
//        cout << "The word hasn't found!" << endl;
//    else
//    {
//        string translate = "";
//        do
//        {
//            cout << "Enter a translate: ";
//            getline(cin, translate);
//            if(!translate.empty())
//                dict.AddTranslate(input, translate);
//
//
//        } while (!translate.empty());
//    }
//    dict.Print();
//
//    ofstream out("Dictionary.txt");
//    out << dict;
//    out.close();

    Dictionary dict("English-Ukrainian");
    ifstream in("Dictionary.txt");
    in >> dict;
    in.close();
    dict.Print();

    bool exit = false;
    while(!exit)
    {
        int choice = 0;
        cout << "1. Add a word\n2. Add a translate\n3. Find a translate\n"
                "4. Delete a word\n5. Show all words\n\n0. Exit\n\nEnter a choice: ";
        cin >> choice;
        string new_word = "";
        string new_words_translate = "";
        string input = "";
        string translate = "";

        switch (choice)
        {
            case 1:
                cout << "Enter a new word to append: ";

                cin >> new_word;
                cout << "Enter a new words translate: ";
                cin >> new_words_translate;
                if(dict.isExist(new_word))
                {
                    cout << "The word is exist." << endl;
                    break;
                }
                else
                {
                    dict.AddWord(new_word, {new_words_translate});
                }
                break;
            case 3:
                cout << "Enter a word to add a translate: ";
                getline(cin, input);
                if(!dict.isExist(input))
                    cout << "The word hasn't found!" << endl;
                else {
                    do {
                        cout << "Enter a translate: ";
                        getline(cin, translate);
                        dict.AddTranslate(input, translate);
                    } while (!translate.empty());
                }
                break;
            case 5:
                dict.Print();
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Incorrect choice! Try again." << endl;
                break;
        }
    }

    /*
    map<string, list<string>> dict;

    string word = "run";
    list<string> meanings = list<string>({"bigty", "zapustyty", "keruvaty"});
    dict.insert(make_pair(word, meanings));
    dict.insert(make_pair("make", list<string>({"robyty", "vyrib", "forma"})));
    dict.insert(make_pair("mind", list<string>({"rozum", "hluzd", "dumka"})));
    dict.insert(make_pair("ride", list<string>({"jizdyty", "katannia", "oblava"})));
    dict.insert(make_pair("bad", list<string>({"pohano", "amoralno", "zipsovanyi", "brydkii"})));


    for(string str : dict["mind"])
    {
        cout << str << " ";
    }
    cout << endl;

    string input = "";
    cout << "Enter a word to add a translate: ";
    getline(cin, input);

    if(dict.find(input) == dict.end())
        cout << "The word hasn't found!" << endl;
    else
    {
        string translate = "";
        do
        {
            cout << "Enter a translate: ";
            getline(cin, translate);
            dict[input].push_back(translate);


        } while (!translate.empty());
    }

    for(string str : dict[input])
    {
        cout << str << " ";
    }
    cout << endl;
     */




    return 0;
}
