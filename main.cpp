#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include <memory>

#include "Card.hpp"
#include "CardDeck.hpp"
#include "Game.hpp"

namespace {

const int LIMIT_SCORE = 21;
const int DEALER_SCORE = 17;

void welcomeMessage() {
	std::cout << "\n\n ======================= \n\n";
	std::cout << "Welcome to Blackjack.\nThe house will pay you $2 for every $1 you bet\n";
	std::cout << "To play type 'y': ";
	std::cout << "\n\n ======================= \n\n";
}

void printInstructions() {
	std::cout << "Let's Play...\n\n";
	std::cout << "To hit, press 'h'...\n";
	std::cout << "To stand, press 's'...\n";
	std::cout << "To split, press 'p'...\n";
	std::cout << "To double your bet, press 'd'...\n";
	std::cout << "To restart the game, press 'R'...\n";

	std::cout << "\n\n";
	std::cout << "Enter your name: ";
}


int gameInitHelper(std::string& playerName) {
	printInstructions();
	std::getline(std::cin, playerName);

	// No checks on the user amount
	std::cout << "How much do you want to bet? ";

	std::string betAmount;
	std::getline(std::cin, betAmount);
	return std::atoi(betAmount.c_str());
}

}


int main() {

	std::unique_ptr<app::Game> game = nullptr;
	bool gameStarted = false;

	welcomeMessage();

	std::string userInput;

	while(std::getline(std::cin, userInput)) {

		if(!gameStarted && "y" == userInput) {
			std::string playerName;
			const int betAmount = gameInitHelper(playerName);
			if(nullptr == game) {
				game = std::make_unique<app::Game>(app::Game(playerName, betAmount));
			}
			else {
				game -> init(playerName, betAmount);
			}

			gameStarted = game -> sanityChecks();

		}
		else if("R" == userInput) {
			std::cout << "Game ended \n";
			gameStarted = false;
			welcomeMessage();
		}
		else if(gameStarted && "h" == userInput) {
			//! you can hit only if game has started
			gameStarted = game->hitGamePlay();
		}
		else if(gameStarted &&  "s" == userInput) {
			game->standGamePlay();
			gameStarted = false;
		}
		else if(gameStarted &&  "p" == userInput) {
			std::cout << "NOT IMPLEMENTED\n";
		}
		else if(gameStarted &&  "d" == userInput) {
			std::cout << "NOT IMPLEMENTED\n";
		}
		else {
			std::cout << "Incorrect input\n";
		}
	}

}
