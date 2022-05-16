#include <iostream>
#include <string>
#include "Media_Device.h"

Media_Device::Media_Device(){
    //default media device constructor
    the_media_state = false;
    the_media_volume_level = 0;
    current_channel = "ABC3";
}

Media_Device::Media_Device(bool media_state, int media_volume_level, std::string new_channel){
    //media device with user input
    //media state level
    the_media_state = media_state;
    if (the_media_state == true){
        std::cout << "The media device is on" << std::endl;
    }
    else if(the_media_state == true){
        std::cout << "The media device is off" << std::endl;
    }
    //media volume level
    if ((media_volume_level >= 0 && media_volume_level <= 100) || (the_media_state == true)){
        the_media_volume_level = media_volume_level;
    }
    else{
        the_media_volume_level = 0;
    }
    std::cout << "The device's volume is: " << the_media_volume_level << std::endl;
    //media channel
    if (the_media_state == true){
        current_channel = new_channel;
    }
    std::cout << "You are on " << current_channel << std::endl;
}

void Media_Device::set_media_state(bool media_state){
    //settin media state
    the_media_state = media_state;
    if (media_state == true){
        std::cout << "The media device is on!" << std::endl;
    }
    else if(media_state == false){
        std::cout << "The media device is off!" << std::endl;
    }
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
    std::cout << "The device's volume is: " << the_media_volume_level << std::endl;
}

int Media_Device::get_media_volume(){
    //getting media volume level
    return the_media_volume_level;
}

void Media_Device::set_current_channel(std::string new_channel){
    if (the_media_state == true){
        current_channel = new_channel;
    }
    std::cout << "You are on " << current_channel << std::endl;
}

std::string Media_Device::get_current_channel(){
    return current_channel;
}

Media_Device::~Media_Device(){
    //default destructor
}