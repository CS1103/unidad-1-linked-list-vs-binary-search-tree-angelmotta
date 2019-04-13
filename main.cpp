#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include "LinkedList.h"
//#include "BinarySearchTree.h"
#include "Location.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    //BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    std::ifstream file("../"+LOCATION_FILE);
    std::string line;
    if(!file) {
        std::cout << "Cannot open Locations.csv file.\n";
        return 1;
    }

    int i=0;
    int _position_id;
    std::string _state_code;
    std::string _county;
    double _latitude;
    double _longitude;
    std::string _line;
    std::string _construction;
    while(std::getline(file, line)){    // recorre linea por linea
        std::istringstream iss(line);
        std::string word;
        if (line.find("PositionId") != std::string::npos) {     // Skip the first line of the file
            //std::cout << "found!" << '\n';
            continue;
        }
        while(std::getline(iss,word,',')){      // extraer todos los fields de una fila
            if(i == 0){
                _position_id = stoi(word);
            }
            if(i == 1){
                _state_code = word;
            }
            if(i == 2){
                _county = word;
            }
            if(i == 3){
                _latitude = stod(word);
            }
            if(i == 4){
                _longitude = stod(word);
            }
            if(i == 5){
                _line = word;
            }
            if(i == 6){
                _construction = word;
            }
            i++;
        }
        i = 0;
        std::cout << "Line: " << _position_id << " " << _state_code << " " << _county << " " << _latitude << " " << _longitude << " " << _line << " " << _construction << std::endl;
        Location temp_data = Location(_position_id, _state_code, _county, _latitude, _longitude, _line, _construction);
        ll.add_tail(temp_data);
    }
    // Fin Grabar datos del archivo Locations.csv en ll


    // Grabar Datos del archivo "Locations.csv" en bst

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch

    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (const auto& id: vsearch) {

        // Buscar en ll

        // Buscar en bsd
    }


    return 0;
}