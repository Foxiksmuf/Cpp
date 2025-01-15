#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr, int& porownania, int& przesuniecia) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            porownania++; // Zliczamy por�wnania
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
            przesuniecia++; // Zliczamy przesuni�cia
        }
    }
}

int main() {
    std::vector<int> liczby;

    int n;
    std::cout << "Ile liczb chcesz posortowa�? ";
    std::cin >> n;

    std::cout << "Wprowad� liczby: ";
    for (int i = 0; i < n; i++) {
        int liczba;
        std::cin >> liczba;
        liczby.push_back(liczba);
    }

    int liczbaPorownan = 0; // Licznik por�wna�
    int liczbaPrzesuniec = 0; // Licznik przesuni��

    selectionSort(liczby, liczbaPorownan, liczbaPrzesuniec);

    std::cout << "Posortowane liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    std::cout << "Liczba por�wna�: " << liczbaPorownan << std::endl;
    std::cout << "Liczba przesuni��: " << liczbaPrzesuniec << std::endl;

    return 0;
}