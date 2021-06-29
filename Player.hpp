//----------------------------------------------------------------------------------------------------------------------
// Player.hpp
//
// This is the Player class
// with its attributes and functions.
//
// Authors: 11804229
//          11814996
//          00713374
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Treasure.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <sstream>

class Player
{
  private:
    std::stack<Treasure*> covered_stack_ = {};
    size_t nr_found_treasures_ = 0;
    std::string color_;
    std::vector<Treasure*> treasures_per_player_ = {};

  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default Player constructor.
    ///
    /// 
    ///
    //
    Player(std::string color) : color_{color}{}

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Player copy-constructor.
    ///
    /// 
    ///
    //
    Player(Player const&) = delete;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// UserInput destructor.
    ///
    /// 
    ///
    //
    ~Player(){}

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Pushs a treasure to the vector of treasures.
    ///
    /// @param treasure Pointer of a treasure 
    ///
    /// @return void
    //
    void pushToVector(Treasure* treasure){ treasures_per_player_.push_back(treasure); } 

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Pushs a treasure to local vector of treasures.
    ///
    /// @param treasure Pointer of a treasure
    /// 
    /// @return void
    //
    void pushBackTreasureStack(Treasure* treasure){ covered_stack_.push(treasure); } 
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Pops a treasure from local vector of treasures.
    /// 
    /// @return void
    //
    void popFrontTreasureStack(); 
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the size of the local vector of tresures.
    /// 
    /// @return size_t size of the vector
    //
    size_t getStackSize(){ return covered_stack_.size(); }
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the number of found treasures.
    /// 
    /// @return size_t number of found treasures
    //
    size_t getNrFoundTreasures(){ return nr_found_treasures_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the number of found treasures.
    /// 
    /// @return bool true if it´s empty, otherwise false
    //
    bool stackEmpty();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the name of the current treasure.
    /// 
    /// @return string name as a string
    //
    std::string getCurrentTreasureName();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the id of the current treasure.
    /// 
    /// @return string id as a string
    //
    std::string getCurrentTreasureId();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the color of the player.
    /// 
    /// @return string color of a player
    //
    std::string getColor(){ return color_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// sets the color of the player to given color.
    /// 
    /// @return string color of a player
    //
    void setColor(std::string color){ color_ = color; }
};

#endif // PLAYER_HPP