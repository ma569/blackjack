# To run application:

- mkdir build
- cd build
- cmake ../
- make
- ./main.bin

# To build test:
Please ensure you have gtest installed. See internet for details

- cd test/
- mkdir build
- cd build
- cmake ../
- make

# Code design
- Business logic is in Game class
- Game knows about Card, CardDeck and Players
- There can be multiple players and each time the game starts the player should enter the name
- There is only one dealer with infinite budget

# TODO
- Cleanup cmake
- Write proper unit tests using gmock library (they are effectively integration tests). They are basic tests. One should extensive tests for production level codes.
- For each class, one should "delete" copy/move constructors and assignment operator
- error checking on user input is minimal 
- implement split and in-game increase in bet
