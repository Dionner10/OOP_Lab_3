#pragma once
#include <string>

class Library {
private:
    struct Book {
        std::string title;
        std::string author;
        std::string publisher;
        int year;
    };

    Book books[100];
    int bookCount;

public:
    Library();

    void addBook(std::string t, std::string a, std::string p, int y);
    int getYear(int index) const;
    int getBookCount() const;

    Library& operator+(int addAmount);
    Library& operator-(int removeAmount);

    void search(std::string text) const;
    void search(int year) const;
};