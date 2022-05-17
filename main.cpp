#include "Interface.h"
#include "Interactable.h"
#include "AC_Unit.h"


int main()
{
    Home * home = new Home;
    Interface Manager(home);
    Manager.header();
    Manager.console();
    return 0;
}
