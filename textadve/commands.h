#pragma once
#include <iostream>
#include <unordered_map>

class Command_list
{
public:
	
	std::unordered_map<std::string, int> commands =
	{
		{"go", 0},
		{"commands", 1},
		{"quit", 2},
		{"pickup", 3},
		{"use", 4},
		{"credits", 5},
		{"inventory", 6},
		{"map", 7},
		{"interact", 8},
		{"inspect", 9},
		{"attack", 10},
		{"read", 11},
	};
};