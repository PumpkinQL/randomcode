#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

class Rooms {

public:
	Rooms();

	struct Weapons
	{
		std::string name;
		unsigned int hp;
		unsigned int damage;
		unsigned int cost;
		bool range;
	};

	struct Items
	{
		std::string name;
		unsigned int cost;
	};

	struct Npc
	{
		bool exist;
		std::string name;
		bool good;
	};

	struct Locations
	{
		std::string name;
		std::string description;
		std::vector<std::string> directions;
		std::unordered_map<const char*, Items> items;
		std::unordered_map<const char*, Weapons> weapons;
		std::unordered_map<const char*, Npc> npc;

		std::string requirements;
	};

	std::string currentLocation;

	std::unordered_map<const char*, Locations> location;

};


