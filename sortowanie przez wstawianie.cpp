#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr, int& porownania, int& przesuniecia) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int x = arr[i]; // x - wartoœæ, dla której miejsca szukamy
        int j = i;

        while (j > 0 && x < arr[j - 1]) {
            porownania++; // Zliczamy porównania
            arr[j] = arr[j - 1]; // Elementy wiêksze od x przesuwane s¹ na prawo o 1 pozycjê
            przesuniecia++; // Zliczamy przesuniêcia
            j--;
        }

        arr[j] = x;
    }
}

int main() {
    std::vector<int> liczby;

    int n;
    std::cout << "Ile liczb chcesz posortowaæ? ";
    std::cin >> n;

    std::cout << "WprowadŸ liczby: ";
    for (int i = 0; i < n; i++) {
        int liczba;
        std::cin >> liczba;
        liczby.push_back(liczba);
    }

    int liczbaPorownan = 0; // Licznik porównañ
    int liczbaPrzesuniec = 0; // Licznik przesuniêæ

    insertionSort(liczby, liczbaPorownan, liczbaPrzesuniec);

    std::cout << "Posortowane liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    std::cout << "Liczba porównañ: " << liczbaPorownan << std::endl;
    std::cout << "Liczba przesuniêæ: " << liczbaPrzesuniec << std::endl;

    return 0;
}