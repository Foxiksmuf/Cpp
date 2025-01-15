#include <iostream>
#include <vector>

using namespace std;

// Funkcja do konwersji listy s¹siedztwa na macierz s¹siedztwa
vector<vector<int>> adjacencyListToMatrix(const vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();

    // Inicjalizacja macierzy s¹siedztwa wype³nionej zerami
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    // Wype³nienie macierzy s¹siedztwa
    for (int i = 0; i < numVertices; ++i) {
        for (int j : adjacencyList[i]) {
            adjacencyMatrix[i][j] = 1;
            adjacencyMatrix[j][i] = 1;  // Graf nieskierowany
        }
    }

    return adjacencyMatrix;
}

int main() {
    // Lista s¹siedztwa
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

    // Konwersja listy s¹siedztwa na macierz s¹siedztwa
    vector<vector<int>> adjacencyMatrix = adjacencyListToMatrix(adjacencyList);

    // Wyœwietlenie macierzy s¹siedztwa
    cout << "Macierz s¹siedztwa:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}