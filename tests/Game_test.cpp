/*
 * Game_test.cpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#include "../Game.hpp"
#include "../Card.hpp"
#include "../CardDeck.hpp"
#include "../Player.hpp"


#include <iostream>

#include <gtest/gtest.h>

namespace app {
namespace test {

class GameTest : public ::testing::Test {

public:
	GameTest() : g(Game("test", 100)) {}

protected:
  void SetUp() override {

  }

  Game g;
};


TEST_F(GameTest, isPlayerBalanceValid_givenValidAmount_expectTrue) {
	EXPECT_TRUE(g.isPlayerBalanceValid(50));
}

TEST_F(GameTest, isPlayerBalanceValid_givenHigherAmount_expectFalse) {
	EXPECT_FALSE(g.isPlayerBalanceValid(101));
}

TEST_F(GameTest, isPlayerBalanceValid_givenNegativeAmount_expectTRUE) {
	EXPECT_TRUE(g.isPlayerBalanceValid(-101));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} /* namespace test */

} /* namespace app */
