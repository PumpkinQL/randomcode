#pragma once
#include "rooms.h"

void game_load();
void previous_location_save();
std::vector<std::string> inventory_load();
void load_gold();
int current_location_index(std::string current_location);
void item_details(int i, int j);
void print_location_details(int i);
void print_inventory(std::vector<item> inventory);
bool enemy_npc(int i);
bool fight_or_goback();
bool fight(int i, std::vector<item> inventory);
bool check_location_requirement(int i, int user_input);
void get_user_input(int index, int i);
void clear_system();
