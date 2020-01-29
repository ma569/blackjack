/*
 * CardDeck.hpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#ifndef CARDDECK_HPP_
#define CARDDECK_HPP_

#include <vector>
#include <deque>

namespace app {

class Card;

class CardDeck {
private:


public:
	CardDeck(const int numCardDecks = 1);

	void shuffleDeck();

	std::vector<Card> drawCard(const int numCardsToDeal = 1);

	int numCardsInDeck() const;

private:
	std::deque<Card> d_cards;
};

} /* namespace app */

#endif /* CARDDECK_HPP_ */
