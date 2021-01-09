#include <iostream>
#include <vector>
#include "rooms.h"
#include <fstream>
#include <unordered_map>

#define LOCATION game.location[current_location]

extern std::string current_location;
extern std::vector<std::string> inventory;
extern Rooms game;

void save_game()
{
    std::ofstream fs("game_info.txt");
    std::string temp;
    bool location = false;
    bool invent = false;
    while (fs.is_open())
    {
        fs << "Location Name" << std::endl;
        fs << current_location << std::endl;
        fs << "Invetory" << std::endl;
        for (size_t i = 0; i < inventory.size(); i++)
            fs << inventory[i] << std::endl;

        fs.close();
    }
}

bool changeRoom(std::string room)
{
    if (game.location.find(room) != game.location.end()) {
        if (LOCATION.directionMap.find(room) != LOCATION.directionMap.end())
        {
            current_location = room;
            return true;
        }
        else {
            std::cout << "You cannot access this room from here" << std::endl;
            return false;
        }
    }
    else {
        std::cout << room << " Does not exist" << std::endl;
        return false;
    }
}


void get_user_input()
{
    bool correct_input = true;
    while (correct_input)
    {
        std::string user_input;
        std::string temp = "";
        std::getline(std::cin, user_input);
        for (size_t i = 0; i < user_input.size(); ++i)
        {
            if (user_input[i] != ' ')
            {
                temp += user_input[i];
            }
            else if (user_input[i] == ' ')
            {
                user_input = user_input.substr(i + 1, user_input.size());
                break;
            }
        }

        if (!(temp == "go" || temp == "pickup" || temp == "use"))
        {
            std::cout << "Command does not exist, try again." << std::endl;
        }
        
        if (temp == "go")
        {
            if (changeRoom(user_input))
                correct_input = false;
        }
        else if (temp == "pickup")
        {

        }
        else if (temp == "use")
        {

        }
        else if (temp == "quit")
        {
            save_game();
            exit(0);
        }
        else {
            printf("Command does not exist\n");
        }
    }
}


void print_items()
{
    for(size_t i = 0; i < LOCATION.items.size(); ++i)
    {
        if (!LOCATION.items[i].taken) {
            std::cout << LOCATION.items[i].name << "   -   cost: ";
            std::cout << LOCATION.items[i].cost << "\n\n";
        }
    }
}



void print_weapons()
{
    for (size_t i = 0; i < LOCATION.weapons.size(); ++i) {
        if (!LOCATION.weapons[i].taken) {
            std::cout << LOCATION.weapons[i].name << "   -   cost: ";
            std::cout << LOCATION.weapons[i].cost << "\n\n";
        }
    }
}



void print_room_info()
{
    std::cout << "You are in: " << game.getName(current_location) << "\n\n";
    std::cout << game.getDescription(current_location) << "\n\n";
    if (LOCATION.items.size() > 0)
        print_items();
    if (LOCATION.weapons.size() > 0)
        print_weapons();
}



void load_game()
{
    std::ifstream fs ("game_info.txt");
    std::string temp;
    bool location = false;
    bool invent = false;
    while (std::getline(fs, temp))
    {
        if (temp == "Location Name")
        {
            location = true;
            continue;
        }
        else if (temp == "Inventory")
        {
            invent = true;
            location = false;
            continue;
        }

        if (location)
            current_location = temp;
        else if (invent)
            if (temp == "Null")
                goto close_file;
            else
            inventory.push_back(temp);
    }
    close_file: fs.close();
}