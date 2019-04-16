#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


UTEC::BinarySearchTree::~BinarySearchTree(){

}

bool UTEC::BinarySearchTree::is_empty() {
    return root == nullptr;
}

UTEC::Node_bt *UTEC::BinarySearchTree::get_root() {
    return root;
}

UTEC::Node_bt *UTEC::BinarySearchTree::insert(Node_bt* node_tmp, const Location& data){   //Inicialmente recibe como argumento la raiz del arbol
    if(node_tmp == nullptr){
        return new Node_bt(data);
    }
    else{
        Node_bt* node_new = new Node_bt(data);
        if(node_tmp->data.getPosition_id() > node_new->data.getPosition_id()){
            node_tmp->right = insert(node_tmp->right, data);
        }
        else if(node_tmp->data.getPosition_id() < node_new->data.getPosition_id()){
            node_tmp->left = insert(node_tmp->left, data);
        }
    }
    return node_tmp;
}

void UTEC::load_locations_bts(UTEC::BinarySearchTree* binary_tree, std::string file_name) {
    //
    std::ifstream file("../"+file_name);
    std::string line;
    assert(file);
    int i=0;
    int _position_id=0;
    std::string _state_code;
    std::string _county;
    double _latitude=0.0;
    double _longitude=0.0;
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
            i++;    //Siguiente campo de la linea n
        }
        i = 0;
        //std::cout << "Line: " << _position_id << " " << _state_code << " " << _county << " " << _latitude << " " << _longitude << " " << _line << " " << _construction << std::endl;
        Location temp_data = Location(_position_id, _state_code, _county, _latitude, _longitude, _line, _construction);
        //linked_list->add_tail(temp_data);   //linked_list es puntero a objeto usamos -> para acceder a su metodo
        binary_tree->insert(binary_tree->get_root(), temp_data );
    }
    // Fin Grabar datos del archivo Locations.csv en ll
}