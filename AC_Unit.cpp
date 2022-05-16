#include <iostream>
#include <string>
#include "AC_Unit.h"


AC_Unit::AC_Unit(){
    //default AC_Unit constructor
    AC_unit_name = "AC Unit 1";
    AC_temperature = 26.0;
    current_fan_speed = 0;
    AC_on_or_off = false;
}
        
AC_Unit::AC_Unit(std::string AC_name, float original_temp, int AC_fan_speed, bool AC_on){
    //AC_Unit constructor with user input
    AC_unit_name = AC_name;
    
    //AC temp has to be above 0, less than 100
    if (original_temp > 0 && original_temp < 100){
        AC_temperature = original_temp;
    }
    else{
        std::cout << "The temperature is invalid." << std::endl;
        std::cout << "Temperature has been set to 26.0 degrees Celcius." << std::endl;
        AC_temperature = 26.0;
    }

    //current fan speed has to be between 1 and 5, both inclusive
    if ((AC_fan_speed >= 1 && AC_fan_speed <= 5) || (AC_on_or_off == true)){
        current_fan_speed = AC_fan_speed;
    }
    else{
        std::cout << "The speed is invalid." << std::endl;
        std::cout << "The speed has been set to 0." << std::endl;
        current_fan_speed = 0;
    }
    AC_on_or_off = AC_on;
}

void AC_Unit::set_name(std::string AC_name){
    //setting AC Name
    AC_unit_name = AC_name;
}

std::string AC_Unit::get_name(){
    //getting AC Name
    return AC_unit_name;
}

void AC_Unit::set_state(bool AC_on){
    //setting AC state
    AC_on_or_off = AC_on;   
}

bool AC_Unit::get_state(){
    //getting AC state
    return AC_on_or_off;
}

void AC_Unit::set_AC_temp(float original_temp){
    //setting AC temperature
    //AC temp has to be above 0, less than 100
    if (original_temp > 0 && original_temp < 100){
        AC_temperature = original_temp;
    }
    else{
        std::cout << "The temperature is invalid." << std::endl;
        std::cout << "Temperature has been set to 26.0 degrees Celcius." << std::endl;
        AC_temperature = 26.0;
    }
}

float AC_Unit::get_AC_temp(){
    //getting AC temperature
    return AC_temperature;
}

void AC_Unit::set_AC_speed(int AC_fan_speed){
    //setting AC fan speed
    //current fan speed has to be between 1 and 5, both inclusive
    if ((AC_fan_speed >= 1 && AC_fan_speed <= 5) || (AC_on_or_off == true)){
        current_fan_speed = AC_fan_speed;
    }
    else{
        std::cout << "The speed is invalid." << std::endl;
        std::cout << "The speed has been set to 0." << std::endl;
        current_fan_speed = 0;
    }
}

float AC_Unit::get_AC_speed(){
    //getting AC Name
    return current_fan_speed;
}

AC_Unit::~AC_Unit(){
    //destructor
}
