cmake_minimum_required(VERSION 3.10)

# Название проекта
project(GraphProject)

# Установка стандарта C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к исходникам
include_directories(include)
   
# Список исходных файлов
set(SOURCES 
    src/graph.cpp
    src/main.cpp
)
   
# Список заголовочных файлов
set(HEADERS
    include/common.hpp
    include/graph.hpp
)

# Создание исполняемого файла
add_executable(graph_app ${SOURCES} ${HEADERS})

# Установка выходного каталога для исполняемого файла
set_target_properties(graph_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
