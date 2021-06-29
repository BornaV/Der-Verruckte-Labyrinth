//----------------------------------------------------------------------------------------------------------------------
// Tile.cpp
//
// Class Tile contains methods and objects for storing
// the Tile objects that will be later used when creating
// the board using the provided random Class
//
// Author: 11804229 
//         11814996
//         00713374
//----------------------------------------------------------------------------------------------------------------------
//

#include "Tile.hpp"

#include <string>
#include <vector>

///---------------------------------------------------------------------------------------------------------------------
Tile::Tile(TileType type, Rotation rotation) : type_(type), rotation_(rotation){}

///---------------------------------------------------------------------------------------------------------------------
Tile::~Tile(){}

///---------------------------------------------------------------------------------------------------------------------
int Tile::getRotationValue() const
{
  if(this->getRotation() == Rotation::DEG0)
  {
    return ZERO;
  }
  if(this->getRotation() == Rotation::DEG90)
  {
    return NINETY;
  }
  if(this->getRotation() == Rotation::DEG180)
  {
    return ONE_EIGHTY;
  }
  if(this->getRotation() == Rotation::DEG270)
  {
    return TWO_SEVENTY;
  }
  return 0;
}

///---------------------------------------------------------------------------------------------------------------------
std::string Tile::getTileTypeString() const
{
  switch(type_) 
  {
    case TileType::T:
      return "T";
    case TileType::L:
      return "L";
    case TileType::I:
      return "I";
    case TileType::O:
      return "O";
    case TileType::U:
      return "U";
    case TileType::X:
      return "X";
  }
}

///---------------------------------------------------------------------------------------------------------------------
TileType Tile::getType() const
{
  return type_;
}

///---------------------------------------------------------------------------------------------------------------------
Rotation Tile::getRotation() const
{
  return rotation_;
}

///---------------------------------------------------------------------------------------------------------------------
void Tile::setPlayers(std::vector<Player*> player_vector)
{
  players_ = player_vector;
}

///---------------------------------------------------------------------------------------------------------------------
std::vector<Player*> Tile::getPlayers()
{
  return players_;
}

///---------------------------------------------------------------------------------------------------------------------
void Tile::setRotation(Rotation value)
{
  rotation_ = value;
}

///---------------------------------------------------------------------------------------------------------------------
void Tile::pushPlayerToPlayersVector(Player* player_object)
{
  players_.push_back(player_object);
}

///---------------------------------------------------------------------------------------------------------------------
size_t Tile::nrSpacesSevenMaxThreePlayers()
{
  size_t start_of_spaces = 4 + this->getPlayersVectorSize(); 
  size_t number_of_spaces = 7 - start_of_spaces;

  return number_of_spaces;
}

///---------------------------------------------------------------------------------------------------------------------
size_t Tile::nrSpacesNineMaxThreePlayers()
{
  size_t start_of_spaces = 4 + this->getPlayersVectorSize(); 
  size_t number_of_spaces = 9 - start_of_spaces;

  return number_of_spaces;
}

///---------------------------------------------------------------------------------------------------------------------
size_t Tile::nrSpacesSevenFourPlayers()
{
  size_t start_of_spaces = 3 + this->getPlayersVectorSize(); 
  size_t number_of_spaces = 7 - start_of_spaces;

  return number_of_spaces;
}

///---------------------------------------------------------------------------------------------------------------------
size_t Tile::nrSpacesNineFourPlayers()
{
  size_t start_of_spaces = 3 + this->getPlayersVectorSize(); 
  size_t number_of_spaces = 9 - start_of_spaces;

  return number_of_spaces;
}

///---------------------------------------------------------------------------------------------------------------------
bool Tile::checkIfPlayersVectorEmpty()
{
  if(players_.empty() == true)
  {
    return true;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
void Tile::clearPlayersVector()
{
  players_.clear();
}

///---------------------------------------------------------------------------------------------------------------------
bool Tile::containsPlayer(Player* player_object)
{
  for(size_t players_counter = 0; players_counter < players_.size(); players_counter++)
  {
    if(players_.at(players_counter)->getColor() == player_object->getColor())
    {
      return true;
    }
  }
  return false;
}