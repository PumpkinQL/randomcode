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
    else if (player.weapons.size() == 0)
        std::cout << "You do not have any items" << std::endl;

    if (player.weapons.size() > 0)
        for (size_t i = 0; i < player.weapons.size(); ++i)
            std::cout << player.weapons[i].name << std::endl;
    else std::cout << "You do not have any weapons" << std::endl;
}

void interact_with_bnpc(std::string npc_name)
{
    bool alive = true;
    while (alive)
    {
        std::cout << "You have encountered: " << LOCATION.badNpc[0].npc_name << std::endl;
        std::cout << "They seem to be agressive and want to fight, you cannot escape" << std::endl;
        std::cout << "You stare at " << LOCATION.badNpc[0].npc_name << "and see a " << LOCATION.badNpc[0].npc_description << std::endl;
        std::cout << LOCATION.badNpc[0].npc_name << " tells you" << LOCATION.badNpc[0].npc_task << std::endl;
        if (rand() % 2)
        {
            std::cout << LOCATION.badNpc[0].npc_name << " attacks you first and use a " << LOCATION.badNpc[0].weapon.name << LOCATION.badNpc[0].weapon.damage << " damage" << std::endl;
            player.hp -= LOCATION.badNpc[0].weapon.damage;
            std::cout << "Your hp is now at " << player.hp << std::endl;
            // Use weapon //   
            printf("while running away you dropped...");
        }
        else
        {
            printf("Just testing hp stuff\n");
            std::cout << "You get the upper hand and attack the enemy first, you use a ";
        }
    }
}

void interact_with_gnpc(std::string npc_name)
{
    std::cout << "You encounter with a friendly " << npc_name << std::endl;
}

void attack(std::string user_input)
{
    std::string npc;
    for (size_t i = 0; i < user_input.size(); i++)
        if (user_input[i] != ' ')
            npc += user_input[i];
        else
        {
            user_input = user_input.substr(i + 1, user_input.size());
            break;
        }

    npc[0] = toupper(npc[0]);
    for (size_t i = 1; i < npc.size(); ++i)
        npc[i] = tolower(npc[i]);

    if (npc == LOCATION.badNpc[0].npc_name)
    {
        std::string temp;
        for (size_t i = 0; i < user_input.size(); i++)
            if (user_input[i] != ' ')
                temp += user_input[i];
            else
            {
                user_input = user_input.substr(i + 1, user_input.size());
                break;
            }

        if (temp == "with")
        {
            std::string wep = user_input;
            wep[0] = toupper(wep[0]);
            for (size_t i = 1; i < wep.size(); ++i)
                wep[i] = tolower(wep[i]);
            while (1)
            {
                if (player.weaponsMap.find(wep) != player.weaponsMap.end())
                    goto fight;
                else
                {
                    std::cout << "You do not own a " << wep << std::endl;
                    goto cancel;
                }
            }
        fight:
            if (player.weapons[player.weaponsMap[wep]].range)
            {
                LOCATION.badNpc[0].npc_health -= player.weapons[player.weaponsMap[wep]].damage;
                std::cout << "You used a ranged weapon to deal some sneaky damage before the engagement" << std::endl;
            }
            std::cout << "You attack" << npc << std::endl;
            std::cout << LOCATION.badNpc[0].gender << " tells you " << LOCATION.badNpc[0].npc_task << std::endl;
            std::cout << "Enemy characteristics: " << std::endl;
            std::cout << LOCATION.badNpc[0].npc_health << std::endl;
            std::cout << LOCATION.badNpc[0].weapon.name << std::endl;
            std::cout << LOCATION.badNpc[0].weapon.damage << std::endl;
            while (1)
            {
                if (rand() % 2)
                {

                }
            }

        }
    }
    else
    {
        std::cout << "The npc " << npc << " does not exist" << std::endl;
    }
    cancel: std::cout << "Engagement cancelled!" << std::endl;
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
    std::cout << "interact " << "[NPC]" << std::endl;
    std::cout << "read " << "[Book]" << std::endl;
    std::cout << "attack" << "[NPC]" << " with " << "[Weapon]" << std::endl;
    std::cout << "Other commands: " << std::endl;
    std::cout << "inventory" << std::endl;
    std::cout << "inspect " << "[Item/Weapon]" << std::endl;
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

    std::cout << std::endl;
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

    //if (LOCATION.itemMap.find(item) != LOCATION.itemMap.end() && !LOCATION.items[LOCATION.itemMap[item]].taken) {
    if (LOCATION.itemMap.find(item) != LOCATION.itemMap.end()) {
        if (!LOCATION.items[LOCATION.itemMap[item]].taken) {
            player.addItem(LOCATION.items[LOCATION.itemMap[item]]);
            game.setTakenItem(item);
            return true;
        }
        else {
            std::cout << std::endl << "You took the " << item << std::endl;
        }
    }
    //else if (LOCATION.weaponMap.find(item) != LOCATION.weaponMap.end() && !LOCATION.weapons[LOCATION.weaponMap[item]].taken) {
    else if (LOCATION.weaponMap.find(item) != LOCATION.weaponMap.end()) {
        if (!LOCATION.weapons[LOCATION.weaponMap[item]].taken) {
            player.addWeapon(LOCATION.weapons[LOCATION.weaponMap[item]]);
            game.setTakenWeapon(item);
            return true;
        }
        else {
            std::cout << std::endl << "You took the " << item << std::endl;
        }
    }
    else {
        std::cout << std::endl << "There is no " << item << std::endl;
        return false;
    }
}

