#include <iostream>

#include "player.h"


void Player::addItem(Rooms::Item item) {
	itemsMap[item.name] = items.size();
	items.push_back(item);
}


void Player::addWeapon(Rooms::Weapon weapon) {
	weaponsMap[weapon.name] = weapons.size();
	weapons.push_back(weapon);
}


Rooms::Item Player::getItem(std::string name) {
	return items[itemsMap[name]];
}


Rooms::Weapon Player::getWeapon(std::string name) {
	return weapons[weaponsMap[name]];
}