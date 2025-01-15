#include <iostream>
#include <string>

using namespace std;

class Zamowienie
{
private:
    string nazwa_produktu;
    double cena_produktu;
    string data_zakupu;
    int liczba_sztuk;
public:
    void zapisz_dane() {
        cout << "Podaj nazwe produktu: ";
        cin >> nazwa_produktu;
        cout << "Podaj cene produktu: ";
        cin >> cena_produktu;
        cout << "Podaj date zakupu: ";
        cin >> data_zakupu;
        cout << "Podaj liczbe sztuk: ";
        cin >> liczba_sztuk;
    }

    void wyswietl_dane() {
        cout << "Nazwa produktu: " << nazwa_produktu << endl;
        cout << "Cena produktu: " << cena_produktu << endl;
        cout << "Data zakupu: " << data_zakupu << endl;
        cout << "Liczba sztuk: " << liczba_sztuk << endl;
    }

    string podaj_nazwe_produktu() {
        return nazwa_produktu;
    }

    double podaj_cene() {
        return cena_produktu;
    }

    string podaj_date_zakupu() {
        return data_zakupu;
    }

    int podaj_liczbe_sztuk() {
        return liczba_sztuk;
    }

    double podaj_koszt() {
        return cena_produktu * liczba_sztuk;
    }
};

int main()
{
    Zamowienie zam1;
    Zamowienie zam2;

    cout << "Zamowienie 1:" << endl;
    zam1.zapisz_dane();
    cout << endl;

    cout << "Zamowienie 2:" << endl;
    zam2.zapisz_dane();
    cout << endl;

    cout << "Dane zamowienia 1:" << endl;
    zam1.wyswietl_dane();
    cout << "Koszt zamowienia 1: " << zam1.podaj_koszt() << endl << endl;

    cout << "Dane zamowienia 2:" << endl;
    zam2.wyswietl_dane();
    cout << "Koszt zamowienia 2: " << zam2.podaj_koszt() << endl;

    return 0;
}