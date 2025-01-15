#include <math.h>
#include <iostream>


using namespace std;
double iloraz(double a, double b, bool& blad) {
    if (b == 0) {
        blad = true;
    }
    else {
        return a / b;
    }

}
double pierwiastek_kwadratowy(double a, bool& blad) {
    if (a < 0) {
        blad = true;
    }
    else {
        return sqrt(a);
    }
}
double potegowanie(double a, double b, bool& blad) {
    if (a == 0) {
        blad = true;
    }
    else {
        return pow(a, b);
    }
}
long ilocznyn_skalarny(int a, int b, int c, int d) {
    return a * c + b * d;
}


int main() {
    int a, b, c, d,dzialanie;
    cout << "1)Iloraz" << endl << "2)Pierwiastek" << endl << "3)Potegowanie" << endl << "4)Iloczyn Skalarny" << endl;
    cin >> dzialanie;
    bool blad = false;
    // iloraz
    if (dzialanie == 1) {
        cout << "Podaj licznik: " << endl;
        cin >> a;
        cout << "Podaj mianownik: ";
        cin >> b;
        double wynik1 = iloraz(a, b, blad);
        if (blad == true) {
            cout << "Nie dziel przez 0!"<<endl;
        }
        else {
            cout << " a " "/" " b " << "jest rowne : "<< " " << wynik1;
        }
    }
    // pierwiastek kwadratowy
    else if (dzialanie == 2) {
        cout << "pierwiastek z jakiej liczby chciasz wykonac: "<<endl;
        cin >> a;
        double wynik2 = pierwiastek_kwadratowy(a, blad);
        if (blad == true) {
            cout << "Nie ma pierwiastka z liczby ujemnej!!!"<<endl;
        }
        else {
            cout << "Pierwiastek z liczby: "<<endl << a << " wynosi: " << wynik2;
        }
    }
    //potegowanie
    else if (dzialanie == 3) {
        cout << "podaj podstawe potegi: "<<endl;
        cin >> a;
        cout << "podaj wykladnik potegi: "<<endl;
        cin >> b;
        long wynik3 = potegowanie(a, b, blad);
        if (blad == true) {
            cout << "nie mozna potegowac liczby rownej: 0 "<<endl;
        }
        else {
            cout << "liczba: "<<endl << a << " podniesiona do potegi: " << b << " jest rowna: " << wynik3;
        }
    }
    //ilocznyn skalarny dwoch wektorow
    else if (dzialanie == 4) {
        cout << "podaj x wektora A: "<< endl;
        cin >> a;
        cout << "podaj y wektora A: "<< endl;
        cin >> b;
        cout << "podaj x wektora B: "<< endl;
        cin >> c;
        cout << "podaj y wektora B: "<< endl;
        cin >> d;
        long wynik4 = ilocznyn_skalarny(a, b, c, d);
        cout << "Iloczyn skalarny"<<endl<<" wektora A = [" << a << ", " << b << "] i wektora B = [" << c << ", " << d << "] jest rowny " << wynik4;
    }
    else {
        cout << "wybierz dzialanie od 1 do 4";
    }
}