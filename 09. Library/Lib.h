#include <iostream>
#include "Book.h"
using namespace std;

#ifndef INC_09__LIBRARY_LIB_H
#define INC_09__LIBRARY_LIB_H

class Lib {
private:
    string name;
    string address;
    Book* books;
    int count_books;
public:
    Lib();
    Lib(string name, string address);

    Lib(const Lib & other){
        this->name = other.name;
        this->address = other.address;
        this->books = new Book[other.count_books];
        for (int i = 0; i < other.count_books; ++i) {
            this->books[i] = other.books[i];
        }
        this->count_books = other.count_books;
    }

    Lib(Lib && other){
        this->name = other.name;
        this->address = other.address;
        this->books = other.books;
        other.books = nullptr;
        this->count_books = other.count_books;
    }

    Lib& operator = (const Lib & other){
        this->name = other.name;
        this->address = other.address;
        this->books = new Book[other.count_books];
        for (int i = 0; i < other.count_books; ++i) {
            this->books[i] = other.books[i];
        }
        this->count_books = other.count_books;
        return *this;
    }
    void Show() const;
    void AddBook(Book b);
    ~Lib(){
        if(books != nullptr){
            delete [] books;
        }
    }
};


#endif //INC_09__LIBRARY_LIB_H
