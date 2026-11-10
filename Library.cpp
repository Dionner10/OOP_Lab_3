#include "Library.h"
#include <iostream>

using namespace std;

Library::Library() {
    bookCount = 0;
}

void Library::addBook(string t, string a, string p, int y, int pg) {
    if (bookCount >= 100) {
        throw "Бібліотека переповнена! Неможливо додати більше книг.";
    }
    if (y < 1000 || y > 2026) {
        throw "Некоректний рік видання! Рік має бути від 1000 до 2026.";
    }
    
    books[bookCount].title = t;
    books[bookCount].author = a;
    books[bookCount].publisher = p;
    books[bookCount].year = y;
    bookCount++;
}

int Library::getYear(int index) const {
    if (index < 0 || index >= bookCount) {
        throw "Помилка читання: Індекс книги виходить за межі наявних!";
    }
    return books[index].year;
}

int Library::getBookCount() const {
    return bookCount;
}

Library& Library::operator+(int addAmount) {
    if (bookCount + addAmount > 100) {
        throw "Помилка (+): Перевищення ліміту полиць бібліотеки!";
    }
    bookCount += addAmount;
    return *this;
}

Library& Library::operator-(int removeAmount) {
    if (bookCount - removeAmount < 0) {
        throw "Помилка (-): Неможливо списати більше книг, ніж є у бібліотеці!";
    }
    bookCount -= removeAmount;
    return *this;
}

// Пошук одразу по трьох текстових полях
/*
void Library::search(string text) const {
    cout << "Пошук за текстом '" << text << "'\n";
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == text || books[i].author == text || books[i].publisher == text) {
            cout << "Знайдено: " << books[i].title << " - " << books[i].author 
                 << " (" << books[i].publisher << ", " << books[i].year << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Нічого не знайдено.\n";
}

// Перевантаження для пошуку за роком
void Library::search(int year) const {
    cout << "Пошук за роком '" << year << "'\n";
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year == year) {
            cout << "Знайдено: " << books[i].title << " - " << books[i].author 
                 << " (" << books[i].publisher << ", " << books[i].year << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Нічого не знайдено.\n";
}
*/
Book * Library::search(int year, int minPages) const {
    Book * result = new Book[10];
    int resultIndex = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year == year && books[i].pages > minPages) {
            result[resultIndex] = books[i];
            resultIndex++;
        }
    }
    return result;
}
