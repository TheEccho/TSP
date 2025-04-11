#include "graph.hpp"
#include <iomanip>
#include <algorithm>

Graph::Graph(int vertices) : numVertices(vertices) {
    adjacencyList.resize(vertices);
}

Graph::Graph(int vertices, const std::vector<Edge>& edges) : Graph(vertices) {
    for (const auto& edge : edges) {
        addEdge(edge);
    }
}

void Graph::addEdge(const Edge& edge) {
    if (edge.from >= numVertices || edge.to >= numVertices) {
        throw std::out_of_range("Vertex index out of range");
    }
    adjacencyList[edge.from].push_back(edge);
}

const std::vector<Edge>& Graph::getNeighbors(int vertex) const {
    if (vertex >= numVertices) {
        throw std::out_of_range("Vertex index out of range");
    }
    return adjacencyList[vertex];
}

int Graph::getNumVertices() const {
    return numVertices;
}

std::optional<Graph> Graph::loadFromFile(const std::string& filename) {
    auto edges = readGraphFromFile(filename);
    if (!edges) {
        return std::nullopt;
    }
    
    // Найдем максимальный индекс вершины
    int maxVertex = 0;
    for (const auto& edge : *edges) {
        maxVertex = std::max(maxVertex, std::max(edge.from, edge.to));
    }
    
    // Создаем граф с n+1 вершинами (учитывая вершину с индексом 0)
    return Graph(maxVertex + 1, *edges);
}

// Реализация функции чтения из файла
std::optional<std::vector<Edge>> readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return std::nullopt;
    }
    
    int numVertices;
    file >> numVertices;
    
    if (file.fail()) {
        std::cerr << "Ошибка чтения количества вершин" << std::endl;
        return std::nullopt;
    }
    
    std::vector<Edge> edges;
    int from, to;
    double distance, time, cost;
    
    while (file >> from >> to >> distance >> time >> cost) {
        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            std::cerr << "Ошибка: индекс вершины вне допустимого диапазона" << std::endl;
            return std::nullopt;
        }
        
        edges.push_back({from, to, distance, time, cost});
    }
    
    if (file.bad()) {
        std::cerr << "Ошибка чтения данных графа" << std::endl;
        return std::nullopt;
    }
    
    return edges;
}

void printGraph(const Graph& graph) {
    std::cout << "Граф содержит " << graph.getNumVertices() << " вершин\n\n";
    
    for (int i = 0; i < graph.getNumVertices(); ++i) {
        const auto& neighbors = graph.getNeighbors(i);
        if (!neighbors.empty()) {
            std::cout << "+-----------------------------------------+\n";
            std::cout << "| Вершина " << i << " соединена с:                  |\n";
            std::cout << "+----------+------------+--------+--------+\n";
            std::cout << "| Вершина  | Расстояние | Время  | Цена   |\n";
            std::cout << "+----------+------------+--------+--------+\n";
            
            for (const auto& edge : neighbors) {
                std::cout << "| " << std::setw(8) << edge.to << " | "
                          << std::setw(10) << edge.distance << " | "
                          << std::setw(6) << edge.time << " | "
                          << std::setw(6) << edge.cost << " |\n";
            }
            
            std::cout << "+----------+------------+--------+--------+\n\n";
        }
    }
}
