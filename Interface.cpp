#include "Interface.h"


Interface::Interface(/*House * home) :home(home*/)
{
    /*nocbreak();
    echo();
    initscr();*/
}
Interface::~Interface()
{
    //endwin();
}


void Interface::header()
{
    cout << "Virtual Home Automation System" << endl;
    cout << "Enter commands below" << endl;
    cout << "Type \"help\" for command line help" << endl;
    //getch();
}

void Interface::console()
{
    vector<string> command;
    do
    {
        cout << ">>>";
        command = getCommand();

        //Interpret commands

        //If exit command leave this loop

    } while(runCommand(command));

    //getch();
};

vector<string> Interface::getCommand()
{
    string input;
    vector<string> command;


    getline(cin,input);
    istringstream ss(input);
    string del;

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

    if(command.at(0) == "add") {add(command); return 1;}
    if(command.at(0) == "remove") {}
    if(command.at(0) == "set") {}


    else {return 1;}
}

void Interface::helpScreen()
{
    cout << "Syntax Guide:" << endl;
    cout << "" << endl;
}

Room * Interface::findRoom(string roomName)
{
    //Checkes through the list of rooms
    for (size_t i = 0; i < home.rooms.size(); i++)
    {
        //the iterator is a pointer to the ith room in the list
        Room * iterator = &(home.rooms.at(i));
        //check what the name of this room is and if it is the wanted one
        //return a pointer to this room
        if (iterator->name = roomName) {return iterator;}
    }

    return NULL
}


Interactable * Interface findDevice(string deviceName, Room room) {}

int Interface::add(vector<string> command)
{
    if(command.size() < 3) {cout << "Insufficient Command Length" << endl; return 0;}
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

    //gets a pointer to the rooms we want to operate in
    Room * deviceRoom = findRoom(command.at(3));
    if(deviceRoom == NULL) {cout << "No rooms of name: " << command.at(3) << endl; return 0;}

    //Pass first of all a string dictating the type of object
    //Pass second the name of the device to create
    //This will be used to create a device of the required type in the correct room
    deviceRoom->addInteractable(command.at(1), command.at(2));
}

void Interface::remove(vector<string> command)
{

}

void Interface::set(vector<string> command)
{

}
