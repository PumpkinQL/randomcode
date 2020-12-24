#pragma once
#include <iostream>
#include <vector>

struct item
{
	std::string item_name;
	std::string item_description;
	int item_attack_power;
	int item_cost;
};

struct locations
{
	std::string name;
	std::string description;
	std::string requirement;
	std::vector<std::string> directions;
	std::vector<item> items;
};

locations records[4] =
{
	{
		"Kitchen",
		"A room or area where food is prepared and cooked.",
		"None",
		{
		   "Bedroom",
		   "Bathroom"
		},
		{
			{
				"Pan",
				"A metal container used for cooking food in.",
				4,
				21,
			},
			{
				"Knife",
				"An instrument composed of a blade fixed into a handle, used for cutting or as a weapon",
				6,
				0,
			}
		}
	},
	{
		"Master Bedroom",
		"The main room for sleeping in",
		"None",
		{
		   "Kitchen",
		},
		{
			{
				"T-Shirt",
				"A short-sleeved casual top, generally made of cotton, having the shape of a T when spread out flat",
				0,
				10,
			},
			{
				"Phone",
				"A telephone",
				0,
				100,
			}
		}
	},
	{
		"Bedroom",
		"A room for sleeping in",
		"Key",
		{
		   "Bathroom",
		   "Master Bedroom",
		},
		{
			{
				"Suite",
				"A set of outer clothes made of the same fabric and designed to be worn together, typically consisting of a jacket and trousers or a jacket and skirt",
				0,
				5,
			}
		}
	},
	{
		"Bathroom",
		"A room containing a bath or shower and typically also a washbasin and a toilet.",
		"None",
		{
			"Master Bedroom",
			"Kitchen",
		},
		{
			{
				"Tooth Paste",
				"A thick, soft, moist substance used on a brush for cleaning one's teeth.",
				0,
				0,
			},
			{
				"Tooth Brush",
				"A small brush with a long handle, used for cleaning the teeth.",
				3,
				5,
			},
		}
	}
};
