//----------------------------------------------------------------------------------------------------------------------
// Game.hpp
//
// This is the Game class
// with its attributes and functions.
//
// Authors: 11804229
//          11814996
//          00713374
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Random.hpp"
#include "Treasure.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "StartTile.hpp"
#include "TreasureTile.hpp"
#include "NormalTile.hpp"
#include "UserInput.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <limits>

static const size_t HEIGHT_GAME = 7;
static const size_t WIDTH_GAME = 7;

static const size_t TILE_WIDTH = 9;

static const std::string ONE_AS_STRING = "1";
static const std::string TWO_AS_STRING = "2";
static const std::string THREE_AS_STRING = "3";
static const std::string FOUR_AS_STRING = "4";
static const std::string FIVE_AS_STRING = "5";
static const std::string SIX_AS_STRING = "6";
static const std::string SEVEN_AS_STRING = "7";

static const size_t ROW_TWO = 2;
static const size_t ROW_SEVEN = 7;
static const size_t ROW_TWELVE = 12;
static const size_t ROW_SEVENTEEN = 17;
static const size_t ROW_TWENTYTWO = 22;
static const size_t ROW_TWENTYSEVEN = 27;
static const size_t ROW_THIRTYTWO = 32;

static const std::string LEFT_ARROW = "-->";
static const std::string RIGHT_ARROW = "<--";

static const std::string LINE_VERTICAL = "|";
static const std::string WORD_TREASURE = "Treasure: ";
static const std::string SLASH_BETWEEN_NUMBERS = "/";
static const std::string UP_ARROW = "V";
static const std::string DOWN_ARROW = "Ʌ";
static const std::string EMPTY_STRING = "";

static const size_t PLAYER_RED = 0;
static const size_t PLAYER_YELLOW = 1;
static const size_t PLAYER_GREEN = 2;
static const size_t PLAYER_BLUE = 3;

static const size_t TOTAL_CARDS_FOR_PLAYERS = 24;
static const size_t BOARD_HEIGHT_IN_CHARACTERS = 35;
static const size_t BOARD_WIDTH_IN_CHARACTERS = 63;

static const size_t NUMBER_OF_STARTTILES = 4;
static const size_t NUMBER_OF_FIXEDTILES = 16;
static const size_t NUMBER_OF_FLEXIBLETILES = 34;

static const size_t ORIENTATION_ZERO = 0;
static const size_t ORIENTATION_NINETY = 1;
static const size_t ORIENTATION_ONEEIGHTY = 2;
static const size_t ORIENTATION_TWOSEVENTY = 3;

static const size_t MAXIMUM_NR_OF_PLAYERS = 4;

static const char BLACK_BOX_CHARACTER = (char)219;

static const size_t FIRST_FIXEDTILE = 0;
static const size_t SECOND_FIXEDTILE = 3;
static const size_t THIRD_FIXEDTILE = 12;
static const size_t FOURTH_FIXEDTILE = 15;

static const size_t LAST_NORMALTILE_L_TYPE = 11;
static const size_t LAST_NORMALTILE_I_TYPE = 22;

static const std::string BLACK_BLOCK_GAME = "\u2588";

static const size_t FIRST_FLEXTILE = 0;

class Game
{
  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns an instance of Game type.
    ///
    /// 
    ///
    /// @return static Game&
    //
    static Game& gameInstance()
    {
      static Game game_instance;
      return game_instance;
    }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Destructor of Game object.
    ///
    /// 
    ///
    /// 
    //
    ~Game(){}
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// It initializes the board with tiles.
    ///
    /// @param tiles_to_be_inserted Vector vector of the tiles to be inserted
    ///
    /// @return void
    //
    void initializeBoard(std::vector<std::vector<Tile*>> tiles_to_be_inserted); 

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Deletes the board and frees the memory.
    ///
    /// @return void
    //
    void deleteBoard(void);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Prints the board.
    ///
    /// @param nr_players Number of players
    /// @param players_vector Vector with the players
    ///
    /// @return void
    //
    void printBoard(size_t nr_players, std::vector<Player*> players_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Deletes all the tiles objects from heap.
    ///
    /// @param all_tiles All created tiles
    /// @param reserve_treasure_vector Reserve treasure tiles
    /// @param players_vector Players 
    /// @param player_count Amount of players
    ///
    /// @return void
    //
    void deleteObjects(std::vector<Tile*>& all_tiles, std::vector<Treasure*>& reserve_treasures_vector, 
                       std::vector<Player*>& players_vector, size_t player_count);
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Creates the treasure tiles.
    ///
    /// @param all_treasures_vector All treasures 
    /// @param reserve_treasures_vector Reserved treasures
    ///
    /// @return void
    //
    void createTreasures(std::vector<Treasure*>& all_treasures_vector, 
                         std::vector<Treasure*>& reserve_treasures_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns a vector of strings
    /// which represent the colors 
    /// of the players.
    ///
    ///
    /// @return std::vector<std::string>
    //
    std::vector<std::string> getPlayersColour();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Creates the players.
    ///
    /// @param players_vector Players
    /// @param player_count Amount of players
    ///
    /// @return void
    //
    void createPlayers(std::vector<Player*>& players_vector, size_t player_count);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Creates the fixed tiles.
    ///
    /// @param fixed_tiles Fixed tiles
    /// @param reserve_treasures_vector Reserved treasures
    /// @param players_vector Players
    /// @param player_count Amount of players
    /// @param start_tiles Start tiles
    /// @param all_tiles All tiles of the board
    ///
    /// @return void
    //
    void createFixtiles(std::vector<Tile*>& fixed_tiles, std::vector<Treasure*>& reserve_treasures_vector, 
                        std::vector<Player*>& players_vector, size_t player_count, std::vector<Tile*>& start_tiles,
                        std::vector<Tile*>& all_tiles);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Creates the flexible tiles.
    ///
    /// @param all_tiles All tiles
    /// @param flex_tiles Flexible tiles
    /// @param reserve_treasures_vector Reserved treasures
    ///
    /// @return void
    //
    void createFlextiles(std::vector<Tile*>& all_tiles, std::vector<Tile*>& flex_tiles, 
                         std::vector<Treasure*>& reserve_treasures_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Fills the board with tiles.
    ///
    /// @param board Reference to the board
    /// @param fixed_tiles Reference to the fixed tiles
    /// @param flex_tiles Reference to the flexible tiles
    /// @param random Reference to random object
    ///
    /// @return void
    //
    void fillBoardWithTiles(std::vector<std::vector<Tile*>>& board, std::vector<Tile*>& fixed_tiles,
                            std::vector<Tile*>& flex_tiles, Oop::Random& random);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Runs the game.
    ///
    /// @param player_count Amount of players
    /// @param user_input Reference to the user input
    /// @param random Reference to the random
    ///
    /// @return size_t player won or game was finished return 0, no possible memory return 1, wrong arguments return 2
    //
    size_t run(size_t player_count, UserInput& user_input, Oop::Random& random);
    
  private:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default Game constructor.
    ///
    /// 
    ///
    //
    Game(){}

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Game copy-constructor.
    ///
    /// 
    ///
    //
    Game(const Game&){} 

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Equal sign operator for object assigning.
    ///
    /// 
    ///
    //
    Game& operator = (const Game&); 

    std::vector<std::vector<Tile*>> game_board_ = {}; 
};

#endif // GAME_HPP
