//----------------------------------------------------------------------------------------------------------------------
// TreasureTile.cpp
//
// Class TreasureTile contains methods and objects for storing
// the TreasureTile objects that will be later used when creating
// the board objects that include treasures using the provided random Class
//
// Author: 11804229 
//         11814996
//         00713374
//----------------------------------------------------------------------------------------------------------------------
//

#include "TreasureTile.hpp"

#include <string>
#include <sstream>

///---------------------------------------------------------------------------------------------------------------------
TreasureTile::TreasureTile(TileType type, Rotation rotation, Treasure treasure) : Tile(type, rotation), 
                           treasure_(treasure)
{
    collected_ = false;
}

///---------------------------------------------------------------------------------------------------------------------
TreasureTile::~TreasureTile() = default;

///---------------------------------------------------------------------------------------------------------------------
Treasure TreasureTile::getTreasure() const
{
  return treasure_;
}

///---------------------------------------------------------------------------------------------------------------------
bool TreasureTile::getCollected() const
{
  return collected_;
}

///---------------------------------------------------------------------------------------------------------------------
void TreasureTile::collectTreasure()
{
  collected_ = true;
}

///---------------------------------------------------------------------------------------------------------------------
std::string TreasureTile::zero()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();
  size_t this_treasure_id = this->getTreasure().getTreasureId();

  helper_string_stream << BOX << BOX << BOX << BOX << BOX<< BOX << BOX << BOX << BOX;
  helper_string_stream << NINE_SPACES;
  if (collected_ == false)
  {
    if (this_treasure_id <= 9)
    {
      helper_string_stream << THREE_SPACES << T_CHAR_ZERO << this_treasure_id << THREE_SPACES;
    }
    else
    {
      helper_string_stream << THREE_SPACES << T_CHAR << this_treasure_id << THREE_SPACES;
    }
  }
  else
  {
    helper_string_stream << NINE_SPACES;
  }
  if (this->checkIfPlayersVectorEmpty() == false)
  {
    if (this->getPlayersVectorSize() <= 3)
    {
      helper_string_stream << THREE_SPACES << PLAYER;
      number_of_spaces = nrSpacesNineMaxThreePlayers();
    }
    else
    {
      helper_string_stream << TWO_SPACES << PLAYER;
      number_of_spaces = nrSpacesNineFourPlayers();
    }
    for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
    {
      helper_string_stream << helper_vector.at(counter)->getColor();
    }
    helper_string_stream << std::string(number_of_spaces,SPACE_TREASURE_TILE);     
  }
  else
  {
    helper_string_stream << NINE_SPACES;
  }
  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string = helper_string_stream.str();
          
  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string TreasureTile::ninety()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();
  size_t this_treasure_id = this->getTreasure().getTreasureId();

  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string_stream << BOX << BOX << SEVEN_SPACES;
  if (collected_ == false)
  {
    if (this_treasure_id <= 9)
    {
      helper_string_stream << BOX << BOX << ONE_SPACE << T_CHAR_ZERO << this_treasure_id << THREE_SPACES;
    }
    else
    {
      helper_string_stream << BOX << BOX << ONE_SPACE << T_CHAR << this_treasure_id << THREE_SPACES;
    }
  }
  else
  {
    helper_string_stream << BOX << BOX << SEVEN_SPACES;
  }
  if (this->checkIfPlayersVectorEmpty() == false)
  {
    if (this->getPlayersVectorSize() <= 3)
    {
      helper_string_stream << BOX << BOX << ONE_SPACE << PLAYER;
      number_of_spaces = nrSpacesNineMaxThreePlayers();
    }
    else
    {
      helper_string_stream << BOX << BOX << PLAYER;
      number_of_spaces = nrSpacesNineFourPlayers();
    }
    for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
    {
      helper_string_stream << helper_vector.at(counter)->getColor();
    }
    helper_string_stream << std::string(number_of_spaces,SPACE_TREASURE_TILE);
  }
  else
  {
    helper_string_stream << BOX << BOX << SEVEN_SPACES;
  }
  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string = helper_string_stream.str();
    
  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string TreasureTile::oneEighty()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();
  size_t this_treasure_id = this->getTreasure().getTreasureId();

  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string_stream << NINE_SPACES;
  if (collected_ == false)
  {
    if (this_treasure_id <= 9)
    {
      helper_string_stream << THREE_SPACES << T_CHAR_ZERO << this_treasure_id << THREE_SPACES;
    }
    else
    {
      helper_string_stream << THREE_SPACES << T_CHAR << this_treasure_id << THREE_SPACES;
    }
  }
  else
  {
    helper_string_stream << NINE_SPACES;
  }
  if (this->checkIfPlayersVectorEmpty() == false)
  {
    if (this->getPlayersVectorSize() <= 3)
    {
      helper_string_stream << THREE_SPACES << PLAYER;
      number_of_spaces = nrSpacesNineMaxThreePlayers();
    }
    else
    {
      helper_string_stream << TWO_SPACES << PLAYER;
      number_of_spaces = nrSpacesNineFourPlayers();
    }
    for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
    {
      helper_string_stream << helper_vector.at(counter)->getColor();
    }
    helper_string_stream << std::string(number_of_spaces,SPACE_TREASURE_TILE);
  }
  else
  {
    helper_string_stream << NINE_SPACES;
  }
  helper_string_stream << BOX << BOX << BOX << BOX << BOX<< BOX << BOX << BOX << BOX;
  helper_string = helper_string_stream.str();

  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string TreasureTile::twoSeventy()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();
  size_t this_treasure_id = this->getTreasure().getTreasureId();

  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string_stream << SEVEN_SPACES << BOX << BOX;
  if (collected_ == false)
  {
    if (this_treasure_id <= 9)
    {
      helper_string_stream << THREE_SPACES << T_CHAR_ZERO << this_treasure_id << ONE_SPACE << BOX << BOX;
    }
    else
    {
      helper_string_stream << THREE_SPACES << T_CHAR << this_treasure_id << ONE_SPACE << BOX << BOX;
    }
  }
  else
  {
    helper_string_stream << SEVEN_SPACES << BOX << BOX;
  }
  if (this->checkIfPlayersVectorEmpty() == false)
  {
    if (this->getPlayersVectorSize() <= 3)
    {
      helper_string_stream << THREE_SPACES << PLAYER;
      number_of_spaces = nrSpacesSevenMaxThreePlayers();
    }
    else
    {
      helper_string_stream << TWO_SPACES << PLAYER;
      number_of_spaces = nrSpacesSevenFourPlayers();
    }
    for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
    {
      helper_string_stream << helper_vector.at(counter)->getColor();
    }
    helper_string_stream << std::string(number_of_spaces,SPACE_TREASURE_TILE) << BOX << BOX;
  }
  else
  {
    helper_string_stream << SEVEN_SPACES << BOX << BOX;
  }
  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string = helper_string_stream.str();
          
  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string TreasureTile::getTileString()
{
  std::string final_string;
  int rotationValue = getRotationValue();

  if (getTileTypeString() == T_CHAR)
  {
    if (rotationValue == ZERO)
    {    
      final_string = zero();
      return final_string;
    }

    if (rotationValue == NINETY)
    {
      final_string = ninety();
      return final_string;
    }

    if (rotationValue == ONE_EIGHTY)
    {
      final_string = oneEighty();
      return final_string;
    }

    if (rotationValue == TWO_SEVENTY)
    {
      final_string = twoSeventy();
      return final_string;
    }
  }

  return final_string;
}