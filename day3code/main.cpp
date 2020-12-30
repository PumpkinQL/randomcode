#include "includes.h"
#include "functions.h"

int index = 0;
int gold_count;
std::string current_location;
std::string previous_location;
std::vector<item> inventory;

int main()
{
	game_load();
	previous_location_save();
	load_gold();
	bool game = true;
	while (game)
	{
		int i = current_location_index(current_location);
		if (!enemy_npc(i))
		{
			print_location_details(i);
			print_inventory(inventory);
			get_user_input(index, i);
		}
		else
		{
			if (fight_or_goback())
				game = fight(i, inventory);
			else
				current_location = previous_location;
		}
		clear_system();
	}
	std::cout << "Game Over!" << std::endl;
	std::cin.get();
}
