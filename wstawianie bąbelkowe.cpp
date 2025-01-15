#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr, int& porownania, int& przesuniecia) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            porownania++; // Zliczamy porównania
            if (arr[j - 1] > arr[j]) {
                int x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                przesuniecia++; // Zliczamy przesuniêcia
            }
        }
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

    bubbleSort(liczby, liczbaPorownan, liczbaPrzesuniec);

    std::cout << "Posortowane liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    std::cout << "Liczba porównañ: " << liczbaPorownan << std::endl;
    std::cout << "Liczba przesuniêæ: " << liczbaPrzesuniec << std::endl;

    return 0;
}