#include <iostream>
#include <string>
#include <array>

using namespace std;

class Silnik {
private:
    int pojemnosc;
    string producent;

public:
    Silnik(int pojemnosc, string producent) : pojemnosc(pojemnosc), producent(producent) {};

    int getPojemnosc() {
        return pojemnosc;
    }

    string getProducent() {
        return producent;
    }
};

class Urzadzenie {
private:
    const string producent;
    int obroty;
    Silnik silnik;

public:
    Urzadzenie(string producent, int obroty, Silnik silnik) : producent(producent), obroty(obroty), silnik(silnik) {};

    string getProducent() {
        return producent;
    }

    int getObroty() {
        return obroty;
    }

    Silnik getSilnik() {
        return silnik;
    }
};

void wyszukaj(array<Urzadzenie, 6> urzadzenia, string producentSzukany) {
    cout << "Szukane urzadzenia producenta: " << producentSzukany << endl;
    for (int i = 0; i < urzadzenia.size(); i++) {
        if (urzadzenia[i].getProducent() == producentSzukany) {
            cout << "Producent Urzadzenia: " << urzadzenia[i].getProducent() << endl;
            cout << "Ilosc obrotow: " << urzadzenia[i].getObroty() << endl;
            cout << "Producent Silnika: " << urzadzenia[i].getSilnik().getProducent() << endl;
            cout << "Pojemnosc Silnika: " << urzadzenia[i].getSilnik().getPojemnosc() << endl;
            cout << "---------------------" << endl;
        }
    }
}

int main() {
    Silnik s1(2, "Producent 1");
    Silnik s2(4, "Producent 1");
    Silnik s3(2, "Producent 2");

    Urzadzenie u1("Producent 1", 2000, s1);
    Urzadzenie u2("Producent 1", 1000, s2);
    Urzadzenie u3("Producent 2", 1500, s3);
    Urzadzenie u4("Producent 2", 1000, s1);
    Urzadzenie u5("Producent 3", 500, s2);
    Urzadzenie u6("Producent 3", 1000, s3);

    array<Urzadzenie, 6> urzadzenia = { u1, u2, u3, u4, u5, u6 };

    wyszukaj(urzadzenia, "Producent 1");

    return 0;
}