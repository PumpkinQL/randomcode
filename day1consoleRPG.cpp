#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>

struct locations
{
	std::string name;
	std::string description;
	std::string requirement;
	std::vector<std::string> items;
	std::vector<std::string> directions;
};

int main()
{
	SetConsoleTitleA("Text Game");
	locations records[3] =
	{
		{ "Kitchen", "Large Cooking Space", "None", { "Knife", "Pan" }, { "Living Room", "Bedroom" }},
		{ "Living Room", "Living Space", "Knife", { "TV", "Magazine" }, { "Bedroom" }},
		{ "Bedroom", "Place For Sleeping", "None", { "Bed", "Lamp" }, { "Living Room" }}
	};
	std::string starting_location{ "Kitchen" };
	std::vector<std::string> inventory;
	while (1)
	{
		//find current_location
		int option = 0;
		for(int i = 0; i < *(&records + 1) - records; i++)
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
					std::cout << option << ": " << records[i].items[j] << std::endl;
				}
				printf("\n");
				if (inventory.size() > 0)
				{
					printf("Inventory: \n");
					for (int j = 0; j < inventory.size(); j++)
						std::cout << j + 1 << ": " << inventory[j] << std::endl;
					printf("\n");
				}
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
						for (k = 0; k < *(&records + 1) - records; k++)
							if (temp_cl == records[k].name)
								break;

						if (records[k].requirement == "None")
						{
							starting_location = records[i].directions[user_input - 1];
						}
						else
						{
							for (int j = 0; j <= inventory.size(); j++)
								if (inventory.size() > 0 && inventory[j] == records[k].requirement)
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
						if (records[i].items[item] == "--COLLECTED--")
							std::cout << "Item has already been collected" << std::endl;
						else
						{
							inventory.push_back(records[i].items[item]);
							records[i].items[item] = "--COLLECTED--";
						}
					goto sleep;
				}
			}
	sleep:
	if(system("CLS"))
		system("clear");
	}
}
