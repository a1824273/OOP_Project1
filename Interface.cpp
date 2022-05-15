#include "Interface.h"



Interface::Interface(/*House * home) :home(home*/)
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
    //getch();
}

void Interface::console()
{
    vector<string> command;
    do
    {
        cout << "\u001b[0m";
        cout << ">>>";
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


    /****************
    vector<string>::iterator itr = command.begin();

    for (size_t i = 0; i < command.size(); i++) {
        printw(command[i].data());
        printw("\n");
    }
    ****************/

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
/*
    if(command.at(0) == "add")  {add(command); return 1;}
    if(command.at(0) == "remove") {}
    if(command.at(0) == "set") {}

*/
    else {cout << "command \"" << command.at(0) << "\" not recognised" << endl; return 1;}
}

void Interface::helpScreen()
{
    cout << "\u001b[33;1m" << endl;
    cout << "*************************************************************************************************************" << endl;
    cout << "Syntax Guide:" << endl;
    cout << endl;
    cout << "Here is where the syntax guide as well as examples for the user to follow will be printed" << endl;
    cout << "e.g. >>>add Light Lamp Bedroom" << endl;
    cout << "This adds a light called Lamp in the room \"Bedroom\"" << endl;
    cout << "set [device name] [room name] [member] [state]" << endl;
    cout << "*************************************************************************************************************" << endl;
    cout << endl;
}

Room * Interface::findRoom(string roomName)
{
    //Checks through the list of rooms
    for (size_t i = 0; i < home.rooms.size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Room * iterator = &(home.rooms.at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->room_name == roomName) {return iterator;}
    }

    return NULL;
}

Interactable * Interface::findInteractable(string deviceName, Room * roomToLookIn)
{
    for (size_t i = 0; i < home.roomToLookIn->list.size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Interactable * iterator = &(home.roomToLookIn->list->at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->get_name() == deviceName) {return iterator;}
    }

    return NULL;
}


int Interface::add(vector<string> command)
{
    if(command.size() < 3) {cout << "Insufficient Command Length" << endl; return 0;}

    //Add Room
    if(command.at(1) == "room")
    {
        //create a room in the house object with a name input from the command
        //command.at(2) is a string and a room will be created with that name
        home.addRoom(command.at(2));
        return 0;
        //exit this function as the command has been completed
    }

    //now need to change the command check length as all other commands are bigger
    if(command.size() < 3) {cout << "Insufficient Command Length" << endl; return 0;}

    //Add Device
    //gets a pointer to the rooms we want to operate in
    Room * deviceRoom = findRoom(command.at(3));
    if(deviceRoom == NULL) {cout << "No rooms of name: " << command.at(3) << endl; return 0;}

    //Pass first of all a string dictating the type of object
    //Pass second the name of the device to create
    //This will be used to create a device of the required type in the correct room
    deviceRoom->add_interactable(command.at(1), command.at(2));
}

void Interface::remove(vector<string> command)
{

}

void Interface::set(vector<string> command)
{
    /*
    Command structure
    0: set
    1: interactable name
    2: member to alters
    3: status to set it to
    */

    const string interactable_name = command.at(0);
    const string interactable_room = command.at(1);
    const string member = command.at(2);
    const string status = command.at(3);



    //find the room,s to work in
    Room * deviceRoom = findRoom(interactable_room);
    //find the interactable to work on
    Interactable * interactable_to_change = findInteractable(interactable_name, deviceRoom);


    //handles universal on/off functions
    if(member == "onoff") {interactable_to_change->set_state(stoi(status));}
    if(member == "name") {interactable_to_change->set_name(status);}

    //Lights
    if(typeid(*interactable_to_change).name() == "Lights")
    {
        Lights* actor = dynamic_cast<Lights*>(interactable_to_change);
        if(member == "colour") {actor->set_colour(status);}
    }


    /*
    if(typeid(*interactable_to_change).name() == "Door")
    {
        Door * actor = dynamic_cast<Door*>(interactable_to_change);
        if(member == "lock") {actor->set_lock(status);}
        if(member == "open") {actor->set_state(status)}
    }*/

    //AC changes
    if(typeid(*interactable_to_change).name() == "AC_Unit")
    {
        AC_Unit * actor = dynamic_cast<AC_Unit*>(interactable_to_change);
        if(member == "temp") {actor->set_AC_temp(any_cast<float>(status));}
        if(member == "speed") {actor->set_AC_speed(any_cast<int>(status));}
    }

    if(typeid(*interactable_to_change).name() == "Smart_Speaker")
    {
        Smart_Speaker * actor = dynamic_cast<Smart_Speaker*>(interactable_to_change);
        if(member == "volume") {actor->set_media_volume(any_cast<int>(status));}
        if(member == "channel") {actor->set_current_channel(status);}
    }

    if(typeid(*interactable_to_change).name() == "Smart_Television")
    {
        Smart_Television * actor = dynamic_cast<Smart_Television*>(interactable_to_change);
        if(member == "volume") {actor->set_media_volume(any_cast<int>(status));}
        if(member == "channel") {actor->set_current_channel(status);}
        if(member == "brightness") {actor->set_brightness_level(any_cast<int>(status));}
    }
}
