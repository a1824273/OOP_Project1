#include <iostream>
#include <string>
#include "Door.h"

Door::Door(){
    //default parameter
    locked = false;
    if (locked == false){
        std::cout << "The door is unlocked!" << std::endl;
    }
    else{
        std::cout << "The door is locked!" << std::endl;
    }
}

Door::Door(bool door_status){
    //Door constructor with user input
    locked = door_status;
    if (locked == false){
        std::cout << "The door is unlocked!" << std::endl;
    }
    else{
        std::cout << "The door is locked!" << std::endl;
    }
}

void Door::set_state(bool door_status){
    //setting the door status
    locked = door_status;
    if (locked == false){
        std::cout << "The door is unlocked!" << std::endl;
    }
    else{
        std::cout << "The door is locked!" << std::endl;
    }
}

bool Door::get_door_state(){
    //get door status
    return locked;
}

Door::~Door(){
}