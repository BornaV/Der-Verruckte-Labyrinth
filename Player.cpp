//----------------------------------------------------------------------------------------------------------------------
// Player.cpp
//
// This is the imlementation of 
// the Player class methods, which 
// can be useful later on in the code
// where players start playing.
//
// Authors: 11804229
//          11814996
//          00713374
//----------------------------------------------------------------------------------------------------------------------
//

#include "Player.hpp"

///---------------------------------------------------------------------------------------------------------------------
void Player::popFrontTreasureStack()
{ 
  covered_stack_.pop(); 
  nr_found_treasures_++;
} 

///---------------------------------------------------------------------------------------------------------------------
bool Player::stackEmpty()
{
  if (covered_stack_.empty() == true)
  {
    return true;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
std::string Player::getCurrentTreasureName()
{ 
  std::string return_string = "";
  return_string = covered_stack_.top()->getName();
  return return_string; 
}

///---------------------------------------------------------------------------------------------------------------------
std::string Player::getCurrentTreasureId()
{ 
  std::stringstream help_id;
  std::string id;
  if (covered_stack_.top()->getTreasureId() < 10)
  {
    help_id << 0 << covered_stack_.top()->getTreasureId();
  }
  else
  {
    help_id << covered_stack_.top()->getTreasureId();
  }
  id = help_id.str();
  return id; 
}