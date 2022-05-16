
#include <iostream>
#include <vector>
#include "Room.h"
#include "Home.h"


Home::Home(){
    home_name = "N/A";
    numRooms = 0;
    rooms = new std::vector<Room*>;
    rooms->clear();
};

Home::Home(std::string new_name){
    home_name = new_name;
    numRooms = 0;
    rooms = new std::vector<Room*>;
    rooms->clear();

};

void Home::add_room(Room* roomtoAdd){
    rooms->push_back(roomtoAdd);
    std::cout << "Room has been successfully added to Home." << std::endl;

};

void Home::remove_room(Room* roomtoRemove){

    int position;
    for (int i = 0; i < rooms->size(); i++){
        if (rooms->at(i) == roomtoRemove){
            position = i;
        }
    };

    rooms->erase(rooms->begin()+position);
    std::cout << "Room has been successfully removed from Home." << std::endl;

};

void Home::list_rooms(){
    
    for (int i = 0; i < rooms->size(); i++){
        std::cout << &rooms[i] << std::endl;
    };
    
    std::cout << std::endl;
    std::cout << "All rooms have been successfully printed." << std::endl;

};

Home::~Home(){
    delete [] rooms;
    std::cout << "Home has been destroyed." << std::endl;

}
