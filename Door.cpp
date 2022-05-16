#include <iostream>
#include <string>
#include "Door.h"

Door::Door(){
    //default parameter
    the_door_name = "Door 1";
    locked = false;
}

Door::Door(std::string door_name, bool door_status){
    //Door constructor with user input
    the_door_name = door_name;
    locked = door_status;
}

void Door::set_door_name(std::string door_name){
    //setting the door name
    the_door_name = door_name;
}

std::string Door::get_door_name(){
    //getting the door name
    return the_door_name;
}

void Door::set_state(bool door_status){
    //setting the door status
    locked = door_status;
}

bool Door::get_door_state(){
    //get door status
    if (locked == true){
        std::cout << "The door is locked" << std::endl;
    }
    else{
        std::cout << "The door is unlocked" << std::endl;
    }
    return locked;
}

Door::~Door(){
}