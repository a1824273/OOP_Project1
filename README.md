# Welcome to DJ's Virtual Smart Home System.
(Please navigate to project branch!)   
From here you can control an array of home devices and fixtures we refer to as "Interactables", all through a command line system.
The system works inside a home, which contains rooms, and these rooms contain the interactables.

# Syntax Guide:

### Loading in a saved home:
To load in a saved home, make sure there are no rooms currently in the house. Then use the following syntax:

	>>> read [home_name]

### Saving a Home:
	To save a home, follow the syntax:

	>>> write [home_name]

(Be warned if a save already exists with that name, it will be overwritten!)

### Getting Started with a new Home:
You can't have a smart home without rooms to put them in! To begin then, we must add a room to the home.
This is achieved through the 'add' command which follows the syntax:

	>>> add Room [room_name]

This command is also used to add interactables to the room, using the syntax:

	>>> add [interactable_type] [interactable_name] [room_name]

The interactable types we currently support are:
- Lights
- Door
- AC_Unit
- Smart_Speaker
- Smart_Television

After specifying the type of device you would like to add, give it a name and choose the room you would like to add it to
Be careful, your room needs to exist before adding an interactable to it.

### Viewing Your Home:
So you've got some interactable's and now you want to view your home. Look no further than the "list" command.

To list the rooms in the house:

	>>> list Rooms

To view the contents of a room, use:

	>>> list [room_name]

Or to view the properies of an interactable

	>>> list [interactable_name] [room_name]

By requiring you to specify the room of this interactable, it allows you to have multiple devices with the same name, but spread over different rooms

### Removing a Room or Interactable:
So now you want to get rid of an interactable, or even a whole room!

To remove a room from the house:

	>>> remove [room_name]

or to remove an interactable from a rome:

	>>> remove [interactable_name] [room_name]


### Changing Device Properies:
So you can make and look at interactables, but what about doing something with them?
This is where the set command comes in.
This command has one implementation but follows a strict syntax:

	>>> set [interactable_name] [room_name] [property] [status]

Each type of interactable has it's own properties and subsequent values and these are explored below.

### Lights:
Lights have the abbility to be turned on and off, as well as the ability to change colour.

onoff: on / off
      
	e.g. >>> set Lamp Bedroom onoff on

colour: string representing required colour

	e.g. >>> set Lamp Bedroom colour red

### Doors:
Simply a lock and unlock feature:

lock: lock / unlock

	e.g. >>> set Front_Door Kitchen lock unlock

### AC_Unit:
Controls for onoff, the speed and temperature

onoff: on / off

	e.g. >>> set Fan Bedroom onoff on

speed: accepts an integer between 1 and 5

	e.g. >>> set Fan Bedroom speed 4

temp: accepts a floating point number between 0 and 100

	e.g. >>> set Fan Bedroom speed 17.6

### Smart_Devces (Smart_Speaker and Smart_Television):
Control for onoff, volume and channel
Smart_Television has exclusive feature for brightness as well

onoff: on / off

	e.g. >>> set TV Office onoff off

volume: accepts an integer between 0 and 100

	e.g. >>> set Nest Bedroom volume 45

channel: accepts a string correlating to the desired channel

	e.g. >>> set TV Bedroom channel Food_Network

#### Smart_Television Exclusive:
brightness: accepts and integer between 0 and 5

	e.g. >>> set TV Office brightness 3
