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
		unsigned int hp;
		unsigned int damage;
		unsigned int cost;
		bool range;
	};

	struct Item
	{
		bool taken;
		std::string name;
		unsigned int cost;
	};

	struct Npc
	{
		bool exist;
		std::string name;
		bool good;
	};

	struct Location
	{
		std::string name;
		std::string description;
		std::vector<std::string> directions;
		//std::unordered_map<const char*, Item> items;
		//std::unordered_map<const char*, Weapon> weapons;
		//std::unordered_map<const char*, Npc> npc;
		std::unordered_map<std::string, int> itemMap;
		std::unordered_map<std::string, int> weaponMap;
		std::unordered_map<std::string, int> npcMap;
		std::unordered_map<std::string, int> directionMap;
		std::vector<Item> items;
		std::vector<Weapon> weapons;
		std::vector<Npc> npc;
		std::string requirement;
	};

	std::string currentLocation;
	std::unordered_map<std::string, Location> location;
	void createRoom(std::string name);
	void addItem(std::string room, Item item); 
	void addWeapon(std::string room, Weapon weapon);
	void addNpc(std::string room, Npc npc);
	void addDirections(std::string room, std::string directions);
	void addRequirement(std::string room, std::string requirement);
	std::vector<Item> getItems(std::string room);
	std::vector<Weapon> getWeapons(std::string room);
	std::vector<Npc> getNpcs(std::string room);
	std::string getRequirement(std::string room);
	std::string getName(std::string room);
	std::string getDescription(std::string room);

	void setTakenItem(std::string item);
	void setTakenWeapon(std::string item);
};


#endif