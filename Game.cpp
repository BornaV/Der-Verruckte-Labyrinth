//----------------------------------------------------------------------------------------------------------------------
// Player.cpp
//
// This is the imlementation of 
// the Player class methods, which 
// can be useful later on in the code
// where players start playing.
//
// Authors: 11804229
//          11814996
//          00713374
//----------------------------------------------------------------------------------------------------------------------
//

#include "Game.hpp"

#include <vector>
#include <string>
#include <iomanip>
#include <map>

///---------------------------------------------------------------------------------------------------------------------
void Game::initializeBoard(std::vector<std::vector<Tile*>> tiles_to_be_inserted)
{
  std::vector<Tile*> temporary_vector = {}; 
  for (size_t row = 0; row < HEIGHT_GAME; row++)
  {
    for (size_t column = 0; column < WIDTH_GAME; column++)
    {
      temporary_vector.push_back(tiles_to_be_inserted.at(row).at(column));    
    }
    game_board_.push_back(temporary_vector);
    temporary_vector.clear();
  }
}

///---------------------------------------------------------------------------------------------------------------------
void Game::deleteBoard(void)
{
  for (size_t row = 0; row < HEIGHT_GAME; row++)
  {
    for (size_t column = 0; column < WIDTH_GAME; column++)
    {
      delete game_board_.at(row).at(column);
    }
  }
  game_board_.clear();
}

///---------------------------------------------------------------------------------------------------------------------
std::string fromIntToString(size_t number)
{
  std::stringstream string_stream;
  string_stream << number;
  std::string final_string = string_stream.str();
  return final_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::vector<std::vector<char>> fillTheBoard(std::vector<std::vector<Tile*>>& game_board)
{
  std::vector<std::vector<char>> helper_vector = {};
  std::vector<char> first_row = {};
  std::vector<char> second_row = {};
  std::vector<char> third_row = {};
  std::vector<char> fourth_row = {};
  std::vector<char> fifth_row = {};
  std::string temporary_string;
  
  for (size_t row = 0; row < HEIGHT_GAME; row++)
  {
    for (size_t column = 0; column < WIDTH_GAME; column++)
    {
      temporary_string.clear();
      temporary_string = game_board.at(row).at(column)->getTileString();
      for (size_t col_counter = 0; col_counter < TILE_WIDTH; col_counter++)
      {
        first_row.push_back(temporary_string.at(col_counter));
        second_row.push_back(temporary_string.at(col_counter + TILE_WIDTH));
        third_row.push_back(temporary_string.at(col_counter + TILE_WIDTH * 2));
        fourth_row.push_back(temporary_string.at(col_counter + TILE_WIDTH * 3));
        fifth_row.push_back(temporary_string.at(col_counter + TILE_WIDTH * 4));
      }
    }

    helper_vector.push_back(first_row);
    helper_vector.push_back(second_row);
    helper_vector.push_back(third_row);
    helper_vector.push_back(fourth_row);
    helper_vector.push_back(fifth_row);
   
    first_row.clear();
    second_row.clear();
    third_row.clear();
    fourth_row.clear();
    fifth_row.clear();
  }

  return helper_vector;
}

///---------------------------------------------------------------------------------------------------------------------
void printLeft(size_t row)
{
  if (row != ROW_TWO && row != ROW_SEVEN && row != ROW_TWELVE && row != ROW_SEVENTEEN && 
      row != ROW_TWENTYTWO && row != ROW_TWENTYSEVEN && row != ROW_THIRTYTWO)
  {
    std::cout << std::setw(5);
  }  
  if (row == ROW_TWO)
  {
    std::cout << std::setw(4) << ONE_AS_STRING;
  }
  else if (row == ROW_TWELVE)
  {
    std::cout << std::setw(4) << THREE_AS_STRING;
  }
  else if (row == ROW_TWENTYTWO)
  {
    std::cout << std::setw(4) << FIVE_AS_STRING;
  }
  else if (row == ROW_THIRTYTWO)
  {
    std::cout << std::setw(4) << SEVEN_AS_STRING;
  }
  else if (row == ROW_SEVEN)
  {
    std::cout << LEFT_ARROW << TWO_AS_STRING;
  }
  else if (row == ROW_SEVENTEEN)
  {
    std::cout << LEFT_ARROW << FOUR_AS_STRING;
  }
  else if (row == ROW_TWENTYSEVEN)
  {
    std::cout << LEFT_ARROW << SIX_AS_STRING;
  }
  else
  {
    std::cout << std::setw(4);
  }
}

///---------------------------------------------------------------------------------------------------------------------
void printRight(size_t row)
{
  if (row == ROW_SEVEN)
  {
    std::cout << RIGHT_ARROW;
  }
  if (row == ROW_SEVENTEEN)
  {
    std::cout << RIGHT_ARROW;
  }
  if (row == ROW_TWENTYSEVEN)
  {
    std::cout << RIGHT_ARROW;
  }
}

///---------------------------------------------------------------------------------------------------------------------
void nrPlayersUp(size_t nr_players, std::vector<std::string> player_cards_vector, std::string cards)
{
  if (nr_players >= 2)
  {
    std::cout << std::left 
              << std::setw(17) << "Player Red(R)" 
              << std::setw(18) << LINE_VERTICAL 
              << std::setw(18) << LINE_VERTICAL
              << std::setw(5) << LINE_VERTICAL << "Player Yellow(Y)" 
              << std::endl;

    std::cout << std::left 
              << std::setw(17) << WORD_TREASURE + player_cards_vector.at(PLAYER_RED) + SLASH_BETWEEN_NUMBERS + cards 
              << std::setw(18) << UP_ARROW 
              << std::setw(18) << UP_ARROW 
              << std::setw(5) 
              << UP_ARROW << WORD_TREASURE + player_cards_vector.at(PLAYER_YELLOW) + SLASH_BETWEEN_NUMBERS + cards 
              << std::endl;
              
    std::cout << std::right;
    std::cout << std::setw(9) << ONE_AS_STRING << std::setw(9) << TWO_AS_STRING 
              << std::setw(9) << THREE_AS_STRING << std::setw(9) << FOUR_AS_STRING 
              << std::setw(9) << FIVE_AS_STRING << std::setw(9) << SIX_AS_STRING 
              << std::setw(9) << SEVEN_AS_STRING << std::setw(4) << EMPTY_STRING
              << std::endl;
  }
}

///---------------------------------------------------------------------------------------------------------------------
void nrPlayersDown(size_t nr_players, std::vector<std::string> player_cards_vector, std::string cards)
{
  if (nr_players == 3)
  {
    std::cout << std::left 
              << std::setw(17) << "Player Green(G)" 
              << std::setw(19) << DOWN_ARROW << std::setw(19) << DOWN_ARROW 
              << std::setw(0) << DOWN_ARROW 
              << std::endl;
    std::cout << std::left 
              << std::setw(17) 
              << WORD_TREASURE + player_cards_vector.at(PLAYER_GREEN) + SLASH_BETWEEN_NUMBERS + cards 
              << std::setw(18) << LINE_VERTICAL << std::setw(18) << LINE_VERTICAL 
              << std::setw(0) << LINE_VERTICAL;
  }
  if (nr_players == 4)
  {
    std::cout << std::left 
              << std::setw(17) << "Player Green(G)" 
              << std::setw(19) << DOWN_ARROW << std::setw(19) << DOWN_ARROW 
              << std::setw(5) << DOWN_ARROW << "Player Blue(B)" 
              << std::endl;
    std::cout << std::left 
              << std::setw(17) << WORD_TREASURE + player_cards_vector.at(PLAYER_GREEN) + SLASH_BETWEEN_NUMBERS + cards 
              << std::setw(18) << LINE_VERTICAL << std::setw(18) << LINE_VERTICAL  
              << std::setw(4) << LINE_VERTICAL 
                              << WORD_TREASURE + player_cards_vector.at(PLAYER_BLUE) + SLASH_BETWEEN_NUMBERS + cards; 
  }
  if (nr_players == 2)
  {
    std::cout << std::left 
              << std::setw(17) << EMPTY_STRING 
              << std::setw(19) << DOWN_ARROW 
              << std::setw(19) << DOWN_ARROW << std::setw(0) << DOWN_ARROW 
              << std::endl;
    std::cout << std::left 
              << std::setw(17) << EMPTY_STRING
              << std::setw(18) << LINE_VERTICAL << std::setw(18) << LINE_VERTICAL << std::setw(0) << LINE_VERTICAL;
  }
}

///---------------------------------------------------------------------------------------------------------------------
void Game::printBoard(size_t nr_players, std::vector<Player*> players_vector)
{
  std::vector<std::vector<char>> play_board = {};
  play_board = fillTheBoard(game_board_);

  size_t cards_per_person = TOTAL_CARDS_FOR_PLAYERS / nr_players;

  std::string cards = fromIntToString(cards_per_person);

  std::string player_cards = EMPTY_STRING;
  std::vector<std::string> player_cards_vector = {};

  for (size_t nr_cards_counter = 0; nr_cards_counter < nr_players; nr_cards_counter++)
  {
    player_cards = fromIntToString(players_vector.at(nr_cards_counter)->getNrFoundTreasures());
    player_cards_vector.push_back(player_cards);
    player_cards = EMPTY_STRING;
  }

  nrPlayersUp(nr_players, player_cards_vector, cards);

  for (size_t row = 0; row < BOARD_HEIGHT_IN_CHARACTERS; row++)
  {
    printLeft(row);

    std::cout << EMPTY_STRING;
    for (size_t column = 0; column < BOARD_WIDTH_IN_CHARACTERS; column++)
    {
      if (play_board.at(row).at(column) == BLACK_BOX_CHARACTER)
      {
        std::cout << BLACK_BLOCK_GAME;
      }
      else
      {
        std::cout << play_board.at(row).at(column);
      }
    }
    
    printRight(row);

    std::cout << std::endl;
  }

  nrPlayersDown(nr_players, player_cards_vector, cards);
}

///---------------------------------------------------------------------------------------------------------------------
void Game::deleteObjects(std::vector<Tile*>& all_tiles, std::vector<Treasure*>& reserve_treasures_vector, 
                         std::vector<Player*>& players_vector, size_t player_count)
{
  for (Tile* element : all_tiles)
  {
    delete element;
  }
  for (size_t counter = 0; counter < reserve_treasures_vector.size(); counter++)
  {
    delete reserve_treasures_vector[counter];
  }
  for (size_t counter = 0; counter < player_count; counter++)
  {
    delete players_vector[counter];
  }
}

///---------------------------------------------------------------------------------------------------------------------
void Game::createTreasures(std::vector<Treasure*>& all_treasures_vector, 
                           std::vector<Treasure*>& reserve_treasures_vector)
{
  std::map<size_t,std::string> input_treasures = {
    {1,"Totenkopf"},
    {2,"Schwert"},
    {3,"Goldsack"},
    {4,"Schlüsselbund"},
    {5,"Sombrero"},
    {6,"Ritterhelm"},
    {7,"Buch"},
    {8,"Krone"},
    {9,"Schatztruhe"},
    {10,"Kerzenleuchte"},
    {11,"Schatzkarte"},
    {12,"Goldring"},
    {13,"Eule"},
    {14,"Hofnarr"},
    {15,"Eidechse"},
    {16,"Käfer"},
    {17,"Flaschengeist"},
    {18,"Kobold"},
    {19,"Schlange"},
    {20,"Geist"},
    {21,"Fledermaus"},
    {22,"Spinne"},
    {23,"Ratte"},
    {24,"Motte"}
  };
  for (auto& element : input_treasures)
  {
    Treasure* treasure = new Treasure{element.second, element.first};
    all_treasures_vector.push_back(treasure);
    reserve_treasures_vector.push_back(treasure);
  }
}

///---------------------------------------------------------------------------------------------------------------------
std::vector<std::string> Game::getPlayersColour()
{
  std::vector<std::string> input_players = {{"R"}, {"Y"}, {"G"}, {"B"}}; 
  return input_players;
}

///---------------------------------------------------------------------------------------------------------------------
void Game::createPlayers(std::vector<Player*>& players_vector, size_t player_count)
{
  std::vector<std::string> input_players = getPlayersColour();
  
  for (size_t player_index = 0; player_index < player_count; player_index++)
  {
    Player* player = new Player{input_players.at(player_index)};
    players_vector.push_back(player);
  }
}

///---------------------------------------------------------------------------------------------------------------------
void Game::createFixtiles(std::vector<Tile*>& fixed_tiles, std::vector<Treasure*>& reserve_treasures_vector, 
                          std::vector<Player*>& players_vector, size_t player_count, std::vector<Tile*>& start_tiles,
                          std::vector<Tile*>& all_tiles)
{
  std::vector<std::string> input_players = getPlayersColour();
  int position_treasures = 0;
  int position_player = 0;
  for (size_t start = 0; start < NUMBER_OF_FIXEDTILES; start++)
  {
    if (start == FIRST_FIXEDTILE || start == SECOND_FIXEDTILE || 
        start == THIRD_FIXEDTILE || start == FOURTH_FIXEDTILE)
    {
      Tile* tile = new StartTile{TileType::L, Rotation::DEG0, input_players.at(position_player)};
      position_player++;
      start_tiles.push_back(tile);
      fixed_tiles.push_back(tile);
      all_tiles.push_back(tile);
    }
    else
    {
      Tile* tile = new TreasureTile{TileType::T, (Rotation)0, *reserve_treasures_vector.at(position_treasures)};
      position_treasures++;
      fixed_tiles.push_back(tile);
      all_tiles.push_back(tile);
    }
  }

  for (size_t start_tile_counter = 0; start_tile_counter < NUMBER_OF_STARTTILES; start_tile_counter++)
  {
    if (start_tile_counter < player_count)
    {
      start_tiles.at(start_tile_counter)->pushPlayerToPlayersVector(players_vector.at(start_tile_counter));
    }
  }
  std::vector<Rotation> rotation_fixed_tiles = {
    Rotation::DEG270,
    Rotation::DEG0,
    Rotation::DEG0,
    Rotation::DEG180,
    Rotation::DEG90,
    Rotation::DEG90,
    Rotation::DEG0,
    Rotation::DEG270,
    Rotation::DEG90,
    Rotation::DEG180,
    Rotation::DEG270,
    Rotation::DEG270,
    Rotation::DEG0,
    Rotation::DEG180,
    Rotation::DEG180,
    Rotation::DEG90
  }; 
  for (size_t start = 0; start < NUMBER_OF_FIXEDTILES; start++)
  {
    fixed_tiles.at(start)->setRotation(rotation_fixed_tiles.at(start));
  }
}

///---------------------------------------------------------------------------------------------------------------------
void Game::createFlextiles(std::vector<Tile*>& all_tiles, std::vector<Tile*>& flex_tiles, 
                           std::vector<Treasure*>& reserve_treasures_vector)
{
  int position_treasures = 12;
  for (size_t start = 0; start < NUMBER_OF_FLEXIBLETILES; start++)
  {
    if (start < LAST_NORMALTILE_L_TYPE) 
    {
      Tile* tile = new NormalTile{TileType::L, Rotation::DEG0};
      flex_tiles.push_back(tile);
      all_tiles.push_back(tile);
    }
    else if (start < LAST_NORMALTILE_I_TYPE) 
    {
      Tile* tile = new NormalTile{TileType::I, Rotation::DEG0};
      flex_tiles.push_back(tile);
      all_tiles.push_back(tile);
    }
    else 
    {
      Tile* tile = new TreasureTile{TileType::T, Rotation::DEG0, *reserve_treasures_vector.at(position_treasures)};
      flex_tiles.push_back(tile);
      all_tiles.push_back(tile);
      position_treasures++;
    }
  }
}

///---------------------------------------------------------------------------------------------------------------------
void Game::fillBoardWithTiles(std::vector<std::vector<Tile*>>& board, std::vector<Tile*>& fixed_tiles,
                              std::vector<Tile*>& flex_tiles, Oop::Random& random)
{
  size_t fix_counter = 0;
  size_t flex_counter = 0;
  std::vector<Tile*> temporary = {};
  size_t r_position;
  size_t r_orientation;
  size_t new_r_position;

  for (size_t row = 0; row < HEIGHT_GAME; row++)
  {
    for (size_t column = 0; column < WIDTH_GAME; column++)
    {
      if (row % 2 == 0 && column % 2 == 0 && fixed_tiles.empty() == false)
      {
        temporary.push_back(fixed_tiles.at(fix_counter));
        fix_counter++;
      }
      else 
      {
        r_position = random.getRandomCard(flex_tiles.size());
        r_orientation = random.getRandomOrientation();
        new_r_position = r_position - 1;
        
        if (r_orientation == ORIENTATION_ZERO)
        {
          flex_tiles.at(new_r_position)->setRotation(Rotation::DEG0);
        }
        if (r_orientation == ORIENTATION_NINETY)
        {
          flex_tiles.at(new_r_position)->setRotation(Rotation::DEG90);
        }
        if (r_orientation == ORIENTATION_ONEEIGHTY)
        {
          flex_tiles.at(new_r_position)->setRotation(Rotation::DEG180);
        }
        if (r_orientation == ORIENTATION_TWOSEVENTY)
        {
          flex_tiles.at(new_r_position)->setRotation(Rotation::DEG270);
        }

        temporary.push_back(flex_tiles.at(new_r_position));        
        flex_tiles.erase(flex_tiles.begin() + new_r_position);
        flex_counter++;
      }
    }
    board.push_back(temporary);
    temporary.clear();
  }
}

///---------------------------------------------------------------------------------------------------------------------
size_t Game::run(size_t player_count, UserInput& user_input, Oop::Random& random)
{
  std::vector<Treasure*> all_treasures_vector = {};
  std::vector<Treasure*> reserve_treasures_vector = {};
  createTreasures(all_treasures_vector, reserve_treasures_vector);
  
  std::vector<Player*> players_vector = {};
  createPlayers(players_vector, player_count);  
  
  size_t random_index;

  std::vector<Tile*> fixed_tiles = {};
  std::vector<Tile*> flex_tiles = {};

  std::vector<std::string> input_players = getPlayersColour();
  std::vector<Tile*> start_tiles = {};
  std::vector<Tile*> all_tiles = {};
  createFixtiles(fixed_tiles, reserve_treasures_vector, players_vector, player_count, start_tiles, all_tiles);
  createFlextiles(all_tiles, flex_tiles, reserve_treasures_vector);

  std::vector<std::vector<Tile*>> board = {};
  fillBoardWithTiles(board, fixed_tiles, flex_tiles, random);

  initializeBoard(board); 
  printBoard(player_count, players_vector);
  std::cout << std::endl;

  while(all_treasures_vector.empty() == false)
  {
    for (size_t i_player = 0; i_player < player_count; i_player++)        
    {
      random_index = random.getRandomCard(all_treasures_vector.size()); 
      Treasure* treasure = all_treasures_vector.at(random_index - 1);      
      players_vector.at(i_player)->pushBackTreasureStack(treasure);  
      players_vector.at(i_player)->pushToVector(treasure); 
      all_treasures_vector.erase(all_treasures_vector.begin() + random_index - 1); 
    }
  }
  
  user_input.setCommandFreeTile(flex_tiles.at(FIRST_FLEXTILE));

  user_input.fillBoardOfGame(board); 
  user_input.fillTheVector(players_vector); 

  user_input.getCommand().current_player_ = 1;

  while(player_count < MAXIMUM_NR_OF_PLAYERS + 1)
  {
    user_input.playerChoice();
    if (user_input.getCommand().quit_ == false)
    {
      user_input.setNextPlayer(player_count);
    }
    else
    {
      break;
    }
    if (user_input.getCommand().game_ends_ == true)
    {
      break;
    }
  }

  deleteObjects(all_tiles, reserve_treasures_vector, players_vector, player_count);

  return 0;
}