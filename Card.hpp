#include <string>
#include <iostream>

/*
 * Card.hpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#ifndef CARD_HPP_
#define CARD_HPP_

namespace app {

class Card {

public:
	Card(const std::string& suit, const unsigned int card);

	friend std::ostream &operator<<(std::ostream &os, const Card &c);

	const std::string getCard() const;

private:
	const std::string& getSuit() const;

private:
	std::string d_suit;
	unsigned int d_card;
};

} /* namespace app */

#endif /* CARD_HPP_ */
