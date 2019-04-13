//
// Created by ruben on 4/5/19.
//

#include "Location.h"

// Defina los metodos que crea necesario

Location::Location(int _position_id,std::string _state_code,std::string _county,double _latitude,double _longitude,std::string _line,std::string _construction){
    position_id = _position_id;
    state_code = _state_code;
    county = _county;
    latitude = _latitude;
    longitude = _longitude;
    line = _line;
    construction = _construction;
}

int Location::getPosition_id() const {
    return position_id;
}

void Location::setPosition_id(int position_id) {
    Location::position_id = position_id;
}
