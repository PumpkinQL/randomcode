#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <unordered_map>
#include "rooms.h"

class Player{
public:

	std::vector<Rooms::Item> items;
	std::vector<Rooms::Weapon> weapons;
	std::unordered_map<std::string, int> itemsMap;
	std::unordered_map<std::string, int> weaponsMap;

	unsigned int hp = 100;
	float armourStrength = 1.0f;

	void addItem(Rooms::Item item);
	void addWeapon(Rooms::Weapon weapon);
	Rooms::Item getItem(std::string name);
	Rooms::Weapon getWeapon(std::string name);
};


#endif