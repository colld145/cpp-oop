#include <iostream>
#include "Book.h"
#include "Lib.h"
using namespace std;

Lib ShowLib(Lib library){
    Lib temp;
    // Some code ...
    return temp;
}

int main() {
    Book b1("Baskervil's dog", "Conan Doyle", 318, 1986, Detective);
    Book b2("Lord of the Rings", "John Tolkien", 400, 1933, Fantasy);
    Book b3("Harry Potter", "Joan Rowling", 800, 1997, Fairytale);
    Book b4("Little Prince", "Antoine De Saint-Exupery", 200, 1970, Fairytale);

    Lib lib("Junior Library", "Rivne, Kyivska 67a");
    lib.AddBook(b1);
    lib.AddBook(b2);
    lib.AddBook(b3);
    lib.AddBook(b4);
    lib.Show();



    return 0;
}
