#include <iostream>
#include <vector>
#include <Windows.h>
#include "rooms.h"
#include "player.h"

void load_game();
void print_room_info();
void user_input();
void clear_console();

// Current location definition
std::string current_location;
std::vector<std::string> inventory;
Rooms game;
Player player;

int main()
{
    SetConsoleTitleA("TextAdvent");
    load_game();
    while (1)
    {
        print_room_info();
        user_input();
    }
    std::cin.get();
}


// TO DO:
// Use items
// Coins
// Xp system
// NPC interactions // Finish it off