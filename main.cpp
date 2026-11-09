#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    Library myLib;

    try {
        myLib.addBook("Кобзар", "Тарас Шевченко", "Основа", 1840);
        myLib.addBook("Тигролови", "Іван Багряний", "Прометей", 1944);
        myLib.addBook("Тіні забутих предків", "Михайло Коцюбинський", "Час", 1911);

        myLib.addBook("Помилкова Книга", "Автор", "Видавництво", 0);
    }
    catch (const char* msg) {
        cout << ">> Помилка: " << msg << "\n";
    }

    myLib.search("Іван Багряний");
    myLib.search("Кобзар");
    myLib.search("Час");
    myLib.search(1840);

    try {
        cout << "Зараз книг: " << myLib.getBookCount() << "\n";
        myLib = myLib - 1;
        cout << "Після списання: " << myLib.getBookCount() << " книг.\n";

        myLib = myLib - 50;
    }
    catch (const char* msg) {
        cout << ">> Помилка: " << msg << "\n";
    }

    return 0;
}