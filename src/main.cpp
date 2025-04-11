#include "graph.hpp"

int main(int argc, char* argv[]) {
    std::string filename;
    
    if (argc > 1) {
        filename = argv[1];
    } else {
        std::cout << "Введите имя файла с данными графа: ";
        std::cin >> filename;
    }
    
    auto graph = Graph::loadFromFile(filename);
    
    if (!graph) {
        std::cerr << "Не удалось загрузить граф из файла " << filename << std::endl;
        return 1;
    }
    
    printGraph(*graph);
    
    return 0;
}
