#include "Lib.h"

Lib::Lib() {
    name = "no name";
    address = "no address";
    books = nullptr;
    count_books = 0;
}

Lib::Lib(string name, string address) {
    this->name = name;
    this->address = address;
    books = nullptr;
    count_books = 0;
}

void Lib::Show() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    for (int i = 0; i < count_books; ++i) {
        books[i].ShowInfo();
    }
}

void Lib::AddBook(Book b) {
    Book* temp = new Book[count_books + 1];
    for (int i = 0; i < count_books; ++i) {
        temp[i] = books[i];
    }
    temp[count_books] = b;
    if(books != nullptr){
        delete [] books;
    }
    books = temp;
    count_books++;
}
