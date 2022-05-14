#include <iostream>
#include <string>
#include "Media_Device.h"
#include "Smart_Speaker.h"

Smart_Speaker::Smart_Speaker(){
    //default constructor for smart speaker
    the_smart_speaker_name = "TV2";
    the_media_state = false;
    current_speaker_channel ="No_signal";
    smart_speaker_volume = 3;
    current_audio = "nothing playing";

}

Smart_Speaker::Smart_Speaker(std::string current_speaker_audio){
    //constructor with user input
    the_smart_speaker_name = the_media_name;
    if (the_media_state == false){
        current_speaker_channel = "No_signal";
        smart_speaker_volume = 0;
        current_audio = "nothing playing";
    }
    else{
        current_speaker_channel = current_channel;

        //tv volume is between 0 and 100 inclusive
        if (the_media_volume_level >= 0 && the_media_volume_level <= 100){
            smart_speaker_volume = the_media_volume_level;
        }
        else{
            smart_speaker_volume = 0;
        }
        current_audio = current_speaker_audio;
    }
}

//inherited functions

void Smart_Speaker::set_media_volume(int media_volume_level){
    //setting the speaker volume, between 0-100 inclusive
    if ((the_media_volume_level >= 0 && the_media_volume_level <= 100) && (the_media_state == true)){
        smart_speaker_volume = media_volume_level;
    }
    else{
        smart_speaker_volume = 0;
    }
}

int Smart_Speaker::get_speaker_volume(){
    //getting the speaker volume
    return smart_speaker_volume;

}

void Smart_Speaker::set_current_channel(std::string new_channel){
    //changing the current channel
    if (the_media_state == true){
        current_speaker_channel = new_channel;
    }
    else{
        current_speaker_channel = "No_signal";
    }

}

std::string Smart_Speaker::get_current_channel(){
    //getting the current channel
    return current_speaker_channel;
}

//making the functions specific to this class

void Smart_Speaker::set_current_audio(std::string current_speaker_audio){
    //setting the current audio
    if (the_media_state == true){
        current_audio = current_speaker_audio;
    }
    else{
        current_audio = "Nothing playing";
    }

}

std::string Smart_Speaker::get_current_audio(){
    //getting the current audio
    return current_audio;
}

Smart_Speaker::~Smart_Speaker(){
    //default destructor
}