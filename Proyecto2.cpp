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

// Estructura para el Grafo
struct Grafo {
    std::vector<std::vector<int>> matrizAdyacencia;
};

// Funciones para construir y manipular el Grafo
void construirGrafo(Grafo& grafo, const std::string& archivoCSV);
int obtenerDistancia(const Grafo& grafo, int origen, int destino);

// Funciones para construir y manipular el Árbol de Decisiones
Nodo* leerArbolDecisiones(const std::string& archivoJSON);
Nodo* construirArbol(const json& j);

// Funciones para leer y editar la información de atracciones
std::vector<Atraccion> leerAtracciones(const std::string& archivoCSV);
void editarTiempoEspera(std::vector<Atraccion>& atracciones, int id, int nuevoTiempo);

// Algoritmo de Dijkstra para encontrar la ruta más corta
std::vector<int> dijkstra(const Grafo& grafo, int inicio, const std::vector<int>& atracciones);

// Función principal del menú de la aplicación
void mostrarMenu();

// Implementación de las funciones...

int main() {
    Grafo grafo;
    construirGrafo(grafo, "grafo.csv");
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
