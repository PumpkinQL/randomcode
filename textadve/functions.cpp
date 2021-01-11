#include <iostream>
#include <vector>
#include "rooms.h"
#include "player.h"
#include <fstream>
#include <unordered_map>
#include <cctype>

#define LOCATION game.location[current_location]

extern std::string current_location;
extern std::vector<std::string> inventory;
extern Rooms game;
extern Player player;

void user_input();

void print_inventory()
{
    if (player.items.size() > 0)
        for (size_t i = 0; i < player.items.size(); ++i)
            std::cout << player.items[i].name << std::endl;
    else std::cout << "You do not have any items" << std::endl;

    if (player.weapons.size() > 0)
        for (size_t i = 0; i < player.weapons.size(); ++i)
            std::cout << player.weapons[i].name << std::endl;
    else std::cout << "You do not have any weapons" << std::endl;
}

void interact_with_npc(std::string npc_name)
{
    std::cout << "You engaged with " << LOCATION.npc[0].name << std::endl;
    if (LOCATION.npc[0].good)
    {
        printf("Good NPC\n");
	}
    else
    {
        printf("Bad NPC\n");
	}
}

void show_map()
{
    std::cout << "Work in progress" << std::endl;
}

void print_commands()
{
    std::cout << "Full list of commands: " << std::endl << std::endl;
    std::cout << "Action commands: " << std::endl;
    std::cout << "go " << "[Location]" << std::endl;
    std::cout << "pickup " << "[Item/Weapon]" << std::endl;
    std::cout << "use " << "[Item/Weapon]" << std::endl << std::endl;
    std::cout << "look" << "[NPC]" << std::endl;
    std::cout << "Other commands: " << std::endl;
    std::cout << "inventory" << std::endl;
    std::cout << "map" << std::endl;
    std::cout << "commands" << std::endl;
    std::cout << "quit" << std::endl;
}

void clear_console()
{
    if (system("CLS"))
        system("clear");
}

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
        fs << "Inventory" << std::endl;
        for (size_t i = 0; i < inventory.size(); i++)
            fs << inventory[i] << std::endl;

        fs.close();
        printf("Saved correctly\n");
    }
}

bool use()
{
    return false;
}

// Updates room info
bool changeRoom(std::string room)
{
    // Change input to correct type
    room[0] = toupper(room[0]);
    for (size_t i = 1; i < room.size(); ++i)
        room[i] = tolower(room[i]);
    //
    if (game.location.find(room) != game.location.end()) {
        if (LOCATION.directionMap.find(room) != LOCATION.directionMap.end())
        {
            current_location = room;
            clear_console();
            //print_room_info();
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


// Pickup items
bool pickup(std::string item) {
    // change input to all lowercase
    item[0] = toupper(item[0]);
    for (size_t i = 1; i < item.size(); ++i)
        item[i] = tolower(item[i]);

    if (LOCATION.itemMap.find(item) != LOCATION.itemMap.end() && !LOCATION.items[LOCATION.itemMap[item]].taken) {
            player.addItem(LOCATION.items[LOCATION.itemMap[item]]);
            game.setTakenItem(item);
            return true;
    }
    else if (LOCATION.weaponMap.find(item) != LOCATION.weaponMap.end() && !LOCATION.weapons[LOCATION.weaponMap[item]].taken) {
            player.addWeapon(LOCATION.weapons[LOCATION.weaponMap[item]]);
            game.setTakenWeapon(item);
            return true;
    }
    else {
        std::cout << "There is no " << item << std::endl;
        return false;
    }
}

void print_items()
{
    for(size_t i = 0; i < LOCATION.items.size(); ++i)
    {
        if (!LOCATION.items[i].taken) {
            std::cout << LOCATION.items[i].name << " - cost: ";
            std::cout << LOCATION.items[i].cost << std::endl;
        }
    }
}

void print_weapons()
{
    for (size_t i = 0; i < LOCATION.weapons.size(); ++i) {
        if (!LOCATION.weapons[i].taken) {
            std::cout << LOCATION.weapons[i].name << " - cost: ";
            std::cout << LOCATION.weapons[i].cost << std::endl;
        }
    }
}

void print_room_info()
{
    std::cout << "You are in: " << game.getName(current_location) << std::endl;
    std::cout << game.getDescription(current_location) << std::endl;
    if (LOCATION.npc.size() > 0)
    {
        std::cout << "There is a " << LOCATION.npc[0].name << ", he appears to be ";
        if (LOCATION.npc[0].good)
            std::cout << "good" << std::endl;
        else
            std::cout << "evil" << std::endl;
    }
    if (LOCATION.items.size() > 0)
        print_items();
    if (LOCATION.weapons.size() > 0)
        print_weapons();
}

// Loads last game save.
void load_game()
{
    std::ifstream fs ("game_info.txt");
    std::string temp;
    bool location = true;
    bool invent = false;
    while (std::getline(fs, temp))
    {
        if (temp == "Inventory")
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
