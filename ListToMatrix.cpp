#include <iostream>
#include <vector>

using namespace std;

// Funkcja do konwersji listy s�siedztwa na macierz s�siedztwa
vector<vector<int>> adjacencyListToMatrix(const vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();

    // Inicjalizacja macierzy s�siedztwa wype�nionej zerami
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    // Wype�nienie macierzy s�siedztwa
    for (int i = 0; i < numVertices; ++i) {
        for (int j : adjacencyList[i]) {
            adjacencyMatrix[i][j] = 1;
            adjacencyMatrix[j][i] = 1;  // Graf nieskierowany
        }
    }

    return adjacencyMatrix;
}

int main() {
    // Lista s�siedztwa
    vector<vector<int>> adjacencyList = {
        {6, 9, 7},
        {7, 2, 8, 6},
        {1, 3},
        {2, 6, 5},
        {6, 9},
        {9, 7, 3},
        {0, 4, 3, 1},
        {1, 5, 9},
        {9, 1},
        {5, 8, 7, 0, 4},
    };

    // Konwersja listy s�siedztwa na macierz s�siedztwa
    vector<vector<int>> adjacencyMatrix = adjacencyListToMatrix(adjacencyList);

    // Wy�wietlenie macierzy s�siedztwa
    cout << "Macierz s�siedztwa:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}