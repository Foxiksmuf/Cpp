#include <iostream>
#include <cstring>

using namespace std;

class Nazwisko {
protected:
    char* nazwisko;
public:
    Nazwisko(const char* n) {
        size_t len = strlen(n) + 1;
        nazwisko = new char[len];
        strcpy_s(nazwisko, len, n);
        cout << "Konstruktor klasy bazowej Nazwisko: " << nazwisko << endl;
    }
    virtual ~Nazwisko() {
        cout << "Destruktor klasy bazowej Nazwisko: " << nazwisko << endl;
        delete[] nazwisko;
    }
};

class Pelne : public Nazwisko {
private:
    char* imie;
public:
    Pelne(const char* i, const char* n) : Nazwisko(n) {
        size_t len = strlen(i) + 1;
        imie = new char[len];
        strcpy_s(imie, len, i);
        cout << "Konstruktor klasy pochodnej Pelne: " << imie << " " << nazwisko << endl;
    }
    ~Pelne() {
        cout << "Destruktor klasy pochodnej Pelne: " << imie << endl;
        delete[] imie;
    }
};

int main() {
    Nazwisko* osoba = new Pelne("Jan", "Kowalski");
    delete osoba;
    return 0;
}