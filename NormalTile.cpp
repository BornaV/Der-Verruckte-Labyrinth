//----------------------------------------------------------------------------------------------------------------------
// NormalTile.cpp
//
// Class NormalTile contains methods and objects for storing
// the NormalTile objects that will be later used when creating
// the board using the provided random Class
//
// Author: 11804229 
//         11814996
//         00713374
//----------------------------------------------------------------------------------------------------------------------
//

#include "NormalTile.hpp"

#include <string>
#include <sstream>

///---------------------------------------------------------------------------------------------------------------------
NormalTile::NormalTile(TileType type, Rotation rotation) : Tile(type, rotation){}

///---------------------------------------------------------------------------------------------------------------------
NormalTile::~NormalTile() = default;

///---------------------------------------------------------------------------------------------------------------------
std::string NormalTile::zero()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  if (getTileTypeString() == "I")
  {
    helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    if (this->checkIfPlayersVectorEmpty() == false)
    {
      if (this->getPlayersVectorSize() <= 3)
      {
        helper_string_stream << BOX << BOX << ONE_SPACE << PLAYER;
        number_of_spaces = nrSpacesSevenMaxThreePlayers();
      }
      else
      {
        helper_string_stream << BOX << BOX << PLAYER;
        number_of_spaces = nrSpacesSevenFourPlayers();
      }
      for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
      {
        helper_string_stream << helper_vector.at(counter)->getColor();
      }
      helper_string_stream << std::string(number_of_spaces,' ') << BOX << BOX;
    }
    else
    {
      helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    }
    helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    helper_string = helper_string_stream.str();

    return helper_string;
  }
  
  else if (getTileTypeString() == "L")
  {
    helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    helper_string_stream << BOX << BOX << SEVEN_SPACES;
    helper_string_stream << BOX << BOX << SEVEN_SPACES;
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
      helper_string_stream << std::string(number_of_spaces,SPACE_NORMAL_TILE);     
    }
    else
    {
      helper_string_stream << BOX << BOX << SEVEN_SPACES;
    }
    helper_string_stream << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX;
    helper_string = helper_string_stream.str();

    return helper_string;
  }

  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string NormalTile::ninety()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  if (getTileTypeString() == "I")
  {
    helper_string_stream << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX;
    helper_string_stream << NINE_SPACES;
    helper_string_stream << NINE_SPACES;
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
      helper_string_stream << std::string(number_of_spaces,SPACE_NORMAL_TILE);
    }
    else
    {
      helper_string_stream << NINE_SPACES;
    }
    helper_string_stream << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX;    
    helper_string = helper_string_stream.str();

    return helper_string;
  }

  else if (getTileTypeString() == "L")
  {
    helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
    helper_string_stream << SEVEN_SPACES << BOX << BOX;
    helper_string_stream << SEVEN_SPACES << BOX << BOX;
    if (this->checkIfPlayersVectorEmpty() == false)
    {
      if (this->getPlayersVectorSize() <= 3)
      {
        helper_string_stream << THREE_SPACES << PLAYER;;
        number_of_spaces = nrSpacesSevenMaxThreePlayers();
      }
      else
      {
        helper_string_stream << BOX << BOX << PLAYER;
        number_of_spaces = nrSpacesSevenFourPlayers();
      }
      for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
      {
        helper_string_stream << helper_vector.at(counter)->getColor();
      }
      helper_string_stream << std::string(number_of_spaces,SPACE_NORMAL_TILE) << BOX << BOX;
    }
    else
    {
      helper_string_stream << SEVEN_SPACES << BOX << BOX;
    }
    helper_string_stream << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX;
    helper_string = helper_string_stream.str();

    return helper_string;
  }

  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string NormalTile::oneEighty()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  helper_string_stream << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX;
  helper_string_stream << SEVEN_SPACES << BOX << BOX;
  helper_string_stream << SEVEN_SPACES << BOX << BOX;
  if (this->checkIfPlayersVectorEmpty() == false)
  {
    if (this->getPlayersVectorSize() <= 3)
    {
      helper_string_stream << THREE_SPACES << PLAYER;;
      number_of_spaces = nrSpacesSevenMaxThreePlayers();
    }
    else
    {
      helper_string_stream << BOX << BOX << PLAYER;
      number_of_spaces = nrSpacesSevenFourPlayers();
    }
    for (size_t counter = 0; counter < this->getPlayersVectorSize(); counter++)
    {
      helper_string_stream << helper_vector.at(counter)->getColor();
    }
    helper_string_stream << std::string(number_of_spaces,SPACE_NORMAL_TILE) << BOX << BOX;
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
std::string NormalTile::twoSeventy()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  helper_string_stream << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX << BOX;
  helper_string_stream << BOX << BOX << SEVEN_SPACES;
  helper_string_stream << BOX << BOX << SEVEN_SPACES;
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
    helper_string_stream << std::string(number_of_spaces,SPACE_NORMAL_TILE);     
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
std::string NormalTile::getTileString()
{
  std::string final_string;
  std::string TileStringType = getTileTypeString();
  int rotationValue = getRotationValue();

  if (TileStringType == "I")
  {
    if (rotationValue == ZERO || rotationValue == ONE_EIGHTY)
    {
      final_string = zero();
      return final_string;
    }
    else if (rotationValue == NINETY || rotationValue == TWO_SEVENTY)
    {
      final_string = ninety();
      return final_string;
    }
    else
    {
      return final_string;
    }
  }
  
  else if (TileStringType == "L")
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
    else
    {
      return final_string;
    }
  }

  return final_string;
}