/*
 * Game.hpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <string>
#include <vector>
#include "Player.hpp"
#include "CardDeck.hpp"

namespace app {

namespace {
	const int NUM_CARD_DECKS = 1;
	const std::string DEALER_NAME = "Affinity";
}

class Game {
public:
	Game(const std::string& playerName,
		 const int betAmount,
		 const int numCardDecks = NUM_CARD_DECKS,
		 const std::string& dealerName = DEALER_NAME);

	void init(const std::string& playerName, const int betAmount);

	//! Checking Negative bet shouldn't be allowed. Behaviour is undefined
	bool isPlayerBalanceValid(const int betAmount);

	void reset();

	bool hitGamePlay();

	void standGamePlay();

	bool sanityChecks();

private:
	void setupGame(const std::string& playerName);

	std::vector<Player>::const_iterator getPlayer(const std::string& playerName) const;

	std::vector<Player>::iterator getPlayer(const std::string& playerName);

	void drawCard(const bool dealer);


	void printPlayerOrDealerCards(const bool dealer) const;

	bool isPlayerInTheGame() const;

	const std::string& getCurrentPlayerName() const;


	const Player& dealer() const;
	Player& dealer();

	int betAmount() const;

	//! win = true for player win or false for draw
	void giveReward(const bool win = false);

private:
	app::CardDeck d_cardDeck;
	Player d_dealer;
	std::vector<Player> d_players; //! assumes small number of players. Should be modified for large number of players
	std::string d_currentPlayerName;
	int d_betAmount;
};


} /* namespace app */

#endif /* GAME_HPP_ */
