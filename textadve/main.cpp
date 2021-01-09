#include <iostream>
#include <vector>

int find_location_index();
void load_game();

int main()
{
    std::string current_location = "hello";
    extern std::vector<std::string> inventory;
    load_game();
    int i = find_location_index();
    std::cin.get();
}