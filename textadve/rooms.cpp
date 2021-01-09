#include <iostream>
#include <vector>
#include "rooms.h"
#include <unordered_map>

//Name
//Description
//Directions <vector>
//Items					Item Name, Items Cost 
//Weapons               Name, HP, Damage, Cost, Bool Range, Bool cost
//NPC					Bool exist, name,  Bool good
//Requirements

//Kitchen
//Bedroom
//Living Room
//Garden

Rooms::Locations locations[4] =
{
	{
		/* Name */ "Kitchen",
		/* Description */ "The main functions of a kitchen are to store, prepare and cook food.",
		/* Directions */ {"Living Room"},
		{
			{
				/* Name */ "Newspaper",
				/* Item Cost */ 0,
			},
			{
				/* Name */ "Grapes",
				/* Item Cost */ 5,
			},
		},
		{
			{
				/* Name */ "Knife",
				/* HP */ 5,
				/* Damage */ 10,
				/* Cost */ 25,
				/* Range */ false,
			}
		},
		{
			{
				/* NPC */ false,
			},
		},
		"None",

	},
	{
		"Living Room",
		"",
		{"Bedroom", "Garden"}
	},
	{
		"Bedroom",
		"",
		{"Living Room"},
	},
	{
		"Garden",
		"",
		{"Kitchen", "Bedroom"}
	}
};



Rooms::Rooms()
{
	location.insert(
		{
		"Kitchen"
		},


		{
			/* Name       */ "Kitchen",
			/* Descriptio */ "The main functions of a kitchen are to store, prepare and cook food.",
			/* Directions */ {"Living Room"},

			// ITEMS
			{
				{
					/* Name      */ "Newspaper",
					/* Item Cost */ 0,
				},
				{
					/* Name      */ "Grapes",
					/* Item Cost */ 5,
				},
			},

			// WEAPONS
				{
					{
						/* Name   */ "Knife",
						/* HP     */ 5,
						/* Damage */ 10,
						/* Cost * */ 25,
						/* Range  */ false,
					}
				},
				{
					{
						/* NPC */ false,
					},
				},

				// requirements
				"None",
		});


	location["Living Room"] =
	{
		/* Name       */ "Living Room",
		/* Descriptio */ "The main functions of a kitchen are to store, prepare and cook food.",
		/* Directions */ {"Kitchen"},

		// ITEMS
		{
			{
				/* Name      */ "Remove Control",
				/* Item Cost */ 0,
			},
			{
				/* Name      */ "Chocolate Bar",
				/* Item Cost */ 5,
			},
		},

		// WEAPONS
			{
				{
					/* Name   */ "Knife",
					/* HP     */ 5,
					/* Damage */ 10,
					/* Cost * */ 25,
					/* Range  */ false,
				}
			},
			{
				{
					/* NPC */ false,
				},
			},

			// requirements
			"None",
	},

}


