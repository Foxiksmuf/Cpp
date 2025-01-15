#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr, int& porownania, int& przesuniecia) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int x = arr[i]; // x - warto��, dla kt�rej miejsca szukamy
        int j = i;

        while (j > 0 && x < arr[j - 1]) {
            porownania++; // Zliczamy por�wnania
            arr[j] = arr[j - 1]; // Elementy wi�ksze od x przesuwane s� na prawo o 1 pozycj�
            przesuniecia++; // Zliczamy przesuni�cia
            j--;
        }

        arr[j] = x;
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

    insertionSort(liczby, liczbaPorownan, liczbaPrzesuniec);

    std::cout << "Posortowane liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    std::cout << "Liczba por�wna�: " << liczbaPorownan << std::endl;
    std::cout << "Liczba przesuni��: " << liczbaPrzesuniec << std::endl;

    return 0;
}