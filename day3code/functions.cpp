#include "includes.h"
#include "rooms.h"

int records_length = *(&records + 1) - records;

extern int index;
extern int gold_count;
extern std::string current_location;
extern std::string previous_location;
extern std::vector<item> inventory;

void game_load()
{
	std::ifstream fs("saved_location.txt");
	std::getline(fs, current_location);
}

void previous_location_save()
{
	std::ifstream fs("previous_location.txt");
	std::getline(fs, previous_location);
}

std::vector<std::string> inventory_load()
{
	std::ifstream fs("inventory.txt");
	std::string temp;
	std::vector<std::string> inventory;
	while (fs >> temp)
		inventory.push_back(temp);

	return inventory;
}

void load_gold()
{
	std::ifstream fs("load_count.txt");
	fs >> gold_count;
}

int current_location_index(std::string current_location)
{
	for (int i = 0; i < records_length; i++)
		if (records[i].name == current_location)
			return i;
}

void item_details(int i, int j)
{
	if (records[i].items[j].item_name != "[COLLECTED]")
	{
		std::cout << index << ": " << std::endl;
		std::cout << " [      Item Name     ] " << records[i].items[j].item_name << std::endl;
		std::cout << " [  Item Description  ] " << records[i].items[j].item_description << std::endl;
		std::cout << " [    Attack Power    ] " << records[i].items[j].item_attack_power << std::endl;
		std::cout << " [      Item Cost     ] " << records[i].items[j].item_cost << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "[COLLECTED]" << std::endl;
		std::cout << std::endl;
	}

}

void print_location_details(int i)
{
	std::cout << "Location name: " << records[i].name << std::endl;
	std::cout << "Location Description: " << records[i].description << std::endl;
	std::cout << "Places to go: " << std::endl;
	std::cout << std::endl;
	if (records[i].directions.size() > 0)
		for (int j = 0; j < records[i].directions.size(); j++)
		{
			index++;
			std::cout << index << ": " << records[i].directions[j] << std::endl;
		}
	std::cout << std::endl;
	if (records[i].items.size() > 0)
		for (int j = 0; j < records[i].items.size(); j++)
		{
			index++;
			item_details(i, j);
		}
	std::cout << std::endl;
	if (records[i].coins > 0)
	{
		std::cout << "Gold found in this location: " << records[i].coins << std::endl;
		gold_count += records[i].coins;
	}
	else
		std::cout << "There is no gold in this location to be picked up" << std::endl;

	std::cout << "Your gold count: " << gold_count << std::endl;
}

void print_inventory(std::vector<item> inventory)
{
	if (inventory.size() > 0)
	{
		std::cout << "Invetory: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < inventory.size(); i++)
			std::cout << inventory[i].item_name << std::endl;
	}
	else
		std::cout << "Inventory is currently empty." << std::endl;
}

bool enemy_npc(int i)
{
	if (records[i].npcs.npc_name != "None")
	{
		std::cout << records[i].npcs.npc_name << std::endl;
		std::cout << records[i].npcs.npc_lines << std::endl;
		std::cout << "Enemy health: " << records[i].npcs.npc_health << std::endl;
		std::cout << "Enemy damage: " << records[i].npcs.npc_damage << std::endl;
		return true;
	}
	else return false;
}

bool fight_or_goback()
{
	std::cout << "fight or go back? ";
	while (1)
	{
		std::string user_input;
		std::getline(std::cin, user_input);
		if (user_input == "fight")
			return true;
		else if (user_input == "go back")
			return false;
		else
			std::cout << "Type 'fight' or 'go back' ";
	}
}

bool fight(int i, std::vector<item> inventory)
{
	for (int j = 0; j < inventory.size(); j++)
	{
		if (inventory[j].item_attack_power >= records[i].npcs.npc_health)
		{
			std::cout << records[i].npcs.npc_name << " has been defeated!" << std::endl;
			records[i].npcs.npc_name = "None";
			Sleep(2000);
			return true;
		}
		else if (j == inventory.size() - 1)
		{
			std::cout << "Game Over!" << std::endl;
			Sleep(2000);
			return false;
		}
	}
}

bool check_location_requirement(int i, int user_input)
{
	current_location = records[i].directions[user_input - 1];
	int j = current_location_index(current_location);
	if (records[j].requirement == "None")
		return true;
	else
	{
		for (int k = 0; k < inventory.size(); k++)
			if (inventory[k].item_name == records[j].requirement)
				return true;

		current_location = previous_location;
		return false;
	}
}

void get_user_input(int index, int i)
{
	int user_input;
	bool correct_input = true;
	while (correct_input)
	{
		while (1)
		{
			std::cin >> user_input;
			if (user_input != 0 && user_input <= index)
				goto action;
			else
				std::cout << "Option does not exist" << std::endl;
		}
	action:
		if (user_input <= records[i].directions.size())
		{
			if (check_location_requirement(i, user_input))
			{
				current_location = records[i].directions[user_input - 1];
				correct_input = false;
			}
			else
				std::cout << "Requirement not met" << std::endl;
		}
		else
		{
			user_input -= records[i].directions.size();
			if (records[i].items[user_input - 1].item_name != "[COLLECTED]")
			{
				if (records[i].items[user_input - 1].item_cost <= gold_count)
				{
					inventory.push_back(records[i].items[user_input - 1]);
					records[i].items[user_input - 1].item_name = "[COLLECTED]";
					gold_count -= records[i].items[user_input - 1].item_cost;
					correct_input = false;
				}
				else
					std::cout << "You cannot afford this item!" << std::endl;
			}
			else
				std::cout << "Item has already been collected" << std::endl;
		}
	}
}

void clear_system()
{
	if (system("CLS"))
		system("clear");

	index = 0;
}
