
#include <iostream>
#include <vector>
#include "Interactable.h"

//Default Constructor 
Interactable::Interactable(){
    interactable_name = "N/A";
    state = 0;

};

//Variable Constructor
Interactable::Interactable(std::string new_name, bool new_state){
    interactable_name = new_name;
    state = new_state;

};

void Interactable::set_name(std::string new_name){
    interactable_name = new_name;

};

std::string Interactable::get_name(){
    return interactable_name;

};

void Interactable::set_state(bool new_state){
    state = new_state;

};

bool Interactable::get_state(){
    return state;

};