void print_item_info(std::string item)
{
    item[0] = toupper(item[0]);
    for (size_t i = 1; i < item.size(); ++i)
        item[i] = tolower(item[i]);

    if (LOCATION.itemMap.find(item) != LOCATION.itemMap.end())
    {
        std::cout << std::endl << "Item name - " << LOCATION.items[LOCATION.itemMap[item]].name << std::endl;
        std::cout << "Item cost - " << LOCATION.items[LOCATION.itemMap[item]].cost << std::endl;
        std::cout << "Item description - " << LOCATION.items[LOCATION.itemMap[item]].item_description << std::endl;
    }
    else if (LOCATION.weaponMap.find(item) != LOCATION.weaponMap.end()) 
    {
        std::cout << std::endl << "Item name - " << LOCATION.weapons[LOCATION.weaponMap[item]].name << std::endl;
        std::cout << "Item cost - " << LOCATION.weapons[LOCATION.weaponMap[item]].cost << std::endl;
        std::cout << "Item description - " << LOCATION.weapons[LOCATION.weaponMap[item]].item_description << std::endl;
    }
    else if (player.itemsMap.find(item) != player.itemsMap.end())
    {
        std::cout << std::endl << "Item name - " << player.items[player.itemsMap[item]].name << std::endl;
        std::cout << "Item cost - " << player.items[player.itemsMap[item]].cost << std::endl;
        std::cout << "Item description - " << player.items[player.itemsMap[item]].item_description << std::endl;
    }
    else if (player.weaponsMap.find(item) != player.weaponsMap.end())
    {
        std::cout << std::endl << "Item name - " << player.weapons[player.weaponsMap[item]].name << std::endl;
        std::cout << "Item cost - " << player.weapons[player.weaponsMap[item]].cost << std::endl;
        std::cout << "Item description - " << player.weapons[player.weaponsMap[item]].item_description << std::endl;
    }
    else {
        std::cout << std::endl << "What " << item << "?" << std::endl;
    }
}

void print_items()
{
    for(size_t i = 0; i < LOCATION.items.size(); ++i)
        if (!LOCATION.items[i].taken)
            std::cout << LOCATION.items[i].name << std::endl;
}

void print_weapons()
{
    for (size_t i = 0; i < LOCATION.weapons.size(); ++i)
        if (!LOCATION.weapons[i].taken)
            std::cout << LOCATION.weapons[i].name << std::endl;
}

void print_room_info()
{
    std::cout << "You are in: " << game.getName(current_location) << std::endl;
    std::cout << game.getDescription(current_location) << std::endl;
    if (LOCATION.badNpc.size() > 0)
    {
        std::cout << "You see an evil face of " << LOCATION.badNpc[0].npc_name << std::endl;
    }
    else if (LOCATION.goodNpc.size() > 0)
    {
        std::cout << "You see a friendly villager, his name is " << LOCATION.goodNpc[0].npc_name << std::endl;
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
    bool invent = false;
    while (std::getline(fs, temp))
    {
        if (temp == "Inventory")
        {
            invent = true;
            continue;
        }

        if (!invent)
            current_location = temp;
        else if (invent)
            if (temp == "Null")
                goto close_file;
            else
            inventory.push_back(temp);
    }
    close_file: fs.close();
}


int kitchenFunc() {
    
   /* if (LOCATION.time == 3) {
        std::cout << std::endl << "The mother is angry" << std::endl;
    }*/

    return true;
}