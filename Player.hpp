/*
 * Player.hpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>
#include <vector>

namespace app {

namespace {
	const int START_MONEY = 100;
}

class Card;

class Player {
public:

	Player(const std::string& name,
		   const int money = START_MONEY,
		   const std::vector<app::Card>& cards = std::vector<app::Card>());

	const std::string& getName() const;

	const int& getBalance() const;

	void addCards(std::vector<app::Card>& cards);

	void removeCards();

	unsigned int getCardPoints() const;

	void printCards(const bool dealer = false) const;

	void updateBalance(const int placedBet);

	const Card& getCard(const int index) const;


private:
	const std::string d_name;
	std::vector<app::Card> d_cards;
	int d_money;
};

} /* namespace app */

#endif /* PLAYER_HPP_ */
