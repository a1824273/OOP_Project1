#include <iostream>
#include <string.h>
#include "Lights.h"
#include "Interactable.h"

Lights::Lights(){
    type = "Lights";
    //creating a default light object with a light name, light colour and status of the light
    the_light_colour = "white";     //the colour of the light
    light_on_state = true;          //shows whether or not the light is on (on is true)
    std::cout << "The lights colour is: " << the_light_colour << "." << std::endl;
    if (light_on_state == true){
        std::cout << "The light is on." << std::endl;
    }
    else{
        std::cout << "The light is off." << std::endl;
    }
}

Lights::Lights(std::string light_colour, bool state_of_light){
    type = "Lights";
    //making a light variable will the light name, light colour and on off state
    the_light_colour = light_colour;
    light_on_state = state_of_light;
    std::cout << "The lights colour is: " << the_light_colour << "." << std::endl;
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
    the_light_colour = colour;
}

std::string Lights::get_colour(){
    //get the colour of the light
    return the_light_colour;
}

void Lights::print(){
    //printing all current infomation of the light
    std::cout << "The lights colour is: " << the_light_colour << "." << std::endl;
    if (light_on_state == true){
        std::cout << "The light is on." << std::endl;
    }
    else{
        std::cout << "The light is off." << std::endl;
    }
}

Lights::~Lights(){
    //destructor
}
