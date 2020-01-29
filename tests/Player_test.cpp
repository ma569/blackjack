/*
 * Player_test.cpp
 *
 *  Created on: Jan 28, 2020
 *      Author: musabbir
 */

#include "../Player.hpp"
#include "../Card.hpp"
#include <iostream>

#include <gtest/gtest.h>

namespace app {
namespace test {

class PlayerTest : public ::testing::Test {

public:
	PlayerTest() : p(Player("test")),
	  	  	  	   q(Player("test", 1000)) {

	}

protected:
  void SetUp() override {
  }

  Player p;
  Player q;
};

TEST_F(PlayerTest, getBalance_defaultConstructed_expect100) {
	EXPECT_EQ(100, p.getBalance());
}

TEST_F(PlayerTest, getBalance_initialisedBalance_expect1000) {
	EXPECT_EQ(1000, q.getBalance());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} /* namespace test */

} /* namespace app */

