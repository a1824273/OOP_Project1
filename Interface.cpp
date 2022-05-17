#include "Interface.h"



Interface::Interface(Home * home) :home(home)
{
    /*nocbreak();
    echo();
    initscr();*/
    //cout << "\033[%dm %3d\033[m" << endl;
    cout << "\033[2J \033[H";

    //cout << "\u001b[47;1m" << endl;

}
Interface::~Interface()
{
    //endwin();
}


void Interface::header()
{
    cout << "\u001b[32;1m";
    cout << R"(___   _ . ____    _  _ _ ____ ___ _  _ ____ _       ____ _  _ ____ ____ ___    _  _ ____ _  _ ____    ____ _   _ ____ ___ ____ _  _ )" << endl;
    cout << R"(|  \  | ' [__     |  | | |__/  |  |  | |__| |       [__  |\/| |__| |__/  |     |__| |  | |\/| |___    [__   \_/  [__   |  |___ |\/| )" << endl;
    cout << R"(|__/ _|   ___]     \/  | |  \  |  |__| |  | |___    ___] |  | |  | |  \  |     |  | |__| |  | |___    ___]   |   ___]  |  |___ |  | )" << endl;
    cout << "Enter commands below" << endl;
    cout << "Type \"help\" for command line help" << endl;
    cout << "Type \"exit\" to exit application" << endl;
    //getch();
}

void Interface::console()
{
    vector<string> command;
    do
    {
        cout << "\u001b[0m";
        cout << ">>> ";
        command = getCommand();

        //Interpret commands

        //If exit command leave this loop

    } while(runCommand(command));

    //getch();
};

vector<string> Interface::getCommand()
{
    //The actual commadn line that is input,
    string input;
    //a vector of strings, where each word is an individual element
    vector<string> command;

    //Gets line entire line from cin and stores it in input
    getline(cin,input);
    //some magic
    istringstream ss(input);

    //the string that will store the individual pieces and push them into the vector
    string del;

    //reads each word of the input in and spilts it at the delimiter ' '
    while(getline(ss, del, ' '))
    {
      command.push_back(del);
    }


    //returns the vector of strings
    return command;
};

bool Interface::runCommand(vector<string> command)
{
    //setup the maximum and minimun size for maxCommandSize
    const int minCommandSize = 0;
    const int maxCommandSize = 5;

    //Check that the command is not empty, if it is, just reset the console
    if(command.size() == minCommandSize) {return 1;}


    if(command.at(0) == "help") {helpScreen(); return 1;}
    if(command.at(0) == "exit") {return 0;}

    if(command.at(0) == "add")  {add(command); return 1;}
    if(command.at(0) == "remove") {}
    if(command.at(0) == "set") {set(command); return 1;}
    if(command.at(0) == "list") {list(command); return 1;}

    else {cout << "command \"" << command.at(0) << "\" not recognised" << endl; return 1;}
    cout << endl;
}

void Interface::helpScreen()
{
    cout << "\u001b[33;1m" << endl;
    cout << "*************************************************************************************************************" << endl;

    ifstream f("Syntax_Guide.txt");
    if (f.is_open())
        std::cout << f.rdbuf();

    cout << "*************************************************************************************************************" << endl;
    cout << endl;
}

Room * Interface::findRoom(string roomName)
{
    //Checks through the list of rooms
    for (size_t i = 0; i < home->rooms->size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Room * iterator = (home->rooms->at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->room_name == roomName) {return iterator;}
    }

    return nullptr;
}

Interactable * Interface::findInteractable(string deviceName, Room * roomToLookIn)
{
    for (size_t i = 0; i < roomToLookIn->interactables->size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Interactable * iterator = (roomToLookIn->interactables->at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->get_name() == deviceName) {return iterator;}
    }

    return nullptr;
}


int Interface::add(vector<string> command)
{
    if(command.size() < 3) {cout << "Insufficient Command Length" << endl; return 0;}

    //Add Room
    if(command.at(1) == "Room")
    {
        //create a room in the house object with a name input from the command
        //command.at(2) is a string and a room will be created with that name
        home->add_room(command.at(2));
        return 1;
        //exit this function as the command has been completed
    }

    //now need to change the command check length as all other commands are bigger
    if(command.size() < 4) {cout << "Insufficient Command Length to add Interactable device of type: " << command.at(1) << endl; return 0;}

    //Add Device
    //gets a pointer to the rooms we want to operate in
    Room * deviceRoom = findRoom(command.at(3));
    if(deviceRoom == nullptr) {cout << "No rooms of name: " << command.at(3) << endl; return 0;}

    //Pass first of all a string dictating the type of object
    //Pass second the name of the device to create
    //This will be used to create a device of the required type in the correct room
    deviceRoom->add_interactable(command.at(1), command.at(2));
    return 1;
}

