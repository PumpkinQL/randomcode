#include <iostream>
#include <vector>
#include "rooms.h"

void load_game();
void print_room_info();
void get_user_input();

std::string current_location;
std::vector<std::string> inventory;
Rooms game;

int main()
{
    load_game();
    while (1)
    {
        print_room_info();
        get_user_input();
    }
    //std::cin.get();
}