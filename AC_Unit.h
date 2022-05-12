#ifndef AC_UNIT_H
#define AC_UNIT_H

#include <iostream>
#include <string>

class AC_Unit{
private:
    std::string AC_unit_name;
    float AC_temperature;
    int current_fan_speed;
    bool AC_on_or_off;
public:
    //default AC_Unit constructor
    AC_Unit();
        
    //AC_Unit constructor with user input
    AC_Unit(std::string AC_name, float original_temp, int AC_fan_speed, bool AC_on);

    //setting AC Name
    void set_name(std::string AC_name);

    //getting AC Name
    std::string get_name();

    //setting AC state
    void set_state(bool AC_on);

    //getting AC temperature
    bool get_state();

    //setting AC temperature
    void set_AC_temp(float original_temp);

    //getting AC temperature
    float get_AC_temp();

    //setting AC fan speed
    void set_AC_speed(int AC_fan_speed);

    //getting AC Name
    float get_AC_speed();

    //destructor
    ~AC_Unit();
};

#endif