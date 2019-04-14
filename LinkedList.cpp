#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

UTEC::LinkedList::~LinkedList() {

}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}


void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::load_locations(UTEC::LinkedList* linked_list, std::string file_name) {
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
        linked_list->add_tail(temp_data);   //linked_list es puntero a objeto usamos -> para acceder a su metodo
    }
    // Fin Grabar datos del archivo Locations.csv en ll
}

void UTEC::load_vsearch(std::vector<int> &vsearch, std::string search_file){
    std::ifstream file("../"+search_file);
    std::string line;
    assert(file);   // Detiene la ejecución si no puede leer el archivo
    while(std::getline(file, line)){
        vsearch.push_back(stoi(line));
    }

}

UTEC::Node *UTEC::LinkedList::search(int position_id) {
    Node* actual = head;
    int found = 0;
    while(actual != nullptr){
        Location data_tmp = actual->data;
        if(data_tmp.getPosition_id() == position_id){
            found = 1;
            break;
        }
        actual = actual->next;
    }
    return actual;
    /*if(found == 1){
        std::cout << "Elemento encontrado" << std::endl;
    }
    else{
        std::cout << "Elemento no encontrado" << std::endl;
    }*/
}