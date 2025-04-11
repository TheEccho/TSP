#pragma once

#include "common.hpp"

// Класс для представления графа
class Graph {
private:
    int numVertices;
    std::vector<std::vector<Edge>> adjacencyList;

public:
    // Конструктор
    explicit Graph(int vertices);
    
    // Конструктор из списка ребер
    Graph(int vertices, const std::vector<Edge>& edges);
    
    // Добавление ребра в граф
    void addEdge(const Edge& edge);
    
    // Получение всех соседей вершины
    const std::vector<Edge>& getNeighbors(int vertex) const;
    
    // Получение количества вершин
    int getNumVertices() const;
    
    // Загрузка графа из файла
    static std::optional<Graph> loadFromFile(const std::string& filename);
};

// Функция для вывода графа
void printGraph(const Graph& graph);
