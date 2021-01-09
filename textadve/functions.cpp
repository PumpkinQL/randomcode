#include <iostream>
#include <vector>
#include "rooms.h"
#include <fstream>

extern Rooms::Locations locations[4];
extern std::string current_location;
extern std::vector<std::string> inventory;

int find_location_index()
{
    for (int i = 0; i < sizeof(locations); i++)
        if (locations[i].name == current_location)
            return i;
}

void load_game()
{
    std::ifstream fs ("game_info.txt");
    std::string temp;
    bool location = false;
    bool invent = false;
    while (std::getline(fs, temp))
    {
        if (temp == "Location Name:")
        {
            location = true;
            continue;
        }
        else if (temp == "Invenotory:")
        {
            invent = true;
            location = false;
            continue;
        }

        if (location)
            current_location = temp;
        else if (invent)
            inventory.push_back(temp);
    }
    fs.close();
}

void save_game()
{
    std::ifstream fs("game_info.txt");
    std::string temp;
    bool location = false;
    bool invent = false;
    while (std::getline(fs, temp))
    {
        if (temp == "Location Name:")
        {
            location = true;
            continue;
        }
        else if (temp == "Invenotory:")
        {
            invent = true;
            location = false;
            continue;
        }

        if (location)
            fs = temp;
        else if (invent)
            fs = temp;
    }
    fs.close();
}