#include <iostream>
#include <vector>
#include "rooms.h"
#include <unordered_map>

//Name
//Description
//Directions <vector>
//Items					Item Name, Items Cost 
//Weapons               Name, HP, Damage, Cost, Bool Range, Bool cost
//NPC					Bool exist, name,  Bool good
//Requirements

//Kitchen
//Bedroom
//Living Room
//Garden

void Rooms::createRoom(std::string name) {
	Location loc;
	loc.name = name;
	location[name] = loc;
}

void Rooms::addItem(std::string room, Item item) {
	location[room].itemMap[item.name] = location[room].items.size();
	location[room].items.push_back(item);
}

void Rooms::addWeapon(std::string room, Weapon weapon) {
	location[room].weaponMap[weapon.name] = location[room].weapons.size();
	location[room].weapons.push_back(weapon);
}

void Rooms::addNpc(std::string room, Npc npc) {
	location[room].itemMap[npc.name] = location[room].npc.size();
	location[room].npc.push_back(npc);
}

void Rooms::addDirections(std::string room, std::string direction) {
	location[room].directionMap[direction] = location[room].directions.size();
	location[room].directions.push_back(direction);
}

void Rooms::addRequirement(std::string room, std::string requirement) {
	location[room].requirement = requirement;
}

std::vector<Rooms::Item> Rooms::getItem(std::string room) {
	return location[room].items;
}

std::vector<Rooms::Weapon> Rooms::getWeapon(std::string room) {
	return location[room].weapons;
}

std::vector<Rooms::Npc> Rooms::getNpc(std::string room) {
	return location[room].npc;
}

std::string Rooms::getRequirement(std::string room) {
	return location[room].requirement;
}

std::string Rooms::getName(std::string room) {
	return location[room].name;
}

std::string Rooms::getDescription(std::string room) {
	return location[room].description;
}





Rooms::Rooms()
{
	// Kitchen Details
	createRoom(kitchen);
	Item kitchen_items[2] =
	{
		{
			/* Taken     */	false,
			/* Name      */ "Remote Control",
			/* Item Cost */ 0,
		},
		{
			/* Taken     */ false,
			/* Name      */ "Chocolate Bar",
			/* Item Cost */ 5,
		}
	};

	Weapon kitchen_weapons =
	{
		/* Taken  */ false,
		/* Name   */ "Knife",
		/* HP     */ 5,
		/* Damage */ 10,
		/* Cost * */ 25,
		/* Range  */ false,

	};

	Npc kitchen_npc =
	{
		/* NPC  */ false,
		/* Name */ "Mother",
		/* Cost */ false,
	};


	//Adding to Kitchen
	location[kitchen].description = "The main functions of a kitchen are to store, prepare and cook food.";

	addItem(kitchen, kitchen_items[0]);
	addItem(kitchen, kitchen_items[1]);
	addWeapon(kitchen, kitchen_weapons);
	addNpc(kitchen, kitchen_npc);
	addDirections(kitchen, living_room);
	addDirections(kitchen, garden);
	addRequirement(kitchen, "None");

	// Living Room Details
	createRoom(living_room);
	Item livingroom_items[2] =
	{
		{
			/* Taken     */	false,
			/* Name      */ "Remote Control",
			/* Item Cost */ 0,
		},
		{
			/* Taken     */ false,
			/* Name      */ "Chocolate Bar",
			/* Item Cost */ 5,
		}
	};

	Weapon livingroom_weapons =
	{
		/* Taken  */ false,
		/* Name   */ "Knife",
		/* HP     */ 5,
		/* Damage */ 10,
		/* Cost * */ 25,
		/* Range  */ false,

	};

	Npc livingroom_npc =
	{
		/* NPC  */ false,
		/* Name */ "Mother",
		/* Cost */ false,
	};
	//location[living_room].name = "Living Room";
	location[living_room].description = "The main functions of a kitchen are to store, prepare and cook food.";
	addItem(living_room, livingroom_items[0]);
	addItem(living_room, livingroom_items[1]);
	addWeapon(living_room, livingroom_weapons);
	addNpc(living_room, livingroom_npc);
	addDirections(living_room, garden);
	addRequirement(living_room, "None");

	//Adding Garden
	createRoom(garden);
	Item garden_items =
	{
		/* Taken     */	false,
		/* Name      */ "Trowel",
		/* Item Cost */ 0,
	};

	Weapon garden_weapons =
	{
		/* Taken  */ false,
		/* Name   */ "Fork",
		/* HP     */ 10,
		/* Damage */ 5,
		/* Cost * */ 30,
		/* Range  */ false,
	};

	Npc garden_npc =
	{
		/* NPC  */ false,
		/* Name */ "Mother",
		/* Cost */ false,
	};

	location[garden].description = "ADD LATER";

	addItem(garden, garden_items);
	addWeapon(garden, garden_weapons);
	addNpc(garden, garden_npc);
	addDirections(garden, bedroom);
	addRequirement(garden, "None");

	//Adding Bedroom
	createRoom(bedroom);
	Item bedroom_items =
	{
		/* Taken     */	false,
		/* Name      */ "Trowel",
		/* Item Cost */ 0,
	};

	Weapon bedroom_weapons =
	{
		/* Taken  */ false,
		/* Name   */ "Fork",
		/* HP     */ 10,
		/* Damage */ 5,
		/* Cost * */ 30,
		/* Range  */ false,
	};

	Npc bedroom_npc =
	{
		/* NPC  */ false,
		/* Name */ "Mother",
		/* Cost */ false,
	};

	location[garden].description = "ADD LATER";

	addItem(bedroom, bedroom_items);
	addWeapon(bedroom, bedroom_weapons);
	addNpc(bedroom, bedroom_npc);
	addDirections(bedroom, living_room);
	addRequirement(bedroom, "None");

}





