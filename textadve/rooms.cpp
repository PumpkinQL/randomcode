#include <iostream>
#include <vector>
#include "rooms.h"
#include <unordered_map>

extern std::string current_location;
#define LOCATION location[current_location]

extern int kitchenFunc();

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

void Rooms::addNpc(std::string room, Bad_Npc npc) {
	location[room].badNpc.push_back(npc);
}

void Rooms::addNpc(std::string room, Good_Npc npc) {
	location[room].goodNpc.push_back(npc);
}

void Rooms::addDirections(std::string room, std::string direction) {
	location[room].directionMap[direction] = location[room].directions.size();
	location[room].directions.push_back(direction);
}

void Rooms::addRequirement(std::string room, std::string requirement) {
	location[room].requirement = requirement;
}

std::vector<Rooms::Item> Rooms::getItems(std::string room) {
	return location[room].items;
}

std::vector<Rooms::Weapon> Rooms::getWeapons(std::string room) {
	return location[room].weapons;
}

//std::vector<Rooms::Npc> Rooms::getNpcs(std::string room) {
//	return location[room].npc;
//}

std::string Rooms::getRequirement(std::string room) {
	return location[room].requirement;
}

std::string Rooms::getName(std::string room) {
	return location[room].name;
}

std::string Rooms::getDescription(std::string room) {
	return location[room].description;
}


void Rooms::setTakenItem(std::string item) {
	LOCATION.items[LOCATION.itemMap[item]].taken = true;
	//else std::cout << "Congratualations. You have thoroughly broken the game.\nPlease report this bug we beg you.\n";
}

void Rooms::setTakenWeapon(std::string item) {
	LOCATION.weapons[LOCATION.weaponMap[item]].taken = true;
}





Rooms::Rooms()
{
	// Kitchen Details
	createRoom(kitchen);
	Item kitchen_items[2] =
	{
		{
			/* Taken       */	false,
			/* Name        */ "Bottle",
			/* Description */ "Contains some dubious liquid",
			/* Item Cost   */ 0,
		},
		{
			/* Taken       */	false,
			/* Name        */ "Pan",
			/* Description */ "Quite rusty",
			/* Item Cost   */ 0,
		}
	};

	Weapon kitchen_weapons =
	{
		/* Taken       */ false,
		/* Name        */ "Knife",
		/* Description */ "A sharp edged object used to cut food",
		/* HP          */ 5,
		/* Damage      */ 10,
		/* Cost *      */ 25,
		/* Range       */ false,

	};

	Bad_Npc kitchen_npc =
	{
		/* NPC         */ true,
		/* Name        */ "Mother",
		/* Description */ "A fierce warrior who will put you to bed",
		/* Task		   */ "Will kill you",
		/* Health      */ 25,
		/* Gender      */ "She",
		/* Weapon      */
		{
			false,
			"Sword",
			"Sharp Object",
			0,
			20,
			0,
			false,
		}
	};


	//Adding to Kitchen
	location[kitchen].description = "The main functions of a kitchen are to store, prepare and cook food.";
	location[kitchen].function = &kitchenFunc;
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
			/* Taken       */ false,
			/* Name        */ "Apple",
			/* Description */ "Some magic item from a magical world",
			/* Item Cost   */ 0,
		},
		{
			/* Taken       */ false,
			/* Name        */ "Remote control",
			/* Description */ "Some magic item from a magical world",
			/* Item Cost   */ 0,
		}
	};

	Weapon livingroom_weapons =
	{
		/* Taken       */ false,
		/* Name        */ "Gun",
		/* Description */ "A sharp edged object used to cut food",
		/* HP          */ 5,
		/* Damage      */ 10,
		/* Cost *      */ 25,
		/* Range       */ false,

	};

	//location[living_room].name = "Living Room";
	location[living_room].description = "An area for rest and entertainment";
	addItem(living_room, livingroom_items[0]);
	addItem(living_room, livingroom_items[1]);
	addWeapon(living_room, livingroom_weapons);
	//addNpc(living_room, livingroom_npc);
	addDirections(living_room, garden);
	addDirections(living_room, bedroom);
	addRequirement(living_room, "None");

	//Adding Garden
	createRoom(garden);
	Item garden_items =
	{
		/* Taken       */ false,
		/* Name        */ "Gnome",
		/* Description */ "Some magic item from a magical world",
		/* Item Cost   */ 0,
	};

	Weapon garden_weapons =
	{
		/* Taken       */ false,
		/* Name        */ "Shovel",
		/* Description */ "A sharp edged object used to cut food",
		/* HP          */ 5,
		/* Damage      */ 10,
		/* Cost *      */ 25,
		/* Range       */ false,
	};

	//Npc garden_npc =
	//{
	//	/* NPC         */ false,
	//	/* Name        */ "Mother",
	//	/* Description */ "A fierce warrior who will put you to bed",
	//	/* Task		   */ "Kill the wild travel",
	//	/* Health      */ 25,
	//	/* Damage      */ 10,
	//	/* Cost        */ false,
	//};

	location[garden].description = "ADD LATER";

	addItem(garden, garden_items);
	addWeapon(garden, garden_weapons);
	//addNpc(garden, garden_npc);
	addDirections(garden, kitchen);
	//addDirections(garden, bedroom);
	addRequirement(garden, "None");

	//Adding Bedroom
	createRoom(bedroom);
	Item bedroom_items =
	{
		/* Taken       */ false,
		/* Name        */ "Keys",
		/* Description */ "Some magic item from a magical world",
		/* Item Cost   */ 0,
	};

	Weapon bedroom_weapons =
	{
		/* Taken       */ false,
		/* Name        */ "Kitchen knife",
		/* Description */ "A sharp edged object used to cut food",
		/* HP          */ 5,
		/* Damage      */ 10,
		/* Cost *      */ 25,
		/* Range       */ false,
	};

	//Npc bedroom_npc =
	//{
	//	/* NPC         */ false,
	//	/* Name        */ "Mother",
	//	/* Description */ "A fierce warrior who will put you to bed",
	//	/* Task		   */ "Kill the wild travel",
	//	/* Health      */ 25,
	//	/* Damage      */ 10,
	//	/* Cost        */ false,
	//};

	addItem(bedroom, bedroom_items);
	addWeapon(bedroom, bedroom_weapons);
	//addNpc(bedroom, bedroom_npc);
	addDirections(bedroom, living_room);
	addRequirement(bedroom, "None");

}





