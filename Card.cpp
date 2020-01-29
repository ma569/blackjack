/*
 * Card.cpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#include "Card.hpp"

namespace app {

namespace {
	const std::string ACE   = "Ace";
	const std::string KING  = "King";
	const std::string QUEEN = "Queen";
	const std::string JACK  = "Jack";
}

Card::Card(const std::string& suit, const unsigned int card) :
	d_suit(suit),
	d_card(card)
{
}

const std::string& Card::getSuit() const {
	return d_suit;
}

const std::string Card::getCard() const {
	if(1 == d_card) {
		return ACE;
	}
	else if (11 == d_card) {
		return JACK;
	}
	else if (12 == d_card) {
		return QUEEN;
	}
	else if (13 == d_card) {
		return KING;
	}

	return std::to_string(d_card);
}

std::ostream& operator<<(std::ostream &os, const Card &c) {
	os << c.getCard() << " of " << c.getSuit();
	return os;
}

} /* namespace app */