void Interface::remove(vector<string> command)
{

}



int Interface::list(vector<string> command)
{
    //const string object_to_list = command.at(1);

    //Lists the rooms in the house
    if(command.at(1) == "Rooms")
    {
        home->list_rooms();
    }

    //Lists the devices i the specified room
    else if(findRoom(command.at(1)) != nullptr)
    {
        Room * room_to_list = findRoom(command.at(1));
        room_to_list->list_interactables();
    }

    else if(command.size() == 3)
    {
        Interactable * device_to_print = findInteractable(command.at(1), findRoom(command.at(2)));
        if(device_to_print == NULL) {cout << "No device called " << command.at(1) << " in " << command.at(2) << endl; return 0;}
        device_to_print->print();
    }

    else
    {
        cout << "Unable to list object " << command.at(1) << endl;
        cout << "Check to see if this room really exists (>>list Rooms)" << endl;
    }

    return 0;
}




int Interface::set(vector<string> command)
{
    /*
    Command structure
    0: set
    1: interactable name
    2: room it is in
    3: member to alters
    4: status to set it to
    */

    if(command.size() != 5)
    {
        cout << "Incorrect command length" << endl;
        return 0;
    }

    const string interactable_name = command.at(1);
    const string interactable_room = command.at(2);
    const string member = command.at(3);
    const string status = command.at(4);



    //find the room,s to work in
    Room * deviceRoom = findRoom(interactable_room);
    if(deviceRoom == nullptr) {cout << "No Room exists of name: \"" << interactable_room << "\"" << endl; return 0;}
    //find the interactable to work on
    Interactable * interactable_to_change = findInteractable(interactable_name, deviceRoom);
    if(interactable_to_change == nullptr) {cout << "No Interactable exists of name: \"" << interactable_name << "\" " << "in \"" << interactable_room << "\"" << endl; return 0;}


    //handles universal on/off functions
    if(member == "onoff")
    {
        if(status == "on") {interactable_to_change->set_state(1); return 1;}
        else if (status == "off") {interactable_to_change->set_state(0); return 1;}
        else {cout << "Invalid on/off parameter" << endl;}
    }

    if(member == "name") {interactable_to_change->set_name(status); return 1;}


    //Lights
    if(interactable_to_change->type == "Lights")
    {
        cout << "Altering the Light" << endl;
        Lights* actor = dynamic_cast<Lights*>(interactable_to_change);
        if(member == "colour") {actor->set_colour(status); return 1;}

    }



    if(interactable_to_change->type == "Door")
    {
        Door * actor = dynamic_cast<Door*>(interactable_to_change);
        if(member == "lock")
        {
            if(status == "unlock")  {actor->set_state(0); return 1;}
            if(status == "lock")    {actor->set_state(1); return 1;}
        }
        //if(member == "open") {actor->set_state(status)}
    }

    //AC changes
    if(interactable_to_change->type == "AC_Unit")
    {
        AC_Unit * actor = dynamic_cast<AC_Unit*>(interactable_to_change);
        if(member == "temp") {actor->set_AC_temp(stof(status)); return 1;}
        if(member == "speed") {actor->set_AC_speed(stoi(status)); return 1;}
    }

    if(interactable_to_change->type == "Smart_Speaker")
    {
        Smart_Speaker * actor = dynamic_cast<Smart_Speaker*>(interactable_to_change);
        if(member == "volume") {actor->set_media_volume(stoi(status)); return 1;}
        if(member == "channel") {actor->set_current_channel(status); return 1;}
    }

    if(interactable_to_change->type == "Smart_Television")
    {
        Smart_Television * actor = dynamic_cast<Smart_Television*>(interactable_to_change);
        if(member == "volume") {actor->set_media_volume(stoi(status)); return 1;}
        if(member == "channel") {actor->set_current_channel(status); return 1;}
        if(member == "brightness") {actor->set_brightness_level(stoi(status)); return 1;}
    }

    cout << "Interactable Property " << member << " does not exist" << endl;

    return 0;
}
