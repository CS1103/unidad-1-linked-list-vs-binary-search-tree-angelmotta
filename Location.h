//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>

class Location {
    int position_id;
    std::string state_code;
    std::string county;
    double latitude;
    double longitude;
    std::string line;
    std::string construction;
public:
    Location(
            int position_id,
            std::string state_code,
            std::string county,
            double latitude,
            double longitude,
            std::string line,
            std::string construction);

    int getPosition_id() const;

    void setPosition_id(int position_id);

    // Declare los metodos que crea necesario
    // Metodo Cargar datos

    // Cree que sea necesario agregar destructor, justifique
};


#endif //LINKEDLISTVSBINARYTREE_LOCATION_H
