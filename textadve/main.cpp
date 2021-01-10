#include <iostream>
#include <vector>
#include <Windows.h>
#include "rooms.h"

void load_game();
void print_room_info();
void get_user_input();
void clear_console();

std::string current_location;
std::vector<std::string> inventory;
Rooms game;

int main()
{
    SetConsoleTitleA("Hello");
    load_game();
    while (1)
    {
        print_room_info();
        get_user_input();
        clear_console();
    }
    //std::cin.get();
}

// TO DO:
// Pickup items/weapons
// Use items
// Coins
// Xp system