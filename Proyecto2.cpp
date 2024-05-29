#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "csv.h"

using json = nlohmann::json;

// Nodo del Árbol de Decisiones
struct Nodo {
    std::string pregunta;
    Nodo* izquierda;
    Nodo* derecha;
    std::vector<int> atracciones; // Solo en nodos hoja
};

// Estructura para la información de atracciones
struct Atraccion {
    int id;
    std::string nombre;
    int tiempoEspera;
};

// Grafo del Parque
class Grafo {
public:
    Grafo(const std::string& archivoCSV);
    int obtenerDistancia(int origen, int destino);

private:
    std::vector<std::vector<int>> matrizAdyacencia;
};

// Implementación del constructor del Grafo
Grafo::Grafo(const std::string& archivoCSV) {
    io::CSVReader<10> in(archivoCSV);
    int dist;
    while (in.read_row(dist)) {
        // Leer cada fila y construir la matriz de adyacencia
    }
}

int Grafo::obtenerDistancia(int origen, int destino) {
    return matrizAdyacencia[origen][destino];
}

// Función para leer el árbol de decisiones desde un archivo JSON
Nodo* leerArbolDecisiones(const std::string& archivoJSON) {
    std::ifstream archivo(archivoJSON);
    json j;
    archivo >> j;

    // Recursivamente construir el árbol desde el JSON
    return construirArbol(j);
}

Nodo* construirArbol(const json& j) {
    Nodo* nodo = new Nodo();
    nodo->pregunta = j["pregunta"];
    if (j.contains("izquierda")) {
        nodo->izquierda = construirArbol(j["izquierda"]);
    }
    if (j.contains("derecha")) {
        nodo->derecha = construirArbol(j["derecha"]);
    }
    if (j.contains("atracciones")) {
        nodo->atracciones = j["atracciones"].get<std::vector<int>>();
    }
    return nodo;
}

// Función para leer la información de atracciones desde un archivo CSV
std::vector<Atraccion> leerAtracciones(const std::string& archivoCSV) {
    std::vector<Atraccion> atracciones;
    io::CSVReader<3> in(archivoCSV);
    int id, tiempoEspera;
    std::string nombre;
    while (in.read_row(id, nombre, tiempoEspera)) {
        atracciones.push_back({id, nombre, tiempoEspera});
    }
    return atracciones;
}

// Algoritmo de Dijkstra para encontrar la ruta más corta
std::vector<int> dijkstra(const Grafo& grafo, int inicio, const std::vector<int>& atracciones) {
    // Implementación del algoritmo de Dijkstra
    std::vector<int> rutaOptima;
    return rutaOptima;
}

// Función principal del menú de la aplicación
void mostrarMenu() {
    std::cout << "Bienvenido al Planificador de Rutas en el Parque de Diversiones\n";
    std::cout << "1. Usar árbol de decisiones\n";
    std::cout << "2. Seleccionar atracciones manualmente\n";
    std::cout << "3. Editar tiempo de espera de atracciones\n";
    std::cout << "4. Salir\n";
}

int main() {
    Grafo grafo("grafo.csv");
    Nodo* arbolDecisiones = leerArbolDecisiones("decisiones.json");
    std::vector<Atraccion> atracciones = leerAtracciones("atracciones.csv");

    bool salir = false;
    while (!salir) {
        mostrarMenu();
        int opcion;
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                // Implementar uso del árbol de decisiones
                break;
            case 2:
                // Implementar selección manual de atracciones
                break;
            case 3:
                // Implementar edición de tiempo de espera
                break;
            case 4:
                salir = true;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    }

    return 0;
}