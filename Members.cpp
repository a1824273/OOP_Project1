

#include <iostream>
#include "Members.h"


//Default Constructor 
Members::Members(){
    name = "N/A";
    access_level = false;
};

Members::Members(std::string member_name, bool access_lvl){
    name = member_name;
    access_level = access_lvl;
    std::cout << "Member successfully created." << std::endl;
};

//set_access_level will set the access level of the member class 
void Members::set_access_level(bool state){
    access_level = state;
};

//get_access_level will return the current access level
bool Members::get_access_level(){
    return access_level;
};

void Members::set_name(std::string setname){
    name = setname;
};

std::string Members::get_name(){
    return name;
};

Members::~Members(){
    
};