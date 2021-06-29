//----------------------------------------------------------------------------------------------------------------------
// UserInput.cpp
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

#include "UserInput.hpp"
#include "TreasureTile.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

///---------------------------------------------------------------------------------------------------------------------
UserInput::UserInput() {}

///---------------------------------------------------------------------------------------------------------------------
UserInput::~UserInput() {}

///---------------------------------------------------------------------------------------------------------------------
bool checkValidNumberOfPlayers(std::string input)
{
  if (input.size() == EQUAL_ONE)
  {
    if (input.at(FIRST_POSITION) < '2' || input.at(FIRST_POSITION) > '4')
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
size_t UserInput::playerAmount()
{
  std::stringstream string_to_int;
  std::cout << "Welcome to the Wild OOP Labyrinth!!!\n";

  do
  {
    std::cout << "Player Count (2-4): ";
    getline(std::cin, input_value_);
    RemoveExtraBlankspaces();
    if (checkValidNumberOfPlayers(input_value_) == false)
    {
      std::cout << "Wrong Input only a Number from 2 to 4 is allowed!\n";
    }

  } while (checkValidNumberOfPlayers(input_value_) == false);

  string_to_int << input_value_;
  string_to_int >> amount_of_players_;
  return amount_of_players_;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::fillTheVector(std::vector<Player*> input_vector)
{
  for (size_t input_vector_counter = START; input_vector_counter < input_vector.size(); input_vector_counter++)
  {
    players_.push_back(input_vector.at(input_vector_counter));
  }
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleShowtreasure(std::vector<std::string> user_input)
{
  if (user_input.size() == EQUAL_ONE)
  {
    if (player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).stack_empty_ == true)
    {
      command_.show_free_tile_ = true;
      if (command_.gamefield_on_ == false)
      {
        std::cout << ALL_TREASURES_FOUND << std::endl;
        return true;
      }
      printBoard(nr_of_players_, players_);
      return true;
    }
    if (players_.at(UserInputArgs::current_player_ - REDUCE_ONE)->getStackSize() != EQUAL_ZERO)
    {
      command_.show_treasure_ = true;
      if (command_.gamefield_on_ == false)
      {
        std::cout << CURRENT_TREASURE 
                  << players_.at(UserInputArgs::current_player_ - REDUCE_ONE)->getCurrentTreasureName()
                  << ID_OF_TREASURE 
                  << players_.at(UserInputArgs::current_player_ - REDUCE_ONE)->getCurrentTreasureId() << "\n";
        return true;
      }
      printBoard(nr_of_players_, players_);
      return true;
    }
  }
  else if (user_input.size() != EQUAL_ONE)
  {
    command_.show_treasure_ = false;
    std::cout << COMMAND_DOES_NOT_TAKE_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleHideTreasure(std::vector<std::string> user_input)
{
  if (user_input.size() == EQUAL_ONE)
  {
    command_.hide_treasure_ = true;
    std::cout << "\x1b[2J";
    command_.show_treasure_ = false;
    printBoard(nr_of_players_, players_);
    return true;
  }
  else if (user_input.size() != EQUAL_ONE)
  {
    command_.hide_treasure_ = false;
    std::cout << COMMAND_DOES_NOT_TAKE_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::isPlayersVectorEmpty()
{
  if(players_.empty() == true)
  {
    return true;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
void printFreeTile(std::string one_dimensional_tile)
{
  size_t begin = START;
  std::cout << FREE_TILE;
  for (size_t row_count = begin; row_count <= begin + END_TILE; row_count++)
  {
    if (one_dimensional_tile.at(row_count) == (char) NUMBER_219)
    {
      std::cout << BLACK_BLOCK;
    }
    else
    {
      std::cout << one_dimensional_tile.at(row_count);
    }
    if (row_count == begin + END_TILE && row_count != one_dimensional_tile.size() - REDUCE_ONE)
    {
      begin += 9;
      std::cout << std::endl;
    }
    else if (row_count == one_dimensional_tile.size() - REDUCE_ONE)
    {
      std::cout << std::endl;
      break;
    }
  }
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleShowFreeTile(std::vector<std::string> user_input)
{
  if (user_input.size() == EQUAL_ONE)
  {
    command_.show_free_tile_ = true;
    printFreeTile(getCommandFreeTile()->getTileString());
    return true;
  }
  else if (user_input.size() != EQUAL_ONE)
  {
    command_.show_free_tile_ = false;
    std::cout << COMMAND_DOES_NOT_TAKE_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleQuit(std::vector<std::string> user_input)
{
  if (user_input.size() == EQUAL_ONE)
  {
    command_.quit_ = true;
    return true;
  }
  else if (user_input.size() != EQUAL_ONE)
  {
    command_.quit_ = false;
    std::cout << COMMAND_DOES_NOT_TAKE_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::playerBackAtOrigin()
{
  char temp_color = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).color_;
  size_t temp_row = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).row_;
  size_t temp_col = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).col_;
  bool temp_stack = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).stack_empty_;
  if (temp_color == FIRST_LETTER_COLOR_RED && temp_row == EQUAL_ZERO && temp_col == EQUAL_ZERO && temp_stack == true)
  {
    std::cout << THE_PLAYER << "RED" << WON_THE_GAME;
    command_.game_ends_ = true;
    return true;
  }
  else if (temp_color == FIRST_LETTER_COLOR_YELLOW && temp_row == EQUAL_ZERO && 
           temp_col == EQUAL_SIX && temp_stack == true)
  {
    std::cout << THE_PLAYER << "YELLOW" << WON_THE_GAME;
    command_.game_ends_ = true;
    return true;
  }
  else if (temp_color == FIRST_LETTER_COLOR_GREEN && temp_row == EQUAL_SIX && 
           temp_col == EQUAL_ZERO && temp_stack == true)
  {
    std::cout << THE_PLAYER << "GREEN" << WON_THE_GAME;
    command_.game_ends_ = true;
    return true;
  }
  else if (temp_color == FIRST_LETTER_COLOR_BLUE && temp_row == EQUAL_SIX && 
           temp_col == EQUAL_SIX && temp_stack == true)
  {
    std::cout << THE_PLAYER << "BLUE" << WON_THE_GAME;
    command_.game_ends_ = true;
    return true;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleFinish(std::vector<std::string> user_input)
{
  char temp_color = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).color_;
  size_t temp_row = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).row_;
  size_t temp_col = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).col_;
  std::vector<Player*> temp_player_info = board_of_game_.at(temp_row).at(temp_col)->getPlayers();

  TreasureTile* board_at_location = dynamic_cast<TreasureTile*>(board_of_game_.at(temp_row).at(temp_col));

  if (user_input.size() == EQUAL_ONE)
  {
    if (command_.was_insertion_ == false)
    {
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
      << std::endl;
      return false;
    }

    command_.show_treasure_ = false;
    PlayerLocation::first_ = 0;
    if (playerBackAtOrigin() == true){return true;}
    command_.finish_ = true;

    if (board_at_location)
    {
      size_t position = START;
      for (size_t player_at = START; player_at < board_at_location->getPlayersVectorSize(); player_at++)
      {
        if (temp_player_info.at(player_at)->getColor()[FIRST_POSITION] == temp_color)
        {
          position = player_at;
          break;
        }
      }

      if (board_at_location->getCollected() == false &&
          temp_player_info.at(position)->getCurrentTreasureName() == board_at_location->getTreasure().getName())
      {
        board_at_location->collectTreasure();
        temp_player_info.at(position)->popFrontTreasureStack();
        if (temp_player_info.at(position)->stackEmpty() == true)
        {
          player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).stack_empty_ = true;
        }
      }
    }
    setNextPlayer(amount_of_players_);
    printBoard(nr_of_players_, players_);
    return true;
  }
  else if (user_input.size() != EQUAL_ONE)
  {
    command_.finish_ = false;
    std::cout << COMMAND_DOES_NOT_TAKE_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleGameField(std::vector<std::string> user_input)
{
  if (user_input.size() == EQUAL_ONE)
  {
    command_.gamefield_ = true;
    printBoard(nr_of_players_, players_);
    return true;
  }
  else if (user_input.size() == 2)
  {
    if (user_input.at(SECOND_POSITION) == "on")
    {
      command_.gamefield_on_ = true;
    }
    else if (user_input.at(SECOND_POSITION) == "off")
    {
      command_.gamefield_on_ = false;
    }
    else
    {
      std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(SECOND_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
  }
  else
  {
    std::cout << WRONG_ARGUMENTS << std::endl;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleRotate(std::vector<std::string> user_input)
{
  if (user_input.size() == 2)
  {
    if (command_.was_insertion_ == true)
    {
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
                << std::endl;
      return false;
    }
    int rotation = static_cast<int>(command_.free_tile_->getRotation());
    if (user_input.at(SECOND_POSITION) == LEFT_LONG || user_input.at(SECOND_POSITION) == LEFT_SHORT)
    {
      if (rotation < 3)
      {
        rotation++;
        command_.free_tile_->setRotation(static_cast<Rotation>(rotation));
      }
      else
      {
        rotation = 0;
        command_.free_tile_->setRotation(static_cast<Rotation>(rotation));
      }
      return true;
    }
    else if (user_input.at(SECOND_POSITION) == RIGHT_LONG || user_input.at(SECOND_POSITION) == RIGHT_SHORT)
    {
      if (rotation > 0)
      {
        rotation--;
        command_.free_tile_->setRotation(static_cast<Rotation>(rotation));
      }
      else
      {
        rotation = 3;
        command_.free_tile_->setRotation(static_cast<Rotation>(rotation));
      }
      return true;
    }
    else
    {
      std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(SECOND_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
  }
  else
  {
    std::cout << WRONG_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool checkIfInteger(std::string to_be_checked)
{
  for (size_t string_counter = START; string_counter < to_be_checked.size(); string_counter++)
  {
    if ((string_counter == EQUAL_ZERO) && 
        (to_be_checked.at(string_counter) <= '0' || to_be_checked.at(string_counter) > '9'))
    {
      return false;
    }
    if (to_be_checked.at(string_counter) < '0' || to_be_checked.at(string_counter) > '9')
    {
      return false;
    }
  }
  return true;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::insertionTop(size_t row_col)
{
  Tile* poped_tile = nullptr;
  if (board_of_game_.at(SEVENTH_POSITION).at(row_col - REDUCE_ONE)->checkIfPlayersVectorEmpty() == false)
  {
    command_.free_tile_->setPlayers(board_of_game_.at(SEVENTH_POSITION).at(row_col - REDUCE_ONE)->getPlayers());
    board_of_game_.at(SEVENTH_POSITION).at(row_col - REDUCE_ONE)->clearPlayersVector();
  }
  poped_tile = board_of_game_.at(SEVENTH_POSITION).at(row_col - REDUCE_ONE);
  for (size_t row_col_counter = SEVENTH_POSITION; row_col_counter >= EQUAL_ONE; row_col_counter--)
  {
    board_of_game_.at(row_col_counter).at(row_col - REDUCE_ONE) = board_of_game_.at(row_col_counter - REDUCE_ONE).at
    (row_col - REDUCE_ONE);
  }
  board_of_game_.at(FIRST_POSITION).at(row_col - REDUCE_ONE) = command_.free_tile_;
  command_.free_tile_ = poped_tile;
  poped_tile = nullptr;
  printBoard(nr_of_players_, players_);
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::insertionBottom(size_t row_col)
{
  Tile* poped_tile = nullptr;
  if (board_of_game_.at(FIRST_POSITION).at(row_col - REDUCE_ONE)->checkIfPlayersVectorEmpty() == false)
  {
    command_.free_tile_->setPlayers(board_of_game_.at(FIRST_POSITION).at(row_col - REDUCE_ONE)->getPlayers());
    board_of_game_.at(FIRST_POSITION).at(row_col - REDUCE_ONE)->clearPlayersVector();
  }
  poped_tile = board_of_game_.at(FIRST_POSITION).at(row_col - REDUCE_ONE);
  for (size_t row_col_counter = START; row_col_counter < SEVENTH_POSITION; row_col_counter++)
  {
    board_of_game_.at(row_col_counter).at(row_col - REDUCE_ONE) = board_of_game_.at(row_col_counter + REDUCE_ONE).at
    (row_col - REDUCE_ONE);
  }
  board_of_game_.at(SEVENTH_POSITION).at(row_col - REDUCE_ONE) = command_.free_tile_;
  command_.free_tile_ = poped_tile;
  poped_tile = nullptr;
  printBoard(nr_of_players_, players_);
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::insertionLeft(size_t row_col)
{
  Tile* poped_tile = nullptr;
  if (board_of_game_.at(row_col - REDUCE_ONE).at(SEVENTH_POSITION)->checkIfPlayersVectorEmpty() == false)
  {
    command_.free_tile_->setPlayers(board_of_game_.at(row_col - REDUCE_ONE).at(SEVENTH_POSITION)->getPlayers());
    board_of_game_.at(row_col - REDUCE_ONE).at(SEVENTH_POSITION)->clearPlayersVector();
  }
  poped_tile = board_of_game_.at(row_col - REDUCE_ONE).at(SEVENTH_POSITION);
  for (size_t row_col_counter = SEVENTH_POSITION; row_col_counter >= EQUAL_ONE; row_col_counter--)
  {
    board_of_game_.at(row_col - REDUCE_ONE).at(row_col_counter) = board_of_game_.at(row_col - REDUCE_ONE).at
    (row_col_counter - REDUCE_ONE);
  }
  board_of_game_.at(row_col - REDUCE_ONE).at(FIRST_POSITION) = command_.free_tile_;
  command_.free_tile_ = poped_tile;
  poped_tile = nullptr;
  printBoard(nr_of_players_, players_);
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::insertionRight(size_t row_col)
{
  Tile* poped_tile = nullptr;
  if (board_of_game_.at(row_col - REDUCE_ONE).at(FIRST_POSITION)->checkIfPlayersVectorEmpty() == false)
  {
    command_.free_tile_->setPlayers(board_of_game_.at(row_col - REDUCE_ONE).at(FIRST_POSITION)->getPlayers());
    board_of_game_.at(row_col - REDUCE_ONE).at(FIRST_POSITION)->clearPlayersVector();
  }
  poped_tile = board_of_game_.at(row_col - REDUCE_ONE).at(FIRST_POSITION);
  for (size_t row_col_counter = START; row_col_counter < SEVENTH_POSITION; row_col_counter++)
  {
    board_of_game_.at(row_col - REDUCE_ONE).at(row_col_counter) = board_of_game_.at(row_col - REDUCE_ONE).at
    (row_col_counter + REDUCE_ONE);
  }
  board_of_game_.at(row_col - REDUCE_ONE).at(SEVENTH_POSITION) = command_.free_tile_;
  command_.free_tile_ = poped_tile;
  poped_tile = nullptr;
  printBoard(nr_of_players_, players_);
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::insertCardInBoard(std::vector<std::string> user_input)
{
  PlayerLocation::load_ = false;
  std::stringstream string_to_int;
  size_t row_col;
  string_to_int << user_input.at(THIRD_POSITION);
  string_to_int >> row_col;

  if (user_input.at(SECOND_POSITION) == TOP_LONG || user_input.at(SECOND_POSITION) == TOP_SHORT)
  {
    insertionTop(row_col);
  }
  else if (user_input.at(SECOND_POSITION) == BOTTOM_LONG || user_input.at(SECOND_POSITION) == BOTTOM_SHORT)
  {
    insertionBottom(row_col);
  }
  else if (user_input.at(SECOND_POSITION) == LEFT_LONG || user_input.at(SECOND_POSITION) == LEFT_SHORT)
  {
    insertionLeft(row_col);
  }
  else if (user_input.at(SECOND_POSITION) == RIGHT_LONG || user_input.at(SECOND_POSITION) == RIGHT_SHORT)
  {
    insertionRight(row_col);
  }
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::isAllowed(std::vector<std::string> user_input)
{
  if ((user_input.at(SECOND_POSITION) == TOP_LONG || user_input.at(SECOND_POSITION) == TOP_SHORT) &&
      (command_.previous_insertion_.side_ == BOTTOM_LONG || command_.previous_insertion_.side_ == BOTTOM_SHORT) &&
      (user_input.at(THIRD_POSITION) == command_.previous_insertion_.position_))
  {
    return false;
  }
  else if ((user_input.at(SECOND_POSITION) == BOTTOM_LONG || user_input.at(SECOND_POSITION) == BOTTOM_SHORT) &&
           (command_.previous_insertion_.side_ == TOP_LONG || command_.previous_insertion_.side_ == TOP_SHORT) &&
           (user_input.at(THIRD_POSITION) == command_.previous_insertion_.position_))
  {
    return false;
  }
  else if ((user_input.at(SECOND_POSITION) == LEFT_LONG || user_input.at(SECOND_POSITION) == LEFT_SHORT) &&
           (command_.previous_insertion_.side_ == RIGHT_LONG || command_.previous_insertion_.side_ == RIGHT_SHORT) &&
           (user_input.at(THIRD_POSITION) == command_.previous_insertion_.position_))
  {
    return false;
  }
  else if ((user_input.at(SECOND_POSITION) == RIGHT_LONG || user_input.at(SECOND_POSITION) == RIGHT_SHORT) &&
           (command_.previous_insertion_.side_ == LEFT_LONG || command_.previous_insertion_.side_ == LEFT_SHORT) &&
           (user_input.at(THIRD_POSITION) == command_.previous_insertion_.position_))
  {
    return false;
  }
  return true;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handleInsert(std::vector<std::string> user_input)
{
  if (user_input.size() == 3)
  {
    size_t temp_storage_of_input;
    std::stringstream(user_input.at(THIRD_POSITION)) >> temp_storage_of_input;
    if (user_input.at(SECOND_POSITION) != TOP_LONG && user_input.at(SECOND_POSITION) != TOP_SHORT && user_input.at
       (SECOND_POSITION) != BOTTOM_LONG && user_input.at(SECOND_POSITION) != BOTTOM_SHORT && user_input.at
       (SECOND_POSITION) != RIGHT_LONG && user_input.at(SECOND_POSITION) != RIGHT_SHORT && user_input.at
       (SECOND_POSITION) != LEFT_LONG && user_input.at(SECOND_POSITION) != LEFT_SHORT)
    {
      if (command_.was_insertion_ == true)
      {
        std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
                  << std::endl;
        return false;
      }
      std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(SECOND_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
    else if (checkIfInteger(user_input.at(THIRD_POSITION)) == false || 
             user_input.at(THIRD_POSITION)[FIRST_POSITION] >= 7+48)
    {
      std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(THIRD_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
    else if ((checkIfInteger(user_input.at(THIRD_POSITION)) == true) &&
             (user_input.at(THIRD_POSITION) != TWO && user_input.at(THIRD_POSITION) != FOUR && user_input.at
             (THIRD_POSITION) != SIX))
    {      
      if (temp_storage_of_input > 7)
      {
        std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(THIRD_POSITION) << QUOTATION_MARK 
                  << std::endl;
        return false;
      }
      std::cout << INVALID_POSITION << std::endl;
      return false;
    }
    else if (isAllowed(user_input) == false)
    {
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << SPACE << user_input.at(SECOND_POSITION) << SPACE;
      std::cout << user_input.at(THIRD_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED << std::endl;
      return false;
    }
    command_.previous_insertion_.side_ = user_input.at(SECOND_POSITION);
    command_.previous_insertion_.position_ = user_input.at(THIRD_POSITION);
    if (command_.was_insertion_ == false)
    {
      insertCardInBoard(user_input);
      PlayerLocation::load_ = false;
      command_.was_insertion_ = true;
    }
    else
    {
      if (command_.was_insertion_ == true)
      {
        std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
                  << std::endl;
        return false;
      }
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << SPACE << user_input.at(SECOND_POSITION) << SPACE;
      std::cout << user_input.at(THIRD_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED << std::endl;
      return false;
    }
    PlayerLocation::load_ = false;
    return true;
  }
  else
  {
    if (command_.was_insertion_ == true)
    {
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
                << std::endl;
      return false;
    }
    std::cout << WRONG_ARGUMENTS << std::endl;
    return false;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::checkMoveIsPossible(size_t direction, size_t fields, size_t row_act_pos, size_t col_act_pos)
{
  while (fields != EQUAL_ZERO)
  {
    size_t row_new_pos;
    size_t col_new_pos;
    switch (direction)
    {
      case 0:
        row_new_pos = row_act_pos - REDUCE_ONE;
        col_new_pos = col_act_pos;
        break;
      case 1:
        row_new_pos = row_act_pos;
        col_new_pos = col_act_pos + ADD_ONE;
        break;
      case 2:
        row_new_pos = row_act_pos + ADD_ONE;
        col_new_pos = col_act_pos;
        break;
      case 3:
        row_new_pos = row_act_pos;
        col_new_pos = col_act_pos - REDUCE_ONE;
        break;
    }
    if (row_new_pos < HEIGHT && col_new_pos < WIDTH)
    {
      if (leavingPossible(direction, row_act_pos, col_act_pos))
      {
        if (checkIfOpen(direction, row_new_pos, col_new_pos))
        {
          movePosition(direction, row_act_pos, col_act_pos);
          fields--;
          row_act_pos = row_new_pos;
          col_act_pos = col_new_pos;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  return true;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::leavingPossible(size_t direction, size_t row, size_t col)
{
  Tile* board_at_location = board_of_game_.at(row).at(col);
  switch (direction)
  {
    case 0:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG0) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG0))
      {
        return true;
      }
      break;
    case 1:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG270) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG270))
      {
        return true;
      }
      break;
    case 2:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG180) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG180))
      {
        return true;
      }
      break;
    case 3:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG90) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG90))
      {
        return true;
      }
      break;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::checkIfOpen(size_t direction, size_t row, size_t col)
{
  Tile* board_at_location = board_of_game_.at(row).at(col);
  switch (direction)
  {
    case 0:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG180) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG180))
      {
        return true;
      }
      break;
    case 1:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG90) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG90))
      {
        return true;
      }
      break;
    case 2:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
            board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::L &&
            board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::T &&
            board_at_location->getRotation() != Rotation::DEG0) ||
          (board_at_location->getType() == TileType::I &&
            board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::I &&
            board_at_location->getRotation() == Rotation::DEG180) ||
          (board_at_location->getType() == TileType::U &&
            board_at_location->getRotation() == Rotation::DEG0))
      {
        return true;
      }
      break;
    case 3:
      if (board_at_location->getType() == TileType::X ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG0) ||
          (board_at_location->getType() == TileType::L &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::T &&
           board_at_location->getRotation() != Rotation::DEG270) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG90) ||
          (board_at_location->getType() == TileType::I &&
           board_at_location->getRotation() == Rotation::DEG270) ||
          (board_at_location->getType() == TileType::U &&
           board_at_location->getRotation() == Rotation::DEG270))
      {
        return true;
      }
      break;
  }
  return false;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::movePosition(size_t direction, size_t& row_act_pos, size_t& col_act_pos)
{
  switch (direction)
  {
    case 0:
      row_act_pos = row_act_pos - REDUCE_ONE;
      break;
    case 1:
      col_act_pos = col_act_pos + ADD_ONE;
      break;
    case 2:
      row_act_pos = row_act_pos + ADD_ONE;
      break;
    case 3:
      col_act_pos = col_act_pos - REDUCE_ONE;
      break;
  }
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::helperHandlePlayerMovement(std::vector<std::string> user_input)
{
  if (user_input.at(FIRST_POSITION) == "go")
  {
    if (user_input.size() == EQUAL_ONE)
    {
      std::cout << WRONG_ARGUMENTS << std::endl;
      return false;
    }
    if (parseDirection(user_input.at(SECOND_POSITION)) == false)
    {
      std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(SECOND_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
    if (user_input.size() == 2)
    {
      command_.fields_ = EQUAL_ONE;
      executeMovement();
    }
    else if (user_input.at(THIRD_POSITION)[FIRST_POSITION] > 0 + 48 && 
             user_input.at(THIRD_POSITION)[FIRST_POSITION] < 7 + 48 && 
             user_input.at(THIRD_POSITION).size() == EQUAL_ONE)
    {
      command_.fields_ = user_input.at(THIRD_POSITION)[FIRST_POSITION] - 48;
      executeMovement();
    }
    else if (user_input.at(THIRD_POSITION)[FIRST_POSITION] == 0 + 48 || !checkIfInteger(user_input.at(THIRD_POSITION)))
    {
      std::cout << INVALID_PARAMETER << QUOTATION_MARK << user_input.at(THIRD_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
    else
    {
      std::cout << IMPOSSIBLE_MOVE << std::endl;
      return false;
    }
  }
  else
  {
    if (parseDirection(user_input.at(FIRST_POSITION)) == false)
    {
      std::cout << INVALID_COMMAND << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << std::endl;
      return false;
    }
    if (user_input.size() != EQUAL_ONE)
    {
      std::cout << COMMAND_DOES_NOT_TAKE_ARGUMENTS << std::endl;
      return false;
    }
    command_.fields_ = EQUAL_ONE;
    executeMovement();
  }
  return true;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::handlePlayerMovement(std::vector<std::string> user_input)
{
  detectPlayer();
  if (command_.was_insertion_ == false)
  {
    if (user_input.at(FIRST_POSITION) == "w" || user_input.at(FIRST_POSITION) == "a" || 
        user_input.at(FIRST_POSITION) == "s" || user_input.at(FIRST_POSITION) == "d")
    {
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
                << std::endl;
      return false;
    }
    else if (user_input.at(FIRST_POSITION) == ARROW_UP)
    {
      std::cout << "\"arrow up\""
                << CURRENTLY_NOT_ALLOWED << std::endl;
      return false;
    }
    else if (user_input.at(FIRST_POSITION) == ARROW_DOWN)
    {
      std::cout << "\"arrow down\""
                << CURRENTLY_NOT_ALLOWED << std::endl;
      return false;
    }
    else if (user_input.at(FIRST_POSITION) == ARROW_LEFT)
    {
      std::cout << "\"arrow left\""
                << CURRENTLY_NOT_ALLOWED << std::endl;
      return false;
    }
    else if (user_input.at(FIRST_POSITION) == ARROW_RIGHT)
    {
      std::cout << "\"arrow right\""
                << CURRENTLY_NOT_ALLOWED << std::endl;
      return false;
    }
    else
    {
      std::cout << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << CURRENTLY_NOT_ALLOWED 
                << std::endl;
      return false;
    }
    return false;
  }
  if (user_input.size() > 3)
  {
    std::cout << WRONG_ARGUMENTS << std::endl;
    return false;
  }
  if(helperHandlePlayerMovement(user_input) == false)
  {
    return false;
  }
  else
  {
    return true;
  }
  return true;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::parseDirection(std::string user_input)
{
  if (user_input == "w" || user_input == "up" || user_input == ARROW_UP)
  {
    command_.direction_ = DIRECTION_UP;
  }
  else if (user_input == "d" || user_input == RIGHT_LONG || user_input == ARROW_RIGHT)
  {
    command_.direction_ = DIRECTION_RIGHT;
  }
  else if (user_input == "s" || user_input == "down" || user_input == ARROW_DOWN)
  {
    command_.direction_ = DIRECTION_DOWN;
  }
  else if (user_input == "a" || user_input == LEFT_LONG || user_input == ARROW_LEFT)
  {
    command_.direction_ = DIRECTION_LEFT;
  }
  else
  {
    return false;
  }
  return true;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::loadPlayerLocation(bool reload, size_t row, size_t col)
{
  PlayerLocation location;
  if (reload == false)
  {
    location.color_ = board_of_game_.at(row).at(col)->getPlayers().at(FIRST_POSITION)->getColor()[FIRST_POSITION];
    location.row_ = row;
    location.col_ = col;
    player_location_.push_back(location);
  }
  else
  {
    for (size_t player = START; player < player_location_.size(); player++)
    {
      for (size_t tile_players = START; tile_players < board_of_game_.at(row).at(col)->getPlayers().size(); 
      tile_players++)
      {
        if (player_location_.at(player).color_ == board_of_game_.at(row).at(col)->getPlayers().at
           (tile_players)->getColor()[FIRST_POSITION])
        {
          player_location_.at(player).row_ = row;
          player_location_.at(player).col_ = col;
        }
      }
    }
  }
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::detectPlayer()
{
  if (PlayerLocation::load_ == true)
  {
    return;
  }
  size_t temp_player_size_storage = player_location_.size();
  for (size_t row = START; row < HEIGHT; row++)
  {
    for (size_t col = START; col < WIDTH; col++)
    {
      if (board_of_game_.at(row).at(col)->checkIfPlayersVectorEmpty() == false)
      {
        if (temp_player_size_storage == EQUAL_ZERO)
        {
          loadPlayerLocation(false, row, col); 
        }
        else
        {
          loadPlayerLocation(true, row, col);
        }
      }
    }
  }
  PlayerLocation::load_ = true;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::executeMovement()
{
  size_t playerRow = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).row_;
  size_t playerCol = player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).col_;
  if (checkMoveIsPossible(command_.direction_, command_.fields_, playerRow, playerCol) == false)
  {
    std::cout << IMPOSSIBLE_MOVE << std::endl;
    return;
  }
  movePlayer(playerRow, playerCol, command_.direction_, command_.fields_);
  if (command_.gamefield_on_ == true)
  {
    printBoard(nr_of_players_, players_);
  }
  return;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::movePlayer(size_t row_current_pos, size_t col_current_pos, size_t direction, size_t fields)
{
  std::vector<Player*> empty;
  size_t current_player_at = UserInputArgs::current_player_ - 1;
  std::vector<Player*> current_player_data = board_of_game_.at(row_current_pos).at(col_current_pos)->getPlayers();
  for (size_t players = START; players < current_player_data.size(); players++)
  {
    if (current_player_data.at(players)->getColor().at(FIRST_POSITION) == player_location_[current_player_at].color_)
    {
      current_player_data.at(FIRST_POSITION) = current_player_data.at(players);
      current_player_data.resize(1); 
      break;
    }
  }
  size_t value_r = fields;
  size_t value_c = fields;
  switch (direction)
  {
    case 0:
      value_r = row_current_pos - value_r;
      value_c = col_current_pos;
      break;
    case 1:
      value_r = row_current_pos;
      value_c = col_current_pos + value_c;
      break;
    case 2:
      value_r = row_current_pos + value_r;
      value_c = col_current_pos;
      break;
    case 3:
      value_r = row_current_pos;
      value_c = col_current_pos - value_c;
      break;
    default:
      break;
  }
  
  board_of_game_.at(value_r).at(value_c)->pushPlayerToPlayersVector(current_player_data.back());
  if (board_of_game_.at(value_r).at(value_c)->getPlayers().size() > 1)
  {
    board_of_game_.at(value_r).at(value_c)->setPlayers(sortPlayer(board_of_game_.at(value_r).at
    (value_c)->getPlayers()));
  }
  empty = board_of_game_.at(row_current_pos).at(col_current_pos)->getPlayers();
  for (size_t players = START; players < empty.size(); players++)
  {
    if (empty.at(players)->getColor().at(FIRST_POSITION) == player_location_[current_player_at].color_)
    {
      empty.erase(empty.begin() + players);
    }
  }
  board_of_game_.at(row_current_pos).at(col_current_pos)->setPlayers(empty);
  player_location_.at(current_player_at).row_ = value_r;
  player_location_.at(current_player_at).col_ = value_c;
}

///---------------------------------------------------------------------------------------------------------------------
std::vector<Player*> UserInput::sortPlayer(std::vector<Player*> player_info)
{
  std::vector<Player*> sorting;
  for (size_t players = START; players < player_info.size(); players++)
  {
    if (player_info.at(players)->getColor().at(FIRST_POSITION) == FIRST_LETTER_COLOR_RED)
    {
      sorting.push_back(player_info.at(players));
      break;
    }
  }
  for (size_t players = START; players < player_info.size(); players++)
  {
    if (player_info.at(players)->getColor().at(FIRST_POSITION) == FIRST_LETTER_COLOR_YELLOW)
    {
      sorting.push_back(player_info.at(players));
      break;
    }
  }
  for (size_t players = START; players < player_info.size(); players++)
  {
    if (player_info.at(players)->getColor().at(FIRST_POSITION) == FIRST_LETTER_COLOR_GREEN)
    {
      sorting.push_back(player_info.at(players));
      break;
    }
  }
  for (size_t players = START; players < player_info.size(); players++)
  {
    if (player_info.at(players)->getColor().at(FIRST_POSITION) == FIRST_LETTER_COLOR_BLUE)
    {
      sorting.push_back(player_info.at(players));
      break;
    }
  }

  return sorting;
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::checkUserInput(std::vector<std::string> user_input)
{
  bool return_variable = false;
  if (user_input.size() == EQUAL_ZERO)
  {
    return false;
  }
  std::string input_word = user_input.at(FIRST_POSITION);
  detectPlayer();
  if (input_word == "showtreasure" || input_word == "st")
  {
    return_variable = handleShowtreasure(user_input);
    return return_variable;
  }
  else if (input_word == "hidetreasure" || input_word == "ht")
  {
    return_variable = handleHideTreasure(user_input);
    return return_variable;
  }
  else if (input_word == "showfreetile" || input_word == "sft")
  {
    return_variable = handleShowFreeTile(user_input);
    return return_variable;
  }
  else if (input_word == "quit" || input_word == "exit")
  {
    return_variable = handleQuit(user_input);
    return return_variable;
  }
  else if (input_word == "finish" || input_word == "f")
  {
    return_variable = handleFinish(user_input);
    return return_variable;
  }
  else if (input_word == "gamefield" || input_word == "g")
  {
    return_variable = handleGameField(user_input);
    return return_variable;
  }
  else if (input_word == "rotate")
  {
    return_variable = handleRotate(user_input);
    return return_variable;
  }
  else if (input_word == "go" || input_word == "w" || input_word == "a" || input_word == "s" || input_word == "d" ||
           input_word == ARROW_UP || input_word == ARROW_DOWN || input_word == ARROW_LEFT || input_word == ARROW_RIGHT)
  {
    return_variable = handlePlayerMovement(user_input);
    return return_variable;
  }
  else if (input_word == "insert" || input_word == "i")
  {
    return_variable = handleInsert(user_input);
    return return_variable;
  }
  else
  {
    std::cout << INVALID_COMMAND
              << QUOTATION_MARK << user_input.at(FIRST_POSITION) << QUOTATION_MARK << std::endl;
    return return_variable;
  }
  return return_variable;
}

///---------------------------------------------------------------------------------------------------------------------
std::vector<std::string> UserInput::createVectorOfWords(std::vector<std::string> help_vector)
{
  std::string help_string;
  help_string.clear();
  for (size_t input_value_counter = START; input_value_counter < input_value_.size(); input_value_counter++)
  {
    if (input_value_.at(input_value_counter) != SPACE)
    {
      help_string.push_back(input_value_.at(input_value_counter));
      if (input_value_counter == input_value_.size() - REDUCE_ONE)
      {
        help_vector.push_back(help_string);
      }
    }
    else
    {
      help_vector.push_back(help_string);
      help_string.clear();
    }
  }
  return help_vector;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::RemoveExtraBlankspaces()
{
  if (input_value_.size() == EQUAL_ZERO)
  {
    return;
  }
  for (size_t at_input = START; at_input < input_value_.size(); at_input++)
  {
    while (input_value_[at_input] == SPACE && input_value_[at_input + ADD_ONE] == SPACE)
    {
      if (input_value_.size() <= at_input)
      {
        break;
      }
      at_input++;
    }
    temp_string_.push_back(input_value_[at_input]);
  }
  if (temp_string_.at(FIRST_POSITION) == SPACE)
  {
    temp_string_.erase(0, 1);
  }
  input_value_ = temp_string_;
  temp_string_.clear();
}

///---------------------------------------------------------------------------------------------------------------------
bool UserInput::validInput()
{
  RemoveExtraBlankspaces();
  std::vector<std::string> help_vector = {};
  help_vector = createVectorOfWords(help_vector);
  bool return_value = checkUserInput(help_vector);
  return return_value;
}

///---------------------------------------------------------------------------------------------------------------------
void clearStruct(UserInputArgs& object)
{
  object.show_treasure_ = object.show_treasure_;
  object.hide_treasure_ = false;
  object.quit_ = false;
  object.show_free_tile_ = false;
  object.finish_ = false;
  object.gamefield_ = false;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::playerChoice()
{
  do
  {
    if (command_.game_ends_ == true)
    {
      command_.quit_ = true;
      break;
    }
    PlayerLocation::first_++;
    clearStruct(command_);
    if (UserInputArgs::current_player_ == 1)
    {
      std::cout << "RED > ";
    }
    else if (UserInputArgs::current_player_ == 2)
    {
      std::cout << "YELLOW > ";
    }
    else if (UserInputArgs::current_player_ == 3)
    {
      std::cout << "GREEN > ";
    }
    else if (UserInputArgs::current_player_ == 4)
    {
      std::cout << "BLUE > ";
    }

    input_value_.clear();
    getline(std::cin, input_value_);
    if (std::cin.eof())
    {
      command_.quit_ = true;
      break;
    }
  } while (validInput() == false || command_.show_treasure_ == true || command_.hide_treasure_ == true ||
           command_.quit_ == false || command_.show_free_tile_ == true || getFinishValue() == true);
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::setNextPlayer(size_t player_count)
{
  if (command_.was_insertion_ == true)
  {
    UserInputArgs::current_player_++;
    if (UserInputArgs::current_player_ > player_count)
    {
      UserInputArgs::current_player_ = 1;
    }
    command_.was_insertion_ = false;
    command_.already_moved_ = false;
  }
}

///---------------------------------------------------------------------------------------------------------------------
std::string UserInput::getInputValue()
{
  return input_value_;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::setInputValue(std::string input)
{
  input_value_ = input;
}

///---------------------------------------------------------------------------------------------------------------------
void printLowerPlayers(size_t nr_players, std::vector<std::string> player_cards_vector, std::string cards)
{
  if (nr_players == 3)
  {
    std::cout << std::left << std::setw(17) << "Player Green(G)" 
              << std::setw(19) << BOARD_ARROW_DOWN << std::setw(19) << BOARD_ARROW_DOWN
              << std::setw(0) << BOARD_ARROW_DOWN << std::endl;
    std::cout << std::left << std::setw(17) << TREASURE + player_cards_vector.at(THIRD_POSITION) + SLASH + cards 
              << std::setw(18) << VERTICAL_LINE << std::setw(18) << VERTICAL_LINE << std::setw(0) 
              << VERTICAL_LINE << std::endl;
  }

  if (nr_players == 4)
  {
    std::cout << std::left << std::setw(17) << "Player Green(G)" 
              << std::setw(19) << BOARD_ARROW_DOWN << std::setw(19) << BOARD_ARROW_DOWN
              << std::setw(5) << BOARD_ARROW_DOWN
              << "Player Blue(B)" << std::endl;
    std::cout << std::left << std::setw(17) << TREASURE + player_cards_vector.at(THIRD_POSITION) + SLASH + cards 
              << std::setw(18) << VERTICAL_LINE << std::setw(18) << VERTICAL_LINE << std::setw(4) << VERTICAL_LINE
              << TREASURE + player_cards_vector.at(FOURTH_POSITION) + SLASH + cards 
              << std::endl;
  }

  if (nr_players == 2)
  {
    std::cout << std::left << std::setw(17) << EMPTY_CHARACTER << std::setw(19) << BOARD_ARROW_DOWN 
              << std::setw(19) << BOARD_ARROW_DOWN << std::setw(0) << BOARD_ARROW_DOWN
              << std::endl;
    std::cout << std::left << std::setw(17) << EMPTY_CHARACTER << std::setw(18) << VERTICAL_LINE << std::setw(18) 
              << VERTICAL_LINE << std::setw(0) << VERTICAL_LINE
              << std::endl;
  }
}

///---------------------------------------------------------------------------------------------------------------------
void printRightSide(size_t row)
{
  if (row == ROW_SEVEN_USER)
  {
    std::cout << BOARD_ARROW_RIGHT;
  }
  if (row == ROW_SEVENTEEN_USER)
  {
    std::cout << BOARD_ARROW_RIGHT;
  }
  if (row == ROW_TWENTYSEVEN_USER)
  {
    std::cout << BOARD_ARROW_RIGHT;
  }
}

///---------------------------------------------------------------------------------------------------------------------
void printLeftSide(size_t row)
{
  if (row != ROW_TWO_USER && row != ROW_SEVEN_USER && row != ROW_TWELVE_USER && row != ROW_SEVENTEEN_USER && 
      row != ROW_TWENTYTWO_USER && row != ROW_TWENTYSEVEN_USER && row != ROW_THIRTYTWO_USER)
  {
    std::cout << std::setw(5);
  }
  if (row == ROW_TWO_USER)
  {
    std::cout << std::setw(4) << ONE;
  }
  else if (row == ROW_TWELVE_USER)
  {
    std::cout << std::setw(4) << THREE;
  }
  else if (row == ROW_TWENTYTWO_USER)
  {
    std::cout << std::setw(4) << FIVE;
  }
  else if (row == ROW_THIRTYTWO_USER)
  {
    std::cout << std::setw(4) << SEVEN;
  }
  else if (row == ROW_SEVEN_USER)
  {
    std::cout << BOARD_ARROW_LEFT << TWO;
  }
  else if (row == ROW_SEVENTEEN_USER)
  {
    std::cout << BOARD_ARROW_LEFT << FOUR;
  }
  else if (row == ROW_TWENTYSEVEN_USER)
  {
    std::cout << BOARD_ARROW_LEFT << SIX;
  }
  else
  {
    std::cout << std::setw(4);
  }
}

///---------------------------------------------------------------------------------------------------------------------
void printUpperPlayers(size_t nr_players, std::vector<std::string> player_cards_vector, std::string cards)
{
  if (nr_players >= 2)
  {
    std::cout << std::left << std::setw(17) << "Player Red(R)" << std::setw(18) 
              << VERTICAL_LINE << std::setw(18) << VERTICAL_LINE
              << std::setw(5) << VERTICAL_LINE
              << "Player Yellow(Y)" << std::endl;
    std::cout << std::left << std::setw(17) << TREASURE + player_cards_vector.at(FIRST_POSITION) + SLASH + cards 
              << std::setw(18) << BOARD_ARROW_UP << std::setw(18) << BOARD_ARROW_UP << std::setw(5) 
              << BOARD_ARROW_UP << TREASURE + player_cards_vector.at(SECOND_POSITION) + SLASH + cards << std::endl;

    std::cout << std::right;
    std::cout << std::setw(9) << ONE << std::setw(9) << TWO << std::setw(9) << THREE << std::setw(9) << FOUR
              << std::setw(9) << FIVE << std::setw(9) << SIX 
              << std::setw(9) << SEVEN << std::setw(4) << EMPTY_CHARACTER << std::endl;
  }
}

///---------------------------------------------------------------------------------------------------------------------
std::string intToString(size_t number)
{
  std::stringstream string_stream;
  string_stream << number;
  std::string final_string = string_stream.str();
  return final_string;
}

///---------------------------------------------------------------------------------------------------------------------
std::vector<std::vector<char>> fillBoard(std::vector<std::vector<Tile*>>& game_board)
{
  std::vector<std::vector<char>> helper_vector = {};
  std::vector<char> first_row = {};
  std::vector<char> second_row = {};
  std::vector<char> third_row = {};
  std::vector<char> forth_row = {};
  std::vector<char> fifth_row = {};
  std::string temspsting;

  for (size_t row = START; row < HEIGHT; row++)
  {

    for (size_t col = START; col < WIDTH; col++)
    {
      temspsting.clear();
      temspsting = game_board.at(row).at(col)->getTileString();
      for (size_t tile = START; tile < 9; tile++)
      {
        first_row.push_back(temspsting.at(tile));
        second_row.push_back(temspsting.at(tile + 9));
        third_row.push_back(temspsting.at(tile + 18));
        forth_row.push_back(temspsting.at(tile + 27));
        fifth_row.push_back(temspsting.at(tile + 36));
      }
    }

    helper_vector.push_back(first_row);
    helper_vector.push_back(second_row);
    helper_vector.push_back(third_row);
    helper_vector.push_back(forth_row);
    helper_vector.push_back(fifth_row);

    first_row.clear();
    second_row.clear();
    third_row.clear();
    forth_row.clear();
    fifth_row.clear();
  }
  return helper_vector;
}

///---------------------------------------------------------------------------------------------------------------------
void UserInput::printBoard(size_t nr_players, std::vector<Player*> players_vector)
{
  std::vector<std::vector<char>> play_board = {};
  size_t cards_per_person = TOTAL_TREASURE_CARDS / nr_players;
  std::string cards = intToString(cards_per_person);
  std::string player_cards;
  std::vector<std::string> player_cards_vector = {};
  play_board = fillBoard(board_of_game_);

  for (size_t nr_cards_counter = START; nr_cards_counter < nr_players; nr_cards_counter++)
  {
    player_cards = intToString(players_vector.at(nr_cards_counter)->getNrFoundTreasures());
    player_cards_vector.push_back(player_cards);
    player_cards.clear();
  }

  printUpperPlayers(nr_players, player_cards_vector, cards);

  for (size_t row = START; row < BOARD_HEIGHT_IN_CHAR; row++)
  {
    printLeftSide(row);
    std::cout << EMPTY_CHARACTER;
    for (size_t col = START; col < BOARD_WIDTH_IN_CHAR; col++)
    {
      if (play_board.at(row).at(col) == (char) NUMBER_219)
      {
        std::cout << BLACK_BLOCK;
      }
      else
      {
        std::cout << play_board.at(row).at(col);
      }
    }
    printRightSide(row);
    std::cout << std::endl;
  }
  printLowerPlayers(nr_players, player_cards_vector, cards);
  if (player_location_.at(UserInputArgs::current_player_ - REDUCE_ONE).stack_empty_ == true && 
      PlayerLocation::first_ >= EQUAL_ONE)
  {
    std::cout << ALL_TREASURES_FOUND << std::endl;
    return;
  }
  if (command_.show_treasure_ == true)
  {
    std::cout << CURRENT_TREASURE << players_.at(UserInputArgs::current_player_ - REDUCE_ONE)->getCurrentTreasureName()
              << ID_OF_TREASURE << players_.at(UserInputArgs::current_player_ - REDUCE_ONE)->getCurrentTreasureId() 
              << "\n";
  }
}