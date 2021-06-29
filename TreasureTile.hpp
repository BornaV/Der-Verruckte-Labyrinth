//----------------------------------------------------------------------------------------------------------------------
// TreasureTile.hpp
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

#ifndef A2_TREASURETILE_HPP
#define A2_TREASURETILE_HPP

#include "Tile.hpp"
#include "Treasure.hpp"

#include <string>

static const char SPACE_TREASURE_TILE = ' ';

class TreasureTile : public Tile
{
  private:
    Treasure treasure_;
    bool collected_;
    size_t number_of_spaces;
    std::string helper_string;
    std::vector<Player*> helper_vector;

  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Constructor of TreasureTile object.
    ///
    /// 
    ///
    /// 
    //
    TreasureTile(TileType type, Rotation rotation, Treasure treasure);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Copy constructor of TreasureTile object.
    ///
    /// 
    ///
    /// 
    //
    TreasureTile(TreasureTile const&) = delete;
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Destructor of TreasureTile object.
    ///
    /// 
    ///
    /// 
    //
    virtual ~TreasureTile();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the treasure.
    ///
    /// @return Treasure object of a treasure
    //
    Treasure getTreasure() const;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets collected.
    ///
    /// @return bool true if it is collected, otherwise false
    //
    bool getCollected() const;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Collects a treasure
    ///
    /// @return void
    //
    void collectTreasure();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the tile string.
    ///
    /// @return string tile as string
    //
    virtual std::string getTileString() override;
    
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

#endif // A2_TREASURETILE_HPP