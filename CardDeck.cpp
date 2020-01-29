/*
 * CardDeck.cpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#include "CardDeck.hpp"

#include <algorithm>
#include <random>

#include "Card.hpp"



namespace app {

namespace {
	const std::string SUIT_CLUBS    = "CLUBS";
	const std::string SUIT_HEARTS   = "HEARTS";
	const std::string SUIT_DIAMONDS = "DIAMONDS";
	const std::string SUIT_SPADES   = "SPADES";

	const int NUM_CARDS_PER_SUIT = 13;
	const int NUM_CARDS_TO_DEAL = 2;

	const std::vector<std::string > SUITS = {SUIT_CLUBS,
			                                 SUIT_SPADES,
											 SUIT_HEARTS,
											 SUIT_DIAMONDS};
}

CardDeck::CardDeck(const int numCardDecks) {
	// num decks
	for (int d = 0; d < numCardDecks; ++d) {
		// num suits
		for(auto const& s: SUITS) {
			for (int c = 0; c < NUM_CARDS_PER_SUIT; ++c) {
				d_cards.emplace_back(Card(s, c+1));
			}
		}
	}
}

void CardDeck::shuffleDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(d_cards.begin(), d_cards.end(), g);
}

std::vector<Card> CardDeck::drawCard(const int numCardsToDeal) {
	std::vector<Card> drawCards;
	for (int i = 0; i != numCardsToDeal; ++i) {
		drawCards.emplace_back(d_cards.front());
		d_cards.pop_front();
	}

	return drawCards;
}


int CardDeck::numCardsInDeck() const {
	return d_cards.size();
}

} /* namespace app */
