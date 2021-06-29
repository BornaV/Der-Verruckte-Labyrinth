//----------------------------------------------------------------------------------------------------------------------
// StartTile.cpp
//
// Class StartTile contains methods and objects for storing
// the StartTile objects that will be later used when creating
// the board using the provided random Class
//
// Author: 11804229 
//         11814996
//         00713374
//----------------------------------------------------------------------------------------------------------------------
//

#include "StartTile.hpp"
#include "Player.hpp"

#include <string>
#include <sstream>

///---------------------------------------------------------------------------------------------------------------------
StartTile::StartTile(TileType type, Rotation rotation, std::string player_color) : Tile(type, rotation), 
                     player_color_(player_color){}
StartTile::~StartTile() = default;

///---------------------------------------------------------------------------------------------------------------------
std::string StartTile::getPlayerColor() const
{
  return player_color_;
}

///---------------------------------------------------------------------------------------------------------------------
std::string StartTile::zero()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string_stream << BOX << BOX << SEVEN_SPACES;
  helper_string_stream << BOX << BOX << ONE_SPACE << "(G)" << THREE_SPACES;
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
    helper_string_stream << std::string(number_of_spaces, SPACE_START_TILE);     
  }
  else
  {
    helper_string_stream << BOX << BOX << SEVEN_SPACES;
  }
  helper_string_stream << BOX << BOX << BOX << BOX << BOX<< BOX << BOX << BOX << BOX;
  helper_string = helper_string_stream.str();

  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string StartTile::ninety()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  helper_string_stream << BOX << BOX << FIVE_SPACES << BOX << BOX;
  helper_string_stream << SEVEN_SPACES << BOX << BOX;
  helper_string_stream << THREE_SPACES << "(B)" << ONE_SPACE << BOX << BOX;
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
    helper_string_stream << std::string(number_of_spaces,SPACE_START_TILE) << BOX << BOX;
  }
  else
  {
    helper_string_stream << SEVEN_SPACES << BOX << BOX;
  }
  helper_string_stream << BOX << BOX << BOX << BOX << BOX<< BOX << BOX << BOX << BOX;
  helper_string = helper_string_stream.str();
      
  return helper_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::string StartTile::oneEighty()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  helper_string_stream << BOX << BOX << BOX << BOX << BOX<< BOX << BOX << BOX << BOX;
  helper_string_stream << SEVEN_SPACES << BOX << BOX;
  helper_string_stream << THREE_SPACES << "(Y)" << ONE_SPACE << BOX << BOX;
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
    helper_string_stream << std::string(number_of_spaces,SPACE_START_TILE) << BOX << BOX;
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
std::string StartTile::twoSeventy()
{
  std::stringstream helper_string_stream;
  helper_vector = this->getPlayers();

  helper_string_stream << BOX << BOX << BOX << BOX << BOX<< BOX << BOX << BOX << BOX;
  helper_string_stream << BOX << BOX << SEVEN_SPACES;
  helper_string_stream << BOX << BOX << ONE_SPACE << "(R)" << THREE_SPACES;
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
    helper_string_stream << std::string(number_of_spaces,SPACE_START_TILE);     
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
std::string StartTile::getTileString()
{ 
  std::string final_string;
  Rotation rotation = getRotation();

  if (getTileTypeString() == "L")
  {
    if (rotation == Rotation::DEG0)
    {
      final_string = zero();
      return final_string;
    }

    if (rotation == Rotation::DEG90)
    {
      final_string = ninety();
      return final_string;
    }

    if (rotation == Rotation::DEG180)
    {
      final_string = oneEighty();
      return final_string;
    }

    if (rotation == Rotation::DEG270)
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