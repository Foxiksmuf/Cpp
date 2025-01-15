#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

// Funkcja do generowania pliku DOT z listy s¹siedztwa
void generateDotFile(const std::unordered_map<int, std::vector<int>>& adjacencyList) {
    std::ofstream dotFile("E:\\szko³a\\png\\graph.dot");

    if (dotFile.is_open()) {
        dotFile << "graph G {\n";

        for (const auto& entry : adjacencyList) {
            int node = entry.first;
            const std::vector<int>& neighbors = entry.second;

            for (int neighbor : neighbors) {
                dotFile << "  " << node << " -- " << neighbor << ";\n";
            }
        }

        dotFile << "}\n";
        dotFile.close();
    }
    else {
        std::cerr << "Unable to open dot file for writing.\n";
    }
}

int main() {
    std::unordered_map<int, std::vector<int>> adjacencyList = {
        {0, {6, 9, 7}},
        {1, {7, 2, 8, 6}},
        {2, {1, 3}},
        {3, {2, 6, 5}},
        {4, {6, 9}},
        {5, {9, 7, 3}},
        {6, {0, 4, 3, 1}},
        {7, {1, 5, 9}},
        {8, {9, 1}},
        {9, {5, 8, 7, 0, 4}}
    };

    generateDotFile(adjacencyList);

    // Utwórz obraz grafu za pomoc¹ Graphviz na systemie Windows
    std::string command = "cmd /c \"C:\\Program Files (x86)\\Graphviz\\bin\\dot.exe\" -Tpng E:\\szko³a\\png\\graph.dot -o E:\\szko³a\\png\\graph.png";

    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Graph visualization created in E:\\szko³a\\png\\graph.png\n";
    }
    else {
        std::cerr << "Error executing system command.\n";
    }

    return 0;
}