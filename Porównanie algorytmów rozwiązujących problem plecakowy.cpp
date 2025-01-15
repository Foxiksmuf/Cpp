#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// Struktura reprezentuj¹ca przedmiot
struct Przedmiot {
    int waga;
    int wartosc;
};

// Funkcja do generowania losowych danych
void generujLosoweDane(int n, vector<Przedmiot>& przedmioty, int& pojemnosc) {
    przedmioty.clear();
    for (int i = 0; i < n; ++i) {
        Przedmiot przedmiot;
        przedmiot.waga = rand() % 100 + 1;  // losowa waga z przedzia³u <1, 100>
        przedmiot.wartosc = rand() % 100 + 1;   // losowa wartoœæ z przedzia³u <1, 100>
        przedmioty.push_back(przedmiot);
    }
    pojemnosc = rand() % 10000 + 1;  // losowa pojemnoœæ z przedzia³u <1, 10000>
}

// Algorytm dok³adny - programowanie dynamiczne (APD)
int plecakAPD(int pojemnosc, const vector<Przedmiot>& przedmioty) {
    int n = przedmioty.size();
    vector<vector<int>> dp(n + 1, vector<int>(pojemnosc + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= pojemnosc; ++w) {
            if (przedmioty[i - 1].waga <= w) {
                dp[i][w] = max(dp[i - 1][w], przedmioty[i - 1].wartosc + dp[i - 1][w - przedmioty[i - 1].waga]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][pojemnosc];
}

// Algorytm przybli¿ony - algorytm zach³anny (AZ)
int plecakAZ(int pojemnosc, vector<Przedmiot>& przedmioty) {
    sort(przedmioty.begin(), przedmioty.end(), [](const Przedmiot& a, const Przedmiot& b) {
        return (double)a.wartosc / a.waga > (double)b.wartosc / b.waga;
        });

    int sumaWartosci = 0;
    int aktualnaWaga = 0;

    for (const auto& przedmiot : przedmioty) {
        if (aktualnaWaga + przedmiot.waga <= pojemnosc) {
            aktualnaWaga += przedmiot.waga;
            sumaWartosci += przedmiot.wartosc;
        }
    }

    return sumaWartosci;
}

// Algorytm przy u¿yciu programowania zach³annego (AP)
int plecakAP(int pojemnosc, const vector<Przedmiot>& przedmioty) {
    vector<pair<double, int>> wartoscNaMase;

    for (size_t i = 0; i < przedmioty.size(); ++i) {
        wartoscNaMase.push_back({ static_cast<double>(przedmioty[i].wartosc) / przedmioty[i].waga, i });
    }

    sort(wartoscNaMase.begin(), wartoscNaMase.end(), greater<pair<double, int>>());

    int sumaWartosci = 0;
    int aktualnaWaga = 0;

    for (const auto& wnm : wartoscNaMase) {
        int i = wnm.second;
        if (aktualnaWaga + przedmioty[i].waga <= pojemnosc) {
            aktualnaWaga += przedmioty[i].waga;
            sumaWartosci += przedmioty[i].wartosc;
        }
    }

    return sumaWartosci;
}

int main() {
    srand(time(nullptr));

    // Wartoœci danych
    vector<int> n_wartosci = { 15, 25, 100, 1000, 10000 };
    vector<int> b_wartosci = { 100, 1000, 10000 };

    // Pêtle testuj¹ce algorytmy
    for (int n : n_wartosci) {
        for (int b : b_wartosci) {
            vector<Przedmiot> przedmioty;
            int pojemnosc;
            generujLosoweDane(n, przedmioty, pojemnosc);

            // Pomiar czasu dla APD
            clock_t start_time = clock();
            int apd_wynik = plecakAPD(pojemnosc, przedmioty);
            clock_t end_time = clock();
            double apd_czas = double(end_time - start_time) / CLOCKS_PER_SEC;

            // Pomiar czasu dla AZ
            start_time = clock();
            int az_wynik = plecakAZ(pojemnosc, przedmioty);
            end_time = clock();
            double az_czas = double(end_time - start_time) / CLOCKS_PER_SEC;

            // Pomiar czasu dla AP
            start_time = clock();
            int ap_wynik = plecakAP(pojemnosc, przedmioty);
            end_time = clock();
            double ap_czas = double(end_time - start_time) / CLOCKS_PER_SEC;

            // Obliczenie optymalnego wyniku
            start_time = clock();
            int optymalny_wynik = plecakAPD(pojemnosc, przedmioty);
            end_time = clock();
            double optymalny_czas = double(end_time - start_time) / CLOCKS_PER_SEC;

            // Wypisanie wyników
            cout << "n=" << n << ", b=" << b << " - APD wynik: " << apd_wynik
                << ", APD czas: " << apd_czas << "s, AZ wynik: " << az_wynik
                << ", AZ czas: " << az_czas << "s, AP wynik: " << ap_wynik
                << ", AP czas: " << ap_czas << "s, Optymalny wynik: " << optymalny_wynik
                << ", Optymalny czas: " << optymalny_czas << "s" << endl;

            // Wzglêdne odchylenie od optimum dla AZ
            double wzgledne_odchylenie = ((double)az_wynik - optymalny_wynik) / optymalny_wynik * 100.0;
            cout << "Wzglêdne odchylenie od optimum dla AZ: " << wzgledne_odchylenie << "%" << endl;
        }
    }

    return 0;
}