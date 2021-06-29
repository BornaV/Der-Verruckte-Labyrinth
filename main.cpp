//---------------------------------------------------------------------------------------------------------------------
// main.cpp
//
// This is the main
// it checks if there are wrong arguments
// creates random and game objects and 
// starts running the game.
//
// Authors: 11804229
//          11814996
//          00713374
//---------------------------------------------------------------------------------------------------------------------
//

#include "Random.hpp"
#include "Game.hpp"
#include "Treasure.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "StartTile.hpp"
#include "TreasureTile.hpp"
#include "NormalTile.hpp"
#include "UserInput.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include <string>

static const std::string WRONG_ARGS = "Wrong arguments!";
static const size_t RETURN_VALUE_2 = 2;
static const size_t RETURN_VALUE_1 = 1;
static const size_t RETURN_VALUE_0 = 0;
static const size_t ARGUMENT_NUMBER_1 = 1;

using namespace Oop;

int main(int argc, char** argv)
{
  if (argc != ARGUMENT_NUMBER_1)
  {
    std::cout << WRONG_ARGS << std::endl;
    return RETURN_VALUE_2;
    char** unused_variable_removal = argv;
    unused_variable_removal++;            
  }

  size_t player_count;
  UserInput user_input;
  player_count = user_input.playerAmount();
  user_input.setNumberOfPlayers(player_count);
  
  Game& game = Game::gameInstance();
  Random& random = Random::getInstance(); 
  try
  {
    game.run(player_count, user_input, random);
  }
  catch(std::bad_alloc&)
  {
    return RETURN_VALUE_1;
  }
  return RETURN_VALUE_0;
}