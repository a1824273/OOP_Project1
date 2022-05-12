
#include <iostream>
#include <vector>
#include "Room.h"

//Default Constructor
Room::Room(){
    room_name = "N/A";
    capacity = 0;
};

//Variable Constructor
Room::Room(std::string name, int max_capacity){
    room_name = name;
    capacity = max_capacity;
};

//add_interactable function
Interactable* Room::add_interactable(std::string interactable_type, std::string interactable_name){
    
    if(interactable_type == "Lights" || interactable_type == "Light" ){
        Light *CreatedLight = new Light(interactable_name); //PARAMETERS TO BE ADDED)
        
    }
            //std::vector<Interactable> *list = new std::vector<Interactable>;


    list->push_back(CreatedLight);
};


Room::~Room(){
    delete [] list;
}

