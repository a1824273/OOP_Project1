#include <iostream>
#include <string>
#include "Media_Device.h"
#include "Smart_Television.h"


Smart_Television::Smart_Television(){
    //default media constructor
    the_smart_television_name = "TV1";
    the_media_state = false;
    current_televsion_channel = "No signal";
    smart_television_volume = 3;
    brightness_level = 0;
}

Smart_Television::Smart_Television(int tv_brightness){
    //media device constructor with user input
    the_smart_television_name = the_media_name;
    if (the_media_state == false){
        current_televsion_channel = "No signal";
        smart_television_volume = 0;
        brightness_level = 0;
    }
    else{
        current_televsion_channel = current_channel;

        //tv volume is between 0 and 100 inclusive
        if (the_media_volume_level >= 0 && the_media_volume_level <= 100){
            smart_television_volume = the_media_volume_level;
        }
        else{
            smart_television_volume = 0;
        }
        //tv brightness between 0 and 5 inclusive
        if (tv_brightness >= 0 && tv_brightness <= 5){
            brightness_level = tv_brightness;
        }
        else {
            brightness_level = 0;
        }

    }
}

//inherited functions
void Smart_Television::set_media_volume(int media_volume_level){
    //changing the televison volume, between 0-100 inclusive
    if ((the_media_volume_level >= 0 && the_media_volume_level <= 100) && (the_media_state == true)){
        smart_television_volume = media_volume_level;
    }
    else{
        smart_television_volume = 0;
    }
}

int Smart_Television::get_television_volume(){
    //getting the television volume
    return smart_television_volume;
}

//probably can take it from the media device
void Smart_Television::set_current_channel(std::string new_channel){
    //changing the current channel
    if (the_media_state == true){
        current_televsion_channel = new_channel;
    }
    else{
        current_televsion_channel = "No signal";
    }
}

std::string Smart_Television::get_current_channel(){
    //getting the current channel
    return current_televsion_channel;

}


//function specific tp the smart television class

void Smart_Television::set_brightness_level(int tv_brightness){
    //changing the brigthness of the televison
    if ((the_media_state == true) && (tv_brightness >= 0 && tv_brightness <= 5)){
        brightness_level = tv_brightness;
    }
    else{
        std::cout << "Brightness level outside of 0 to 5 range." << std::endl;
    }
}

int Smart_Television::get_brightness_level(){
    //getting the current channel brightness
    return brightness_level;
}

Smart_Television::~Smart_Television(){
    //default Smart_Television desctructor
}