#ifndef ROOMS_H
#define ROOMS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


class Rooms {
private:
	std::string living_room = "Living room";
	std::string garden = "Garden";
	std::string bedroom = "Bedroom";
	std::string kitchen = "Kitchen";

public:
	Rooms();

	struct Weapon
	{
		bool taken;
		std::string name;
		std::string item_description;
		unsigned int hp;
		unsigned int damage;
		unsigned int cost;
		bool range;
	};

	struct Item
	{
		bool taken;
		std::string name;
		std::string item_description;
		unsigned int cost;
	};

	struct Good_Npc
	{
		bool exist;
		std::string npc_name;
		std::string npc_description;
		std::string npc_task;
		int npc_health;
		std::string gender;
	};

	struct Bad_Npc
	{
		bool exist;
		std::string npc_name;
		std::string npc_description;
		std::string npc_task;
		int npc_health;
		std::string gender;
		Weapon weapon;
	};

	struct Location
	{
		std::string name;
		std::string description;
		std::vector<std::string> directions;
		std::unordered_map<std::string, int> itemMap;
		std::unordered_map<std::string, int> weaponMap;
		//std::unordered_map<std::string, int> npcMap;
		std::unordered_map<std::string, int> directionMap;
		std::vector<Item> items;
		std::vector<Weapon> weapons;
		std::vector<Bad_Npc> badNpc;
		std::vector<Good_Npc> goodNpc;
		std::string requirement;
		int time = 0;
		int (*function)();
	};


	std::string currentLocation;
	std::unordered_map<std::string, Location> location;
	void createRoom(std::string name);
	void addItem(std::string room, Item item); 
	void addWeapon(std::string room, Weapon weapon);
	void addNpc(std::string room, Good_Npc npc);
	void addNpc(std::string room, Bad_Npc npc);
	void addDirections(std::string room, std::string directions);
	void addRequirement(std::string room, std::string requirement);
	std::vector<Item> getItems(std::string room);
	std::vector<Weapon> getWeapons(std::string room);
	//std::vector<Npc> getNpcs(std::string room);
	std::string getRequirement(std::string room);
	std::string getName(std::string room);
	std::string getDescription(std::string room);

	void setTakenItem(std::string item);
	void setTakenWeapon(std::string item);
};


#endif