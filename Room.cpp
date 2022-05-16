
#include <iostream>
#include <vector>
#include "Room.h"
#include "Lights.h"
#include "Smart_Speaker.h"
#include "Smart_Television.h"
#include "Media_Device.h"
#include "AC_Unit.h"
#include "Door.h"

//Default Constructor
Room::Room(){

    room_name = "N/A";                                  //setting Room Name to N/A
    capacity = 0;                                       //setting Capacity to 0
    interactables = new std::vector<Interactable*>;     //Initialising the List Vector
    interactables->clear();                             //Clearing the List Vector

};

//Variable Constructor
Room::Room(std::string name, int max_capacity){

    room_name = name;
    capacity = max_capacity;
    interactables = new std::vector<Interactable*>;
    interactables->clear();

};

//get_name function will return room name
std::string Room::get_name(){
    return room_name;
};

//set_name function will set room name
void Room::set_name(std::string name){
    room_name = name;

};

//add_interactable function
void Room::add_interactable(std::string interactable_type, std::string interactable_name){

    //Creating Light Object and adding it to the list of interactables
    if(interactable_type == "Lights" || interactable_type == "Light" ){
        Lights *CreatedLight = new Lights;
        CreatedLight->set_name(interactable_name);
        interactables->push_back(CreatedLight);
    }

    //Creating Smart Television Object and adding it to the list of interactables
    if(interactable_type == "Smart Television" || interactable_type == "SmartTelevision" || interactable_type == "Smart_Television"){
        Smart_Television *CreatedSmart_Television = new Smart_Television;
        CreatedSmart_Television->set_name(interactable_name);
        interactables->push_back(CreatedSmart_Television);
    }

    //Creating Smart_Speaker Object and adding it to the list of interactables
    if(interactable_type == "Smart Speaker" || interactable_type == "SmartSpeaker" || interactable_type == "Smart_Speaker"){
        Smart_Speaker *CreatedSmart_Speaker = new Smart_Speaker;
        CreatedSmart_Speaker->set_name(interactable_name);
        interactables->push_back(CreatedSmart_Speaker);
    }

    //Creating Smart_Speaker Object and adding it to the list of interactables
    if(interactable_type == "AC Unit" || interactable_type == "ACUnit" || interactable_type == "AC"){
        AC_Unit *CreatedAC = new AC_Unit;
        CreatedAC->set_name(interactable_name);
        interactables->push_back(CreatedAC);
    }

    //Creating Smart_Speaker Object and adding it to the list of interactables
    if(interactable_type == "Door" || interactable_type == "door"){
        Door *CreatedDoor = new Door;
        CreatedDoor->set_name(interactable_name);
        interactables->push_back(CreatedDoor);
    }

};

//Default Destructor
Room::~Room(){
    delete [] interactables;
}
