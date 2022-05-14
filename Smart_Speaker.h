#ifndef SMART_SPEAKER_H
#define SMART_SPEAKER_H

#include <iostream>
#include <string>
#include "Media_Device.h"

class Smart_Speaker: public Media_Device{
private:
    //inheritad from the parent class (media device)
    int smart_speaker_volume;
    std::string the_smart_speaker_name;
    bool the_smart_speaker_state;
    std::string current_speaker_channel;
    //specific to this class
    std::string current_audio;

public:
    //default constructor for smart speaker
    Smart_Speaker();

    //constructor with user input
    Smart_Speaker(std::string current_speaker_audio);

    //inherited functions
    //setting the speaker volume, between 0 and 100 inclusive
    void set_media_volume(int media_volume_level);
    
    //getting the speaker volume
    int get_speaker_volume();

    //changing the current channel
    void set_current_channel(std::string new_channel);

    //getting the current channel
    std::string get_current_channel();

    //making the functions specific to this class
    //setting the current audio
    void set_current_audio(std::string current_speaker_audio);

    //getting the current audio
    std::string get_current_audio();

    //default destructor
    ~Smart_Speaker();

};

#endif