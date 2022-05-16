#ifndef LIGHTS_H
#define LIGHTS_H

#include <iostream>
#include <string>

using namespace std;

class Lights: public Interactable{
private:
    string thee_light_colour;
    bool light_on_state;
public:
    //creating a default light object with a light name, light colour and status of the light
    Lights();

    //making a light variable will the light name, light colour and on off state
    Lights(string light_colour, bool state_of_light);

    //change the state of the light (i.e. on or off)
    void set_state(bool light_state);

    //return the state of the light
    bool get_state();

    //change the colour of the light
    void set_colour(string colour);

    //get the colour of the light
    string get_colour();
    
    //destructor
    ~Lights();
};

#endif