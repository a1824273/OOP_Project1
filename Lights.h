#ifndef LIGHTS_H
#define LIGHTS_H

#include <iostream>
#include <string>

class Lights{
private:
    std::string thee_light_name;
    std::string thee_light_colour;
    bool light_on_state;
public:
    //creating a default light object with a light name, light colour and status of the light
    Lights();

    //making a light variable will the light name, light colour and on off state
    Lights(std::string light_name, std::string light_colour, bool state_of_light);

    //changing the light name
    void set_light_name(std::string light_name);

    //getting the light name
    std::string get_light_name();

    //change the state of the light (i.e. on or off)
    void set_state(bool light_state);

    //return the state of the light
    bool get_state();

    //change the colour of the light
    void set_colour(std::string colour);

    //get the colour of the light
    std::string get_colour();
    
    //destructor
    ~Lights();
};

#endif