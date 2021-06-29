//----------------------------------------------------------------------------------------------------------------------
// UserInput.hpp
//
// Class UserInput contains methods and objects for storing
// the user input objects that will be later used when creating
// the board using the provided random Class
//
// Author: 11804229 
//         11814996
//         00713374
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "Player.hpp"
#include "Tile.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

static const std::string COMMAND_DOES_NOT_TAKE_ARGUMENTS = "This command does not take any arguments!";
static const std::string INVALID_COMMAND = "Invalid command: ";
static const std::string INVALID_PARAMETER = "Invalid parameter: ";
static const std::string CURRENTLY_NOT_ALLOWED = " is currently not allowed";
static const std::string TREASURE = "Treasure: ";
static const std::string WRONG_ARGUMENTS = "Wrong number of arguments!";
static const std::string INVALID_POSITION = "Invalid Position!";
static const std::string IMPOSSIBLE_MOVE = "Impossible move!";
static const std::string ALL_TREASURES_FOUND = "All Treasures found, return to your startfield to win!";

static const std::string VERTICAL_LINE = "|";
static const std::string QUOTATION_MARK = "\"";

static const std::string ID_OF_TREASURE = " Nr.: ";
static const std::string CURRENT_TREASURE = "Current Treasure: ";
static const std::string FREE_TILE = "Free tile:\n";

static const std::string BOARD_ARROW_RIGHT = "<--";
static const std::string BOARD_ARROW_LEFT = "-->";
static const std::string BOARD_ARROW_UP = "V";
static const std::string BOARD_ARROW_DOWN = "Ʌ";
static const std::string SLASH = "/";

static const std::string ONE = "1";
static const std::string TWO = "2";
static const std::string THREE = "3";
static const std::string FOUR = "4";
static const std::string FIVE = "5";
static const std::string SIX = "6";
static const std::string SEVEN = "7";

static const char FIRST_LETTER_COLOR_RED = 'R';
static const char FIRST_LETTER_COLOR_YELLOW = 'Y';
static const char FIRST_LETTER_COLOR_GREEN = 'G';
static const char FIRST_LETTER_COLOR_BLUE = 'B';

static const std::string THE_PLAYER = "The Player ";
static const std::string WON_THE_GAME = " has won the game!\n";

static const std::string TOP_LONG = "top";
static const std::string TOP_SHORT = "t";
static const std::string BOTTOM_LONG = "bottom";
static const std::string BOTTOM_SHORT = "b";
static const std::string LEFT_LONG = "left";
static const std::string LEFT_SHORT = "l";
static const std::string RIGHT_LONG = "right";
static const std::string RIGHT_SHORT = "r";

static const std::string ARROW_UP = "\x1b[A";
static const std::string ARROW_RIGHT = "\x1b[C";
static const std::string ARROW_DOWN = "\x1b[B";
static const std::string ARROW_LEFT = "\x1b[D";

static const std::string BLACK_BLOCK = "\u2588";

static const std::string EMPTY_CHARACTER = "";
static const char SPACE = ' ';
static const size_t NUMBER_219 = 219;

static const size_t HEIGHT = 7;
static const size_t WIDTH = 7;

static const size_t START = 0;
static const size_t REDUCE_ONE = 1;
static const size_t ADD_ONE = 1;
static const size_t EQUAL_ONE = 1;
static const size_t EQUAL_ZERO = 0;
static const size_t EQUAL_SIX = 6;
static const size_t END_TILE = 8;

static const size_t FIRST_POSITION = 0;
static const size_t SECOND_POSITION = 1;
static const size_t THIRD_POSITION = 2;
static const size_t FOURTH_POSITION = 3;
static const size_t SEVENTH_POSITION = 6;

static const size_t DIRECTION_UP = 0;
static const size_t DIRECTION_RIGHT = 1;
static const size_t DIRECTION_DOWN = 2;
static const size_t DIRECTION_LEFT = 3;

static const size_t ROW_TWO_USER = 2;
static const size_t ROW_SEVEN_USER = 7;
static const size_t ROW_TWELVE_USER = 12;
static const size_t ROW_SEVENTEEN_USER = 17;
static const size_t ROW_TWENTYTWO_USER = 22;
static const size_t ROW_TWENTYSEVEN_USER = 27;
static const size_t ROW_THIRTYTWO_USER = 32;

static const size_t TOTAL_TREASURE_CARDS = 24;
static const size_t BOARD_HEIGHT_IN_CHAR = 35;
static const size_t BOARD_WIDTH_IN_CHAR = 63;


typedef struct _PreviousInsertion_
{
  std::string side_ = "";
  std::string position_ = "";
} PreviousInsertion;

typedef struct _UserInputArgs_
{
  inline static size_t current_player_;
  Tile* free_tile_;
  bool game_ends_ = false;
  bool show_treasure_ = false;
  bool hide_treasure_ = false;
  bool quit_ = false;
  bool show_free_tile_ = false;
  bool finish_ = false;
  bool gamefield_ = false;
  bool gamefield_on_ = true;
  bool was_insertion_ = false;
  bool already_moved_ = false;
  bool move_player_ = false;
  size_t direction_ = 0;
  size_t fields_ = 1;
  
  PreviousInsertion previous_insertion_;
} UserInputArgs;

typedef struct _PlayerLocation_
{
  char color_;
  size_t row_;
  size_t col_;
  bool stack_empty_ = false;
  inline static bool load_ = false;
  inline static size_t first_ = false;
} PlayerLocation;

class UserInput
{
  private:

    std::stringstream temp_stream_;
    size_t amount_of_players_;
    std::string input_value_;
    std::string temp_string_;
    std::vector<PlayerLocation> player_location_;
    UserInputArgs command_;
    std::vector<Player*> players_ = {};
    std::vector<std::vector<Tile*>> board_of_game_ = {};
    size_t nr_of_players_;
    
  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default UserInput constructor.
    ///
    /// 
    ///
    //
    UserInput();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// UserInput copy-constructor.
    ///
    /// 
    ///
    //
    UserInput(UserInput const&) = delete;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// UserInput destructor.
    ///
    /// 
    ///
    //
    ~UserInput();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the amount of players.
    ///
    /// @return size_t amount of players
    //
    size_t playerAmount();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Prints the actual player to terminal and reads the user input.
    ///
    /// @return void
    //
    void playerChoice();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if it´s a valid user input
    ///
    /// @return void
    //
    bool validInput();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the input value of the user.
    ///
    /// @return void
    //
    std::string getInputValue();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the input value of the user.
    ///
    /// @param input new string
    ///
    /// @return void
    //
    void setInputValue(std::string input);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the next player.
    ///
    /// @param player_count counter to next player
    ///
    /// @return void
    //
    void setNextPlayer(size_t player_count);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Removes all blank spaces.
    ///
    /// @return void
    //
    void RemoveExtraBlankspaces();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Creates a vector of words.
    ///
    /// @param help_vector Empty vector to fill 
    ///
    /// @return vector<std::string> new vector for the stored words
    //
    std::vector<std::string> createVectorOfWords(std::vector<std::string> help_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the user input args via command.
    ///
    /// @return UserInputArgs all needed values from user
    //
    UserInputArgs getCommand(){ return command_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the command to finish.
    ///
    /// @param boolean_variable True value
    ///
    /// @return void
    //
    void setCommandFinish(bool boolean_variable){ command_.finish_ = boolean_variable; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the command to quit.
    ///
    /// @param boolean_variable True value
    ///
    /// @return void
    //
    void setCommandQuit(bool boolean_variable){ command_.quit_ = boolean_variable; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks the user input in respect of allowed words or words combinations.
    ///
    /// @param words Words vector filled with strings
    ///
    /// @return bool true if user input is ok, otherwise false
    //
    bool checkUserInput(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Fills the players vector at user input class.
    ///
    /// @param input_vector Players
    ///
    /// @return void
    //
    void fillTheVector(std::vector<Player*> input_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the players.
    ///
    /// @return vector<Player*> vector of players as pointers
    //
    std::vector<Player*> getTheVector(){ return players_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if the players vector is empty.
    ///
    /// @return bool true if it is empty, otherwise false
    //
    bool isPlayersVectorEmpty();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the free tile.
    ///
    /// @param tile_object Free tile object
    ///
    /// @return void
    //
    void setCommandFreeTile(Tile* tile_object){ command_.free_tile_ = tile_object; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the free tile.
    ///
    /// @return void
    //
    Tile* getCommandFreeTile(){ return command_.free_tile_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Fills the board of the game with tiles.
    ///
    /// @param board 2-dim vector vector of tiles from the board
    ///
    /// @return void
    //
    void fillBoardOfGame(std::vector<std::vector<Tile*>> board){ board_of_game_ = board; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the board of the game with tiles.
    ///
    /// @return std::vector<std::vector<Tile*>> 2-dim vector vector of tiles from the board as pointers
    //
    std::vector<std::vector<Tile*>> getBoardOfGame(){ return board_of_game_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets the number of players.
    ///
    /// @param player_count amount of players
    ///
    /// @return void
    //
    void setNumberOfPlayers(size_t player_count){ nr_of_players_ = player_count; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the number of players.
    ///
    /// @return void
    //
    size_t getNumberOfPlayers(){ return nr_of_players_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Prints the board to termina.
    ///
    /// @param nr_of_players amount of players
    /// @param players_vector player vectors to access player information
    ///
    /// @return void
    //
    void printBoard(size_t nr_of_players, std::vector<Player*> players_vector);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Inserts the card in the board
    ///
    /// @param words user input
    /// @return void
    //
    void insertCardInBoard(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the show treasure argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if show treasure was valid and set to true, otherwise false
    //
    bool handleShowtreasure(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the hide treasure argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if hide treasure valid and was set to true, otherwise false
    //
    bool handleHideTreasure(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the free tile argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if free tile was valid and set to true, otherwise false
    //
    bool handleShowFreeTile(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the quit argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if quit was valid and set to true, otherwise false
    //
    bool handleQuit(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the finish argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if finish was valid and set to true, otherwise false
    //
    bool handleFinish(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the game field argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if game field was valid and set to true, otherwise false
    //
    bool handleGameField(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the rotation argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if rotation was valid and set to true, otherwise false
    //
    bool handleRotate(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the insertion argument from user.
    ///
    /// @param words user input
    /// @return bool returns true if insertion was valid and set to true, otherwise false
    //
    bool handleInsert(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// This checks if a move is possible on the board.
    ///
    /// @param direction Direction as size_t. 0 = up, 1 = right, 2 = down and 3 = left
    /// @param fields Amounts of fields to check
    /// @param row_act_pos Row actual position
    /// @param col_act_pos Column actual position
    ///
    /// @return true if its possible, otherwise false
    //
    bool checkMoveIsPossible(size_t direction, size_t fields, size_t row_act_pos, size_t col_act_pos);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// This checks if a tile is open in a specific direction.
    ///
    /// @param direction Direction as size_t. 0 = up, 1 = right, 2 = down and 3 = left
    /// @param row Row tile
    /// @param col Column tile
    ///
    /// @return true if it is open, otherwise false
    //
    bool checkIfOpen(size_t direction, size_t row, size_t col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if leaving a tile in a specific direction is possible.
    ///
    /// @param direction Direction as size_t. 0 = up, 1 = right, 2 = down and 3 = left
    /// @param row Row tile
    /// @param col Column tile
    ///
    /// @return true if it is possible, otherwise false
    //
    bool leavingPossible(size_t direction, size_t row, size_t col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Moves the position from on tile to another in a specific direction.
    ///
    /// @param direction Direction as size_t. 0 = up, 1 = right, 2 = down and 3 = left
    /// @param row_act_pos Reference to the row position 
    /// @param col_act_pos Reference to the column position
    ///
    /// @return void
    //
    void movePosition(size_t direction, size_t& row_act_player, size_t& col_act_player);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Helper for handlePlayerMovement() function.
    ///
    /// @param words user input
    ///
    /// @return bool returns true if movement was valid and set to true, otherwise false
    //
    bool helperHandlePlayerMovement(std::vector<std::string> user_input);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Handles the player movement.
    ///
    /// @param words user input
    ///
    /// @return bool returns true if movement was valid and set to true, otherwise false
    //
    bool handlePlayerMovement(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Pares direction from string to integer. 0 is up, 1 is right, 2 is down and 3 is left
    ///
    /// @param words direction
    ///
    /// @return bool returns true if parsing was valid and set to true, otherwise false
    //
    bool parseDirection(std::string words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Detects the player on the board and saves it in column and row of player location struct.
    ///
    /// @return void
    //
    void detectPlayer();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Reloads player loaction and saves it in column and row of player location struct.
    ///
    /// @return void
    //
    void loadPlayerLocation(bool reload, size_t row, size_t col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Moves player if its allowed to do so.
    ///
    /// @return void
    //
    void executeMovement();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Moves player from one tile to another.
    ///
    /// @param row row of the actual tile
    /// @param col col of the actual tile
    /// @param direction direction
    /// @param fields amount of fields
    ///
    /// @return void
    //
    void movePlayer(size_t row, size_t col, size_t direction, size_t fields);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sorts the players in the following way on a tile. Red, Yellow, Green and than Blue.
    ///
    /// @param player_info players vector
    ///
    /// @return bool returns true if parsing was valid and set to true, otherwise false
    //
    std::vector<Player*> sortPlayer(std::vector<Player*> player_info);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if the insertion commands are valid
    ///
    /// @param words user input
    ///
    /// @return bool returns true if insertion commands are valid, otherwise false
    //
    bool isAllowed(std::vector<std::string> words);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Inserts tile at the top at a specific row and column and prints the board.
    ///
    /// @param row_col specific row and column at the board
    ///
    /// @return void
    //
    void insertionTop(size_t row_col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Inserts tile at the bottom at a specific row and column and prints the board.
    ///
    /// @param row_col specific row and column at the board
    ///
    /// @return void
    //
    void insertionBottom(size_t row_col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Inserts tile at the left at a specific row and column and prints the board.
    ///
    /// @param row_col specific row and column at the board
    ///
    /// @return void
    //
    void insertionLeft(size_t row_col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Inserts tile at the right at a specific row and column and prints the board.
    ///
    /// @param row_col specific row and column at the board
    ///
    /// @return void
    //
    void insertionRight(size_t row_col);

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Checks if a player is back at the start tile.
    ///
    /// @return bool true if it is the case and the player which wins will be printed to board, otherwise false
    //
    bool playerBackAtOrigin();

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets the finish value of the player.
    ///
    /// @return bool true if it finished, otherwise false
    //
    bool getFinishValue(){return command_.finish_;}
};
#endif // A2_USERINPUT_HPP
