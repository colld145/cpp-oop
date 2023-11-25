#include <iostream>
#include <list>
#include <iomanip>
using namespace std;


template <typename T>
ostream &operator<<(ostream& out, list<T> l)
{
    out << "[ ";
    for(auto n : l)
    {
        out << n << " ";
    }
    out << "]";
    return out;
}


void Show(list<int>& list1, list<int>& list2)
{
    cout << "List 1: ";

    list<int>::iterator iter;
    for( iter = list1.begin(); iter != list1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "List 2: ";

    for( iter = list2.begin(); iter != list2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << endl;

}


struct Book
{
        string name;
        string author;
        int pages;
};

bool CompareBookByName(const Book& b1, const Book& b2)
{
    return b1.name < b2.name;
}

bool CompareBookByAuthor(const Book& b1, const Book& b2)
{
    return b1.author < b2.author;
}

bool CompareBookByPages(const Book& b1, const Book& b2)
{
    return b1.pages < b2.pages;
}

int main()
{

    list<Book> library;

    library.assign({
        Book{"Harry Potter", "Johan Rowling", 800},
        Book{"Eneida", "Kotliarevskii", 400},
        Book{"The Godfather", "Mario Balotelli", 400},
    });

    cout << "-------- Original List ---------" << endl;

    for(Book book : library)
    {
        cout << left << setw(20) << book.name << setw(20) << book.author << setw(20) << book.pages << endl;
    }
    cout << endl;
    library.sort(CompareBookByName);
    for(Book book : library)
    {
        cout << left << setw(20) << book.name << setw(20) << book.author << setw(20) << book.pages << endl;
    }


//    list<int> n;
//    list<int> n2;
//
//    for (int i = 0; i < 10; ++i)
//    {
//        n.push_back(i);
//        n2.push_front(i);
//    }
//
//    Show(n,n2);
//
//    n.assign({11,21,31,41});
//
//    Show(n,n2);
//
//    n.erase(n.begin());
//
//    Show(n,n2);







    return 0;
}
