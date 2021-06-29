//----------------------------------------------------------------------------------------------------------------------
// Treasure.hpp
//
// Class Treasure contains methods and objects for storing
// the Treasure objects that will be later used when creating
// the board using the provided random Class
//
// Author: 11804229 
//         11814996
//         00713374
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef TREASURE_HPP
#define TREASURE_HPP

#include <string>

class Treasure
{
  private:
    std::string name_;
    size_t treasure_id_;
    bool found_;

  public:
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Default Treasure constructor.
    ///
    /// 
    ///
    //
    Treasure(){}

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Treasure constructor.
    ///
    /// 
    ///
    //
    Treasure(std::string name, size_t treasure_id) : name_{name}, treasure_id_{treasure_id}{}

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Treasure copy-constructor.
    ///
    /// 
    ///
    //
    Treasure(Treasure const&) = default;

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Treasure destructor.
    ///
    /// 
    ///
    //
    ~Treasure(){}
    
    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns the name_ of the treasures.
    ///
    /// @return string name_ of treasures
    //
    std::string getName(){ return name_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Gets treasure id
    ///
    /// @return size_ treasure id
    //
    size_t getTreasureId(){ return treasure_id_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Returns if a treasure is found.
    ///
    /// @return true if found, otherwise false
    //
    bool getFound(){ return found_; }

    //------------------------------------------------------------------------------------------------------------------
    ///
    /// Sets found.
    ///
    /// @param found_command found as true
    ///
    /// @return void
    //
    void setFound(bool found_command){ found_ = found_command; }    
};

#endif // TREASURE_HPP