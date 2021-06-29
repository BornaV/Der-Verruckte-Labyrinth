//----------------------------------------------------------------------------------------------------------------------
// StartTile.hpp
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

#ifndef A2_STARTTILE_HPP
#define A2_STARTTILE_HPP

#include "Tile.hpp"
#include "Player.hpp"

#include <string>

static const char SPACE_START_TILE = ' ';

class StartTile : public Tile
{
  private:
  
    std::string player_color_;
    size_t number_of_spaces;
    std::string helper_string;
    std::vector<Player*> helper_vector;
    
  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default StartTile constructor.
    ///
    /// 
    ///
    //
    StartTile(TileType type, Rotation rotation, std::string player_color);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// StartTile copy-constructor.
    ///
    /// 
    ///
    //
    StartTile(StartTile const&) = delete;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// StartTile destructor.
    ///
    /// 
    ///
    //
    virtual ~StartTile();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the player color as string.
    ///
    /// @return string color of player
    //
    std::string getPlayerColor() const;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string.
    ///
    /// @return string tile string
    //
    virtual std::string getTileString() override; 

    // pure virtual helper functions
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of zero degrees.
    ///
    /// @return string tile string
    //
    virtual std::string zero() override;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of 90 degrees.
    ///
    /// @return string tile string
    //
    virtual std::string ninety() override;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of 180 degrees.
    ///
    /// @return string tile string
    //
    virtual std::string oneEighty() override;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of 270 degrees.
    ///
    /// @return string tile string
    //
    virtual std::string twoSeventy() override;

};

#endif // A2_STARTTILE_HPP