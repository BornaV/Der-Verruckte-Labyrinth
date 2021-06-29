//----------------------------------------------------------------------------------------------------------------------
// NormalTile.hpp
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

#ifndef A2_NORMALTILE_HPP
#define A2_NORMALTILE_HPP

#include "Tile.hpp"

#include <string>

static const char SPACE_NORMAL_TILE = ' ';

class NormalTile : public Tile
{
  private:

    size_t number_of_spaces;
    std::string helper_string;
    std::vector<Player*> helper_vector;
    
  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default NormalTile constructor.
    ///
    /// 
    ///
    //
    NormalTile(TileType type, Rotation rotation);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// NormalTile copy-constructor.
    ///
    /// 
    ///
    //
    NormalTile(NormalTile const&) = delete;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// NormalTile destructor.
    ///
    /// 
    ///
    //
    virtual ~NormalTile();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string.
    ///
    /// @return string tile string
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

#endif // A2_NORMALTILE_HPP