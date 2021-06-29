//----------------------------------------------------------------------------------------------------------------------
// Tile.hpp
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

#ifndef A2_TILE_HPP
#define A2_TILE_HPP

#include "Player.hpp"
#include "Treasure.hpp"

#include <string>
#include <vector>

static const char BOX = (char)219;

static const size_t ZERO = 0;
static const size_t NINETY = 90;
static const size_t ONE_EIGHTY = 180;
static const size_t TWO_SEVENTY = 270;
 
static const std::string PLAYER = "P";
static const std::string T_CHAR = "T";
static const std::string T_CHAR_ZERO = "T0";

static const std::string ONE_SPACE    = " ";
static const std::string TWO_SPACES   = "  ";
static const std::string THREE_SPACES = "   ";
static const std::string FIVE_SPACES  = "     ";
static const std::string SEVEN_SPACES = "       ";
static const std::string NINE_SPACES  = "         ";

enum class TileType {T, L, I, O, U, X};
enum class Rotation {DEG0 = 0, DEG90 = 1, DEG180 = 2, DEG270 = 3};

class Tile
{
  private:
    TileType type_;
    Rotation rotation_;
    std::vector<Player*> players_;
    Treasure treasure_object_;

  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default Tile constructor.
    ///
    /// 
    ///
    //
    Tile(TileType type, Rotation rotation);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Tile copy-constructor.
    ///
    /// 
    ///
    //
    Tile(Tile const&) = default;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Tile destructor.
    ///
    /// 
    ///
    //
    virtual ~Tile() = 0;
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string.
    ///
    /// @return string tile string
    //
    virtual std::string getTileString() = 0; 

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the rotation value. 
    ///
    /// @return int rotation value
    //
    int getRotationValue() const;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the string of the tile type.
    ///
    /// @return string tile type
    //
    std::string getTileTypeString() const;
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the type of the tile.
    ///
    /// @return TileType type of the tile
    //
    TileType getType() const;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the rotation of the tile.
    ///
    /// @return Rotation rotation of the tile
    //
    Rotation getRotation() const;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the players.
    ///
    /// @return vector<Player*> vector of players
    //
    std::vector<Player*> getPlayers();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the players.
    ///
    /// @param player_vector vector of players
    ///
    /// @return void
    //
    void setPlayers(std::vector<Player*> player_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the rotation value.
    ///
    /// @param value rotation value
    ///
    /// @return void
    //
    void setRotation(Rotation value);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Pushs player to players vector.
    ///
    /// @param player_object a single player
    ///
    /// @return void
    //
    void pushPlayerToPlayersVector(Player* player_object);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if players vector is empty.
    ///
    /// @return true if yes, otherwise false
    //
    bool checkIfPlayersVectorEmpty();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the size of the players vector.
    ///
    /// @return size_t size of players vector
    //
    size_t getPlayersVectorSize() { return players_.size(); }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Cleares the players vector.
    ///
    /// @return void
    //
    void clearPlayersVector();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if a certain player is in the vector of players.
    ///
    /// @param player_object a single player
    ///
    /// @return bool true if it is inside, otherwise false
    //
    bool containsPlayer(Player* player_object);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Calculates number of spaces between last player and margin of tile in three players case.
    ///
    /// @return size_t amount of spaces
    //
    size_t nrSpacesSevenMaxThreePlayers();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Calculates number of spaces between last player and margin of tile in three players case.
    ///
    /// @return size_t amount of spaces
    //
    size_t nrSpacesNineMaxThreePlayers();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Calculates number of spaces between last player and margin of tile in four players case.
    ///
    /// @return size_t amount of spaces
    //
    size_t nrSpacesSevenFourPlayers();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Calculates number of spaces between last player and margin of tile in four players case.
    ///
    /// @return size_t amount of spaces
    //
    size_t nrSpacesNineFourPlayers();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of zero degrees.
    ///
    /// @return string tile string
    //
    virtual std::string zero() = 0;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of 90 degrees.
    ///
    /// @return string tile string
    //
    virtual std::string ninety() = 0;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of 180 degrees.
    ///
    /// @return string tile string
    //
    virtual std::string oneEighty() = 0;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the tile string of 270 degrees.
    ///
    /// @return string tile string
    //
    virtual std::string twoSeventy() = 0;
};

#endif // A2_TILE_HPP