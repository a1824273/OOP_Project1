
#ifndef HOME_H_
#define HOME_H_

#include <iostream>
#include <vector>
#include "Room.h"

class Home{

    protected:
        std::string home_name;
        int numRooms;
        std::vector<Room> *list; // = new std::vector<Room>;

    public:
        //Default Constructor
        Home::Home();

        //Variable Constructor
        Home::Home(std::string home_name);

        //add_room Function will add a room to the house
        void Home::add_room(Room* roomtoAdd);

        //remove_room Function will remove a room from the house
        void Home::remove_room(Room* roomtoRemove);

        //list_rooms Function will return the list of rooms in the house
        vector<Room> Home::list_rooms();

};

#endif //HOME_H_