#include "Book.h"

Book::Book() {
    title = "none";
    author = "none";
    int pages = 0;
    int year = 0;
    genre = None;
}

Book::Book(string t, string a, int p, int y, Genre g) :title(t), author(a), pages(p), year(y), genre(g){}

void Book::ShowInfo() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Pages: " << pages << endl;
    cout << "Year: " << year << endl;
    cout << "Genre: " << genre << " ";
    switch(genre){
        case None:
            cout << "None" << endl;
            break;
        case Detective:
            cout << "Detective" << endl;
            break;
        case Adventure:
            cout << "Adventure" << endl;
            break;
        case Drama:
            cout << "Drama" << endl;
            break;
        case Comedy:
            cout << "Comedy" << endl;
            break;
        case History:
            cout << "History" << endl;
            break;
        case Horror:
            cout << "Horror" << endl;
            break;
        case Science:
            cout << "Science" << endl;
            break;
        case Biography:
            cout << "Biography" << endl;
            break;
        case Roman:
            cout << "Roman" << endl;
            break;
        case Fairytale:
            cout << "Fairytale" << endl;
            break;
        case Thriller:
            cout << "Thriller" << endl;
            break;
        case Fantasy:
            cout << "Fantasy" << endl;
            break;
    }
    cout << "----------------" << endl;
}
