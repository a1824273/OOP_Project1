#include <iostream>
#include <string>
#include "Media_Device.h"

Media_Device::Media_Device(){
    //default media device constructor
    the_media_name = "No media";
    the_media_state = false;
    the_media_volume_level = 0;
}

Media_Device::Media_Device(std::string media_name, bool media_state, int media_volume_level){
    //media device with user input
    the_media_name = media_name;
    the_media_state = media_state;
    if (media_volume_level >= 0 && media_volume_level <= 100){
        the_media_volume_level = media_volume_level;
    }
    else{
        the_media_volume_level = 0;
    }
    
}

void Media_Device::set_media_name(std::string media_name){
    //setting media name
    the_media_name = media_name;
}

std::string Media_Device::get_media_name(){
    //get media name
    return the_media_name;
}

void Media_Device::set_state(bool media_state){
    //settin media state
    the_media_state = media_state;
}

bool Media_Device::get_media_state(){
    //getting media state
    return the_media_state;
}

    
void Media_Device::set_media_volume(int media_volume_level){
    //setting media volume level
    //volume is 0-100
    if ((media_volume_level >= 0 && media_volume_level <= 100) && (the_media_state == true)){
        the_media_volume_level = media_volume_level;
    }
    else{
        the_media_volume_level = 0;
    }
}

int Media_Device::get_media_volume(){
    //getting media volume level
    return the_media_volume_level;
}

Media_Device::~Media_Device(){
    //default destructor
}