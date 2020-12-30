#pragma once
#include <iostream>
#include <vector>

struct item
{
	std::string item_name;
	std::string item_description;
	int item_attack_power;
	int item_cost;
};

struct npc
{
	std::string npc_name;
	std::string npc_lines;
	int npc_health;
	int npc_damage;
};

struct locations
{
	std::string name;
	std::string description;
	std::string requirement;
	std::vector<std::string> directions;
	std::vector<item> items;
	int coins;
	npc npcs;
};

extern locations records[4];