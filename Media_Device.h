#ifndef MEDIA_DEVICE_H
#define MEDIA_DEVICE_H

#include <iostream>
#include <string>
#include "Interactable.h"

class Media_Device: public Interactable {
protected:
    bool the_media_state;
    int the_media_volume_level;
    std::string current_channel;

public:
    //default media device constructor
    Media_Device();

    //media device with user input
    Media_Device(bool media_state, int media_volume_level, std::string new_channel);

    //settin media state
    void set_media_state(bool media_state);

    //getting media state
    bool get_media_state();

    //setting media volume level
    //volume is 0-100
    virtual void set_media_volume(int media_volume_level);

    //getting media volume level
    int get_media_volume();

    //changing the channel
    virtual void set_current_channel(std::string new_channel);

    //getting the current channel
    std::string get_current_channel();

    //default destructor
    ~Media_Device();
};

#endif