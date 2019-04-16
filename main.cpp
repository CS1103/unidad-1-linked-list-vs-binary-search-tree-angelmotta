#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "Location.h"
#include <chrono>

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    load_locations(&ll, LOCATION_FILE);

    // Grabar Datos del archivo "Locations.csv" en bst
    //Node_bt* root = insert(bst.get_root(),Location Data);
    //bst.insert(root, Location data );

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    load_vsearch(vsearch, SEARCH_FILE);

    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso

    // Busqueda en ll
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    for (const auto& id: vsearch) {
        // Buscar en ll
        ll.search(id);
        // Buscar en bsd
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    double time_avg = static_cast<double>(int_ms)/100;
    std::cout << "Tiempo promedio de busqueda en Lista Enlazada(ms): " << time_avg << std::endl; // Tiempo promedio por cada busqueda

    return 0;
}