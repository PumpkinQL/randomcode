#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include "rooms.h"

int main()
{
	std::string starting_location{ "Kitchen" };
	std::vector<item> inventory;
	int gold_count = 20;
	while (1)
	{
		//find current_location
		int option = 0;
		for(int i = 0; i < sizeof(records); i++)
			if (starting_location == records[i].name)
			{
				std::cout << "You are at: " << records[i].name << std::endl;
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
					std::cout << option << std::endl;
					if (records[i].items[j].item_name != "[COLLECTED]")
					{
						std::cout << " - " << records[i].items[j].item_name << std::endl;
						std::cout << " - " << records[i].items[j].item_description << std::endl;
						std::cout << " - " << records[i].items[j].item_attack_power << std::endl;
						std::cout << " - " << records[i].items[j].item_cost << std::endl;
					}
					else
						std::cout << "\t" << records[i].items[j].item_name << std::endl;
				}
				printf("\n");
				if (inventory.size() > 0)
				{
					printf("Inventory: \n");
					for (int j = 0; j < inventory.size(); j++)
						std::cout << j + 1 << ": " << inventory[j].item_name << std::endl;
					printf("\n");
				}
				else
					printf("Inventory is empty!\n");

				std::cout << "Gold Count: " << gold_count << std::endl;

				//user input
				char temp;
				int  user_input;
             	bool user_dec = true;
user_dec:       while (user_dec)
				{
					std::cin >> temp;
					if (temp >= '0' && temp <= '9')
					{
						if (temp - 48 <= option && temp - 48 != 0)
						{
							user_input = temp - 48;
							user_dec = false;
						}
					}
					else 
						std::cout << "Option does not exist >:" << std::endl;
				}
				while (1)
				{
					int item = user_input - records[i].directions.size() - 1;
					if (user_input <= option - records[i].items.size())
					{
						std::string temp_cl = records[i].directions[user_input - 1];
						int k;
						for (k = 0; k < sizeof(records); k++)
							if (temp_cl == records[k].name)
								break;

						if (records[k].requirement == "None")
						{
							starting_location = records[i].directions[user_input - 1];
						}
						else
						{
							for (int j = 0; j <= inventory.size(); j++)
								if (inventory.size() > 0 && inventory[j].item_name == records[k].requirement)
								{
									starting_location = records[i].directions[user_input - 1];
									goto sleep;
								}

									printf("Requirement not met\n");
									user_dec = true;
									goto user_dec;
						}
					}
					else if (user_input >= records[i].directions.size())
						if (records[i].items[item].item_name == "[COLLECTED]")
						{
							std::cout << "Item has already been collected" << std::endl;
							Sleep(1000);
						}
						else if (records[i].items[item].item_cost > gold_count)
						{
							printf("You do not have enough gold to purcahse thia item\n");
							Sleep(2000);
						}
						else if (records[i].items[item].item_cost < gold_count)
						{
							printf("Item purchased\n");
							gold_count -= records[i].items[item].item_cost;
							inventory.push_back(records[i].items[item]);
							records[i].items[item].item_name = "[COLLECTED]";
						}
					goto sleep;
				}
			}
	sleep:
	if(system("CLS"))
		system("clear");
	}
}
