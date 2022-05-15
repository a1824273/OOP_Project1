
#include <iostream>
#include <vector>
#include "Room.h"
#include "Lights.h"
#include "Smart_Speaker.h"
#include "Smart_Television.h"
#include "Media_Device.h"

//Default Constructor
Room::Room(){

    room_name = "N/A";                      //setting Room Name to N/A
    capacity = 0;                           //setting Capacity to 0
    interactables = new std::vector<Interactable>;   //Initialising the List Vector
    interactables->clear();                          //Clearing the List Vector

};

//Variable Constructor
Room::Room(std::string name, int max_capacity){

    room_name = name;
    capacity = max_capacity;
    interactables = new std::vector<Interactable>;
    interactables->clear();
    
};

//add_interactable function
void Room::add_interactable(std::string interactable_type, std::string interactable_name){

    //Creating Light Object and adding it to the list of interactables
    if(interactable_type == "Lights" || interactable_type == "Light" ){
        Lights *CreatedLight = new Lights();
        CreatedLight->set_light_name(interactable_name);
        interactables->push_back(CreatedLight);
    }
     
    //Creating Smart Television Object and adding it to the list of interactables
    if(interactable_type == "Smart Television" || interactable_type == "SmartTelevision" || interactable_type == "Smart_Television"){
        Smart_Television *CreatedSmart_Television = new Smart_Television();
        CreatedSmart_Television->set_media_name(interactable_name);
        interactables->push_back(CreatedSmart_Television);
    }

    //Creating Smart_Speaker Object and adding it to the list of interactables
    if(interactable_type == "Smart Speaker" || interactable_type == "SmartSpeaker" || interactable_type == "Smart_Speaker"){
        Smart_Speaker *CreatedSmart_Speaker = new Smart_Speaker();
        CreatedSmart_Speaker->set_media_name(interactable_name);
        interactables->push_back(CreatedSmart_Speaker);
    }



};


Room::~Room(){
    delete [] list;
}

