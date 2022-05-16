#ifndef SMART_TELEVISION_H
#define SMART_TELEVISION_H

#include <iostream>
#include <string>
#include "Media_Device.h"
#include "Interactable.h"

class Smart_Television: public Media_Device {
private:
    //inherited from the parent class (media device)
    int smart_television_volume;
    bool the_smart_television_state;
    std::string current_television_channel;
    //specific to this class
    int brightness_level;

public:
    //default media constructor
    Smart_Television();

    //media device constructor with user input
    Smart_Television(int tv_brightness);

    //inherited functions
    //changing the televison volume, between 0-100 inclusive
    void set_media_volume(int media_volume_level);
    
    //getting the television volume
    int get_television_volume();

    //changing the current channel
    void set_current_channel(std::string new_channel);

    //getting the current channel
    std::string get_current_channel();
    



    //function specific tp the smart television class
    //changing the brigthness of the televison
    void set_brightness_level(int tv_brightness);

    //getting the current channel brightness
    int get_brightness_level();
    
    //default Smart_Television desctructor
    ~Smart_Television();
};

#endif