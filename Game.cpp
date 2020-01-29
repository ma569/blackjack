/*
 * Game.cpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#include "Game.hpp"

#include <iostream>
#include <algorithm>
#include <limits>

#include "CardDeck.hpp"
#include "Player.hpp"
#include "Card.hpp"

namespace app {

namespace {
	const int LIMIT_SCORE = 21;
	const int NUM_CARDS_TO_DEAL = 2;
	const int INVALID_AMOUNT = -1;
	const int WIN_RATIO = 2;
	const int DEALER_SCORE = 17;

	void printGameOver() {
		std::cout << "You went bust "<< '\n';
	}

	void printPlayerBalance(const int balance) {
		std::cout << "Your balance = "<< balance << '\n';
	}

	void printHitStand() {
		std::cout << "\n\n Hit (h) or stand (s) \n\n";
	}

	void welcomeMessage() {
		std::cout << "\n\n ======================= \n\n";
		std::cout << "Welcome to Blackjack.\nThe house will pay you $2 for every $1 you bet\n";
		std::cout << "To play type 'y': ";
		std::cout << "\n\n ======================= \n\n";
	}
}

Game::Game(const std::string& playerName,
		   const int betAmount,
		   const int numCardDecks,
		   const std::string& dealerName) : d_cardDeck(numCardDecks),
											d_dealer(dealerName, std::numeric_limits<int>::max()),
											d_currentPlayerName(playerName),
											d_betAmount(INVALID_AMOUNT) {
	init(playerName, betAmount);
}


void Game::init(const std::string& playerName, const int betAmount) {
	d_betAmount = betAmount;
	d_cardDeck.shuffleDeck();

	d_currentPlayerName = playerName;

	auto playerIter = getPlayer(playerName);

	//! player doesn't exist, add it
	if(playerIter == d_players.end()) {
		Player p = Player(playerName);
		d_players.emplace_back(p);
	}
}

void Game::setupGame(const std::string& playerName) {
	drawCard(false);
	drawCard(false);

	auto playerIter = getPlayer(playerName);
	if(playerIter != d_players.end()) {
		playerIter->printCards();
	}

	drawCard(true);
	drawCard(true);
	std::cout << "One of the cards Dealer has is " << d_dealer.getCard(0) << '\n';
}

std::vector<Player>::const_iterator Game::getPlayer(const std::string& playerName) const {
	auto it = find_if(d_players.begin(),
					  d_players.end(), [&playerName](const Player& player) {
				return player.getName() == playerName;
			  });
	return it;
}

std::vector<Player>::iterator Game::getPlayer(const std::string& playerName) {
	auto it = find_if(d_players.begin(),
					  d_players.end(), [&playerName](const Player& player) {
			return player.getName() == playerName;
		});
	return it;
}

bool Game::isPlayerBalanceValid(const int betAmount) {
	bool flag = true;
	auto playerIter = getPlayer(d_currentPlayerName);
	if(playerIter != d_players.end()) {
		if(betAmount > playerIter->getBalance()) {
			flag = false;
		}
		else {
			playerIter -> updateBalance(betAmount);
		}
	}

	return flag;
}

void Game::drawCard(const bool dealer) {
	if(d_cardDeck.numCardsInDeck() != 0) {
		std::vector<app::Card> card = d_cardDeck.drawCard();
		if(dealer) {
			d_dealer.addCards(card);
		}
		else {
			getPlayer(d_currentPlayerName) -> addCards(card);
		}
	}
	else {
		d_cardDeck = CardDeck();
	}

}

void Game::printPlayerOrDealerCards(const bool dealer) const {
	if(!dealer) {
		auto playerIter = getPlayer(getCurrentPlayerName());
		playerIter->printCards();
	}
	else {
		d_dealer.printCards(true);
	}

}

bool Game::isPlayerInTheGame() const {
	return getPlayer(getCurrentPlayerName())->getCardPoints() <= LIMIT_SCORE;
}

const std::string& Game::getCurrentPlayerName() const {
	return d_currentPlayerName;
}

void Game::reset() {
	d_dealer.removeCards();
	for(auto& p: d_players) {
		p.removeCards();
	}

	d_currentPlayerName = "";
	d_betAmount = INVALID_AMOUNT;
}

const Player& Game::dealer() const {
	return d_dealer;
}

Player& Game::dealer() {
	return d_dealer;
}

int Game::betAmount() const {
	return d_betAmount;
}

void Game::giveReward(const bool win) {
	if(win) {
		//! 1.5 times  the winning
		getPlayer(getCurrentPlayerName()) -> updateBalance(-WIN_RATIO * betAmount());
	}
	else {
		getPlayer(getCurrentPlayerName()) -> updateBalance(-betAmount());
	}

}

bool Game::hitGamePlay() {
	bool gameInPlay = true;
	drawCard(false);
	printPlayerOrDealerCards(false);

	if(!isPlayerInTheGame()) {
		printGameOver();
		printPlayerBalance(getPlayer(getCurrentPlayerName()) -> getBalance());
		gameInPlay = false;
		reset();
		welcomeMessage();
	}
	else {
		printHitStand();
	}

	return gameInPlay;
}

void Game::standGamePlay() {
	const int playerScore = getPlayer(getCurrentPlayerName()) -> getCardPoints();
	while(dealer().getCardPoints() < DEALER_SCORE) {
		drawCard(true);
	}

	printPlayerOrDealerCards(true);

	const int dealerScore = dealer().getCardPoints();
	if(dealerScore > LIMIT_SCORE || dealerScore < playerScore) {
		std::cout << "YOU WIN\n";
		giveReward(true);
	}
	else if(dealerScore > playerScore) {
		std::cout << "DEALER WIN\n";
	}
	else if(dealerScore == playerScore) {
		std::cout << "GAME DRAWN\n";
		giveReward();
	}

	printPlayerBalance(getPlayer(getCurrentPlayerName())->getBalance());
	reset();
	welcomeMessage();
}

bool Game::sanityChecks() {
	bool checksPassed = true;
	if(betAmount() >= 1 && isPlayerBalanceValid(betAmount())) {

		setupGame(getCurrentPlayerName());
		printHitStand();
	}
	else {
		checksPassed = false;
		std::cout << "Please check your bet amount" << std::endl;
		welcomeMessage();
		reset();
	}

	return checksPassed;
}

} /* namespace app */
