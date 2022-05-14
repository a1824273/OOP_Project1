#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <sstream>

#include "Interactable.h"
#include "AC_Unit.h"

using namespace std;

class Interface
{
  private:
      //House * home;
      /*string bannedNames =
      {
          "house",
          "room",
          "light",
          "door",
          "tv",
          "speaker",
          "ac"

      };*/

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

      void helpScreen();
      void set(vector<string> command);
      int add(vector<string> command);
      void remove(vector<string> command);

      Room * findRoom(string roomName);
      Interactable * findInteractable(string deviceName);
};

#endif
