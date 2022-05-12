
#ifndef ROOM_H_
#define ROOM_H_
#include "Interactable.h"

#include <iostream>
#include <vector>

class Room {

    private:
        std::string room_name;      //Name of the Room 
        Interactable* devices;      //Devices inside of the room
        int num_devices;            //Total number of interactables currently inside the room;
        int capacity;               //Total number of interactables that can occupy one room
        std::vector<Interactable> *list = new std::vector<Interactable>;

    public:
    //Default Constructor
        Room();
    //Variable Constructor that takes name and total number of interactables that can occupy the room;
        Room(std::string name, int capacity);

    //add_interactable will create an interactable with given type and name, and then add it to the current room.
        Interactable* add_interactable(std::string interactable_type, std::string interactable_name);

    //Default Destructor
        ~Room();


};


#endif //ROOM_H_