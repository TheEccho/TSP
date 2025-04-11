#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <optional>

// Структура для хранения данных о ребре графа
struct Edge {
    int from;           // Начальная вершина
    int to;             // Конечная вершина
    double distance;    // Расстояние между вершинами
    double time;        // Время перемещения
    double cost;        // Стоимость доставки
};

// Функция для чтения данных из файла
std::optional<std::vector<Edge>> readGraphFromFile(const std::string& filename);
