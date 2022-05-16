
#ifndef HOME_H_
#define HOME_H_

#include <iostream>
#include <vector>
#include "Room.h"

class Home{

    protected:
        std::string home_name;
        int numRooms;
        std::vector<Room> *rooms; // = new std::vector<Room>;

    public:
        //Default Constructor
        Home();

        //Variable Constructor
        Home(std::string new_name);

        //add_room Function will add a room to the house
        void add_room(Room* roomtoAdd);

        //remove_room Function will remove a room from the house
        void remove_room(Room* roomtoRemove);

        //list_rooms Function will return the list of rooms in the house
        vector<Room> list_rooms();

        //Default Destructor
        ~Home();

};

#endif //HOME_H_