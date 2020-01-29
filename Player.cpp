/*
 * Player.cpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#include "Player.hpp"
#include "Card.hpp"

namespace app {

namespace {
	const unsigned int LIMIT_SCORE = 21;
	const unsigned int FACE_CARD_SCORE = 10;
	const unsigned int MIN_ACE_SCORE = 1;
	const unsigned int MAX_ACE_SCORE = 11;
}

Player::Player(const std::string& name,
	   const int money,
	   const std::vector<app::Card>& cards) : d_name(name),
											  d_cards(cards),
											  d_money(money) {

}

const std::string& Player::getName() const {
	return d_name;
}

const int& Player::getBalance() const {
	return d_money;
}

void Player::addCards(std::vector<app::Card>& cards) {
	for(auto c: cards) {
		d_cards.emplace_back(c);
	}
}

void Player::removeCards() {
	d_cards.clear();
}

unsigned int Player::getCardPoints() const {
	unsigned int minSum = 0;
	unsigned int maxSum = 0;
	for(auto c: d_cards) {
		if("Jack" == c.getCard() || "Queen" == c.getCard() || "King" == c.getCard()) {
			minSum += FACE_CARD_SCORE;
			maxSum += FACE_CARD_SCORE;
		}
		else if("Ace" == c.getCard()) {
			minSum += MIN_ACE_SCORE;
			maxSum += MAX_ACE_SCORE;
		}
		else {
			minSum += std::atoi(c.getCard().c_str());
			maxSum += std::atoi(c.getCard().c_str());
		}
	}

	return (maxSum > LIMIT_SCORE) ? minSum : maxSum;
}

void Player::printCards(const bool dealer) const {
	if(dealer) {
		std::cout << "Dealer has ";
	}
	else {
		std::cout << "You have ";
	}
	for(auto c: d_cards) {
		std::cout << c << ", ";
	}

	std::cout << "points = " << getCardPoints();
	std::cout << '\n';
}

void Player::updateBalance(const int placedBet) {
	d_money -= placedBet;
}

const Card& Player::getCard(const int index) const {
	return d_cards[index];
}

} /* namespace app */

