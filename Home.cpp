
#include <iostream>
#include <vector>
#include "Room.h"
#include "Home.h"


Home::Home(){
    home_name = "N/A";
    numRooms = 0;
    rooms = new std::vector<Room>;
    rooms.clear();
};

Home::Home(std::string new_name){
    home_name = new_name;
    numRooms = 0;
    rooms = new std::vector<Room>;
    rooms.clear();

};

void Home::add_room(Room* roomtoAdd){
    rooms->push_back(roomtoAdd);
};

void Home::remove_room(Room* roomtoRemove){
    
    int position;
    for (int i = 0; i < rooms->size(); i++){
        if (rooms[i] == roomtoRemove){
            position = i;
        }
    };

    rooms->erase(position);

};

std::vector<Room> Home::list_rooms(){
    return rooms;
}

Home::~Home(){
    delete [] rooms;
}




