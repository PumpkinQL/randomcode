#include <math.h>
#include <ctime>
#include <windows.h>
#include <algorithm>
#include <random>
#include <chrono>

std::vector<int> player1;
std::vector<int> player2;

bool check_cards(int card_one, int card_two)
{

	std::string cardone;
	std::string cardtwo;

	//Red
	if (card_one < 11)
		cardone = "red";
	//Yellow
	else if (card_one < 21)
		cardone = "yellow";
	else
		cardone = "black";

	if (card_two < 11)
		cardtwo = "red";
	else if (card_two < 21)
		cardtwo = "yellow";
	else
		cardtwo = "black";

	if (cardone != cardtwo)
		if (cardone == "red" && cardtwo == "black")
		{
			player1.push_back(card_one);
			player1.push_back(card_two);
			printf("Player 1 wins the round\n");
			return true;
		}
		else if (cardone == "yellow" && cardtwo == "red")
		{
			player1.push_back(card_one);
			player1.push_back(card_two);
			printf("Player 1 wins the round\n");
			return true;
		}
		else if (cardone == "black" && cardtwo == "yellow")
		{
			player1.push_back(card_one);
			player1.push_back(card_two);
			printf("Player 1 wins the round\n");
			return true;
		}
		else
		{
			player2.push_back(card_one);
			player2.push_back(card_two);
			printf("Player 2 wins the round\n");
			return false;
		}
	else
		if (card_one > card_two)
		{
			player1.push_back(card_one);
			player1.push_back(card_two);
			printf("Player 1 wins the round\n");
			return true;
		}
		else
		{
			player2.push_back(card_one);
			player2.push_back(card_two);
			printf("Player 2 wins the round\n");
			return false;
		}
}

int main()
{
	std::vector<int> main_deck;
	main_deck = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
	while (1)
	{
		main_deck = { 1, 2, 3, 4, 5, 6 , 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
		player1erase(player1begin(), player1end());
		player2erase(player2begin(), player2end());
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle(main_deck.begin(), main_deck.end(), std::default_random_engine(seed));
		while (main_deck.size() > 1)
		{
			check_cards(main_deck[0], main_deck[1]);
			main_deck.erase(main_deck.begin(), main_deck.begin() + 2);
		}
		printf("Deck is out\n");
		if (player1.size() < player2.size())
		{
			printf("Player 2 wins!\n");
			for (size_t i = 0; i < player2.size(); i++)
				std::cout << player2[i] << " ";
		}
		else
		{
			printf("Player 1 wins!\n");
			for (size_t i = 0; i < player1.size(); i++)
				std::cout << player1.[i] << " ";
		}
		std::cin.get();
		srand(time(0));
		if (system("CLS"))
			system("clear");
	}
}
