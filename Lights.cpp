#include <iostream>
#include <string.h>
#include "Lights.h"
#include "Interactable.h"

Lights::Lights(){
    //creating a default light object with a light name, light colour and status of the light
    thee_light_colour = "white";
    light_on_state = true;
    std::cout << "The lights colour is: " << thee_light_colour << "." << std::endl;
    if (light_on_state == true){
        std::cout << "The light is on." << std::endl;
    }
    else{
        std::cout << "The light is off." << std::endl;
    }
}

Lights::Lights(std::string light_colour, bool state_of_light){
    //making a light variable will the light name, light colour and on off state
    thee_light_colour = light_colour;
    light_on_state = state_of_light;
    std::cout << "The lights colour is: " << thee_light_colour << "." << std::endl;
    if (light_on_state == true){
        std::cout << "The light is on." << std::endl;
    }
    else{
        std::cout << "The light is off." << std::endl;
    }
}

void Lights::set_state(bool light_state){
    //change the state of the light (i.e. on or off)
    light_on_state = light_state;

}
bool Lights::get_state(){
    //return the state of the light
    if (light_on_state == true){
        std::cout << "The light is on" << std::endl;
    }
    else{
        std::cout << "The light is off" << std::endl;
    }
    return light_on_state;
}
void Lights::set_colour(std::string colour){
    //change the colour of the light
    thee_light_colour = colour;
}
std::string Lights::get_colour(){
    //get the colour of the light
    return thee_light_colour;
}
Lights::~Lights(){
    //destructor
}