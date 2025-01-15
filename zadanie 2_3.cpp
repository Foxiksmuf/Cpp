#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    std::vector<int> liczby;

    // Inicjowanie generatora liczb losowych
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generowanie 100 000 losowych liczb i umieszczanie ich w wektorze
    for (int i = 0; i < 100000; i++) {
        int liczba = std::rand();
        liczby.push_back(liczba);
    }

    std::cout << "Wygenerowane liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    clock_t start = clock(); // Pocz¹tek pomiaru czasu

    selectionSort(liczby);

    clock_t end = clock(); // Koniec pomiaru czasu

    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Posortowane liczby: ";
    for (int liczba : liczby) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    std::cout << "Czas wykonania sortowania: " << elapsed_secs << " sekundy" << std::endl;

    return 0;
}