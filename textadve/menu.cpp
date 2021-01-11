#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "commands.h"

extern std::string current_location;
extern std::vector<std::string> inventory;

Command_list command_list;

void print_inventory();
void show_map();
void print_commands();
void save_game();
void print_commands();
void interact_with_npc(std::string npc_name);
bool changeRoom(std::string room);
bool pickup(std::string item);

void user_input()
{
    bool correct_input = true;
    while (correct_input)
    {
        std::string user_input;
        std::string temp = "";
        std::cout << std::endl << "> ";
        std::getline(std::cin, user_input);
        std::cout << std::endl;
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

       /* if (temp == user_input) {
            std::cout << "Invalid instruction" << std::endl;
            break;
        }*/

        if (command_list.commands.find(temp) != command_list.commands.end())
        {
            switch (command_list.commands[temp])
            {
            case 0: // go
                if (temp == user_input) {
                    std::cout << "You can't go to nowhere" << std::endl;
                    break;
                }
                if (changeRoom(user_input))
                    correct_input = false;
                break;
            case 1:
                print_commands();
                break;
            case 2:
                save_game();
                exit(0);
            case 3:
                if (temp == user_input) {
                    std::cout << "You can't pick up nothing" << std::endl;
                    break;
                }
                // Pickup something
                if (pickup(user_input))
                break;
            case 4:
                // Use item
                if (temp == user_input)
                {
                    std::cout << "You need to select an item to use!" << std::endl;
                    break;
				}
                break;
            case 5:
                // Credits
                std::cout << "not created yet" << std::endl;
                break;
            case 6:
                // Shows inventory
                print_inventory();
                break;
            case 7:
                // Shows a map
                std::cout << "heres a map jk" << std::endl;
                break;
            case 8:
                interact_with_npc(user_input);
                break;
            }

        }
        else {
            printf("Command does not exist\n");
        }
        
    }
}