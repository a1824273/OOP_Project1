#ifndef DOOR_H
#define DOOR_H

#include <iostream>
#include <string>
#include "Interactable.h"

class Door: public Interactable{
private:
    std::string the_door_name;
    bool locked;
public:
    //default parameter
    Door();

    //Door constructor with user input
    Door(std::string door_name, bool door_status);

    //setting the door name
    void set_door_name(std::string door_name);

    //getting the door name
    std::string get_door_name();

    //setting the door status
    void set_state(bool door_status);

    //get door status
    bool get_door_state();

    ~Door();
};

#endif