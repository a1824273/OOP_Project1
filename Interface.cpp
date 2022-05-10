#include "Interface.h"


Interface::Interface(/*House * home) :home(home*/)
{
    /*nocbreak();
    echo();
    initscr();*/
}
Interface::~Interface()
{
    endwin();
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
    if(command.at(0) == "exit") {return 0;}
    else {return 1;}
}
