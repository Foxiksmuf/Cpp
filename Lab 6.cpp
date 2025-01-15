#include <iostream>
#include <cstring>

using namespace std;

class Osoba {
private:
    char* imie;
    char* nazwisko;
    int wiek;

public:
    // konstruktor
    Osoba(const char* imie_in, const char* nazwisko_in, int wiek_in) {
        imie = new char[strlen(imie_in) + 1];
        strcpy_s(imie, strlen(imie_in) + 1, imie_in);
        nazwisko = new char[strlen(nazwisko_in) + 1];
        strcpy_s(nazwisko, strlen(nazwisko_in) + 1, nazwisko_in);
        wiek = wiek_in;
    }

    // destruktor
    ~Osoba() {
        delete[] imie;
        delete[] nazwisko;
    }

    // metoda wyœwietlaj¹ca dane obiektu
    void pokaz() {
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Wiek: " << wiek << endl;
    }

    // metoda zmieniaj¹ca imiê
    void zmien_imie(const char* imie_in) {
        delete[] imie;
        imie = new char[strlen(imie_in) + 1];
        strcpy_s(imie, strlen(imie_in) + 1, imie_in);
    }

    // konstruktor kopiuj¹cy
    Osoba(const Osoba& o) {
        imie = new char[strlen(o.imie) + 1];
        strcpy_s(imie, strlen(o.imie) + 1, o.imie);
        nazwisko = new char[strlen(o.nazwisko) + 1];
        strcpy_s(nazwisko, strlen(o.nazwisko) + 1, o.nazwisko);
        wiek = o.wiek;
    }
};

int main() {
    // utworzenie dwóch obiektów klasy Osoba
    Osoba o1("Adam", "Nowak", 25);
    Osoba o2 = o1;

    // zmiana imienia drugiego obiektu
    o2.zmien_imie("Krystian");

    // wyœwietlenie danych obu obiektów
    o1.pokaz();
    o2.pokaz();

    // utworzenie trzech obiektów klasy Osoba
    Osoba o3(o1);
    Osoba o4 = o1;

    // zmiana imienia drugiego i trzeciego obiektu
    o4.zmien_imie("Pawel");
    o3.zmien_imie("Michal");

    // wyœwietlenie danych wszystkich trzech obiektów
    o1.pokaz();
    o2.pokaz();
    o3.pokaz();

    return 0;
}