#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "rooms.h"

int get_user_input(int option)
{
	bool user_dec = true;
	int user_input;
	int temp;
    while (user_dec)
	{
		std::cin >> temp;
		// Checks if the option exists
		if (temp > 0 && temp <= option)
		{
			user_input = temp;
			user_dec = false;
		}
		else if (temp == option + 1)
			return temp;
		else
			std::cout << "Option does not exist" << std::endl;
	}

	return user_input;
}

void print_items(int i, int j)
{
	std::cout << " [      Item Name     ] " << records[i].items[j].item_name << std::endl;
	std::cout << " [  Item Description  ] " << records[i].items[j].item_description << std::endl;
	std::cout << " [    Attack Power    ] " << records[i].items[j].item_attack_power << std::endl;
	std::cout << " [      Item Cost     ] " << records[i].items[j].item_cost << std::endl;
}

void clear_console()
{
	if (system("CLS"))
		system("clear");
}

std::string game_save()
{
	std::ifstream load_location;
	load_location.open("saved_location.txt");
	std::string current_location;
	std::getline(load_location, current_location);
	load_location.close();
	return current_location;
}

std::string load_prev_location()
{
	std::ifstream load;
	load.open("previous_location.txt");
	std::string previous_location;
	load >> previous_location;
	load.close();
	return previous_location;
}

void prev_location(std::string current_loc)
{
	std::ofstream prev_location;
	prev_location.open("previous_location.txt");
	prev_location << current_loc << std::endl;
	prev_location.close();
}

int main()
{
	std::string current_location = game_save();
	std::string previous_location = load_prev_location();
	std::vector<item> inventory;
	int gold_count = 20;
	bool main_game = true;
	int records_size = *(&records + 1) - records;
main_loop:
	while (main_game)
	{
		// Counter for options
		int option = 0;
		// Cycles through all the locations
		for (int i = 0; i < records_size; i++)
			// Finds the location index
			if (current_location == records[i].name)
			{
				// Prints out all the location info
				std::cout << "You are at: " << records[i].name << std::endl;
				if (records[i].npcs.npc_name != "None")
				{
					std::cout << "You encounter a: " << records[i].npcs.npc_name << std::endl;
					std::cout << records[i].npcs.npc_lines << std::endl;
					std::cout << "Weapon power needed to defeat him: " << records[i].npcs.npc_health << std::endl;
					std::cout << "Fight or go back?" << std::endl;
					bool fight_or_flee = true;
					while (fight_or_flee)
					{
						std::string fight;
						std::getline(std::cin, fight);
						if (fight == "fight")
						{
							for (int j = 0; j < inventory.size(); j++)
							{
								if (inventory[j].item_attack_power >= records[i].npcs.npc_health)
								{
									std::cout << records[i].npcs.npc_name << " has been defeated!";
									records[i].npcs.npc_name = "None";
									Sleep(4000);
									clear_console();
									std::cout << "You are at:" << records[i].name << std::endl;
									fight_or_flee = false;
									break;
								}
								else
								{
									printf("You have been defeated and locked up, Game Over!");
									Sleep(500);
									goto game_end;
								}
							}
						}
						else if (fight == "go back")
						{
							current_location = previous_location;
							fight_or_flee = false;
							clear_console();
							goto main_loop;
						}
						else
							std::cout << "Wrong Command!" << std::endl;
					}
				}
				std::cout << "Location Description: " << records[i].description;
				printf("\n");
				printf("Locations to go: \n");
				for (int j = 0; j < records[i].directions.size(); j++)
				{
					option++;
					std::cout << option << ": " << records[i].directions[j] << std::endl;
				}
				printf("\n");
				printf("Items: \n");
				for (int j = 0; j < records[i].items.size(); j++)
				{
					option++;
					std::cout << "------------------------------------------------ " << option << " ------------------------------------------------" << std::endl;
					// If the item has already been collected
					if (records[i].items[j].item_name == "                                    [COLLECTED]")
						std::cout << "\t" << records[i].items[j].item_name << std::endl;
					else  // If the item can still be collected
					{
						print_items(i, j);
					}
				}
				// Checks if the location has any coins and adds them to your total coins 
				if (records[i].coins > 0)
				{
					std::cout << "Coins in this location: " << records[i].coins;
					gold_count += records[i].coins;
					records[i].coins = 0;
				}
				printf("\n");
				// If you have items in your inventory
				if (inventory.size() > 0)
				{
					printf("Inventory: \n");
					for (int j = 0; j < inventory.size(); j++)
						std::cout << j + 1 << ": " << inventory[j].item_name << std::endl;
					printf("\n");
				} // If inventory is empty
				else
					printf("Inventory is empty!\n");

				// Prints gold count at the end
				std::cout << "Gold Count: " << gold_count << std::endl;
				std::cout << std::endl;
				std::cout << option + 1 << " Save and Exit" << std::endl;

				// User input
user_dec:		int user_input = get_user_input(option);
				// Updates your location & inventory
				while (1)
				{
					// Works out how many items are at that location
					int item = user_input - records[i].directions.size() - 1;
					// Checks if the user is trying to access a direction or an item
					if (user_input <= option - records[i].items.size())
					{
						std::string next_location = records[i].directions[user_input - 1];
						int k;
						// Finds the index of the location you are trying to get to
						for (k = 0; k < records_size; k++)
							if (next_location == records[k].name)
								break;

						// Checks if the location has a requirement
						if (records[k].requirement == "None")
						{
							previous_location = current_location;
							prev_location(previous_location);
							current_location = records[i].directions[user_input - 1];
						}
						else
						{
							// Checks if you have the item to access it
							for (int j = 0; j < inventory.size(); j++)
								if (inventory.size() > 0 && inventory[j].item_name == records[k].requirement)
								{
									previous_location = current_location;
									prev_location(previous_location);
									current_location = records[i].directions[user_input - 1];
									goto clear_console; // Changes your location and goes to the end of the while loop
								}

							// Only triggered if the requirement is not met
							printf("Requirement not met\n");
							// Goes to the user input again
							goto user_dec;
						}
					}
					else if (user_input == option + 1)
						goto game_end;
					// if the user is trying to pickup an item
					else if (user_input >= records[i].directions.size())
						if (records[i].items[item].item_name == "                                    [COLLECTED]")
						{
							printf("Item has already been collected\n");
							Sleep(1000);
						}
						else if (records[i].items[item].item_cost > gold_count)
						{
							printf("You do not have enough gold to purcahse this item\n");
							Sleep(2000);
						}
						else if (records[i].items[item].item_cost < gold_count)
						{
							printf("Item purchased\n");
							gold_count -= records[i].items[item].item_cost;
							inventory.push_back(records[i].items[item]);
							records[i].items[item].item_name = "                                    [COLLECTED]";
						}

					goto clear_console;
				 
				}
			}
	clear_console:
		clear_console();
	}
	game_end:	
	std::ofstream save_location;
	save_location.open("saved_location.txt");
	save_location << current_location << std::endl;
	save_location.close();
}
