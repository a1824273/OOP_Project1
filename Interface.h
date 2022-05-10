#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <sstream>

using namespace std;

class Interface
{
  private:
      //House * home;

  public:
      //COnstructor takes in a pointer to the home with whcih we will operate on
      Interface(/*House * home*/);
      ~Interface();
      //Clears the screen and produces the header for the screen
      void header();

      //Initiates the console loop
      void console();

      vector<string> getCommand();

      bool runCommand(vector<string> command);
};

#endif
