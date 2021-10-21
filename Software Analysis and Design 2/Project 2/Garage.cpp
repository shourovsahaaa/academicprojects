/****************************************************************************************************************************
Title        : Garage
Authors      : Future Professional C++ programmer, Shourov Saha
Description  : Cpp file defining the functions called in Gargage.hpp of a Garage class which borrows heavily from the ArrayBag ADT.
****************************************************************************************************************************/

#include "Garage.hpp"
#include "Object.hpp"
#include "Vehicle.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/** default constructor **/
template<typename ItemType>
Garage<ItemType>::Garage(size_t capacity)
{
  capacity_ = capacity;
  spaces_occupied_ = 0;
  items_ = new ItemType[capacity_];
}

/**
@param target to be found in items_
@return either the index target in the array items_ or -1,
if the array does not contain the target.
**/
template<typename ItemType>
int Garage<ItemType>::getIndexOf(const ItemType &target) const
{
  bool found = false;
  int result = -1;
  int search_index = 0;
  while (!found && (search_index < spaces_occupied_)) 
  {
    if (items_[search_index] == target) 
    {
      found = true;
      result = search_index;
    }
    else 
    {
      search_index++;
    }
  }
  return result;
}

/**
@return spaces_occupied_ : the number of vehicles currently stored in the caller
**/
template<typename ItemType>
size_t Garage<ItemType>::getCurrentSize() const
{
  return spaces_occupied_;
}

/**
 @return true if spaces_occupied_ == 0, false otherwise
**/
template<typename ItemType>
bool Garage<ItemType>::isEmpty() const
{
  if (spaces_occupied_ == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/**
 @return true if to_add was successfully added to items_, false otherwise
**/
template<typename ItemType>
bool Garage<ItemType>::add(const ItemType &to_add)
{
  bool fit = (spaces_occupied_ < capacity_);
  if (fit)
  {
    for (int i = 0; i < to_add.getSpaces(); i++)
    {
      items_[spaces_occupied_] = to_add;
      spaces_occupied_++;
    }
  }
  return fit;
}

/**
 @return true if a single instance of an_entry was successfully removed from items_, false otherwise
**/
template<typename ItemType>
bool Garage<ItemType>::remove(const ItemType &to_remove)
{
  int index = getIndexOf(to_remove);
  int size = to_remove.getSpaces();
  bool can_remove_item = !isEmpty()&&(index>-1);
  if (can_remove_item == 0)
  {
    return false;
  }
  
  for (int i = 0; i < size; i++)
  {
    spaces_occupied_--;
    items_[index] = items_[spaces_occupied_];
    index = getIndexOf(to_remove);
    if (index == -1)
    {
      return true;
    }
  }
  return true;
}


/**
@return true if you manage to swap the given items, false otherwise.
**/
template<typename ItemType>
bool Garage<ItemType>::swap(ItemType in, ItemType out)
{
  if (remove(out) && add(in))
  {
    return true;
  }
  return false;
}

/**
@return the number of times an_entry is found in items_
**/
template<typename ItemType>
int Garage<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
  int count = 0;
  for (int i = 0; i < capacity_; i++)
  {
    if (items_[i] == an_entry)
    {
      count++;
    }
  }

  return count;
}


/**
@return a vector that has the same contents as items_
**/
template<typename ItemType>
vector<ItemType> Garage<ItemType>::toVector() const
{
  vector<ItemType> Garage_contents;
  for (int i = 0; i < spaces_occupied_; i += items_[i].getSpaces())
  {
    Garage_contents.push_back(items_[i]);
  }

  return Garage_contents;
}

/**
@return true if spaces_occupied_ == capacity_, false otherwise
**/
template<typename ItemType>
bool Garage<ItemType>::isFull() const
{
  if (spaces_occupied_ == capacity_)
  {
    return 1;
  }

  return 0;
}

/**
@post spaces_occupied_ == 0
**/
template<typename ItemType>
void Garage<ItemType>::clear()
{
  spaces_occupied_ = 0;
}

/**
@return true if an_entry is found in items_, false otherwise
**/
template<typename ItemType>
bool Garage<ItemType>::contains(const ItemType &an_entry) const
{
  if (getFrequencyOf(an_entry) > 0)
  {
    return 1;
  }

  return 0;
}


/** 
Outputs the names of the content in the Garage ADT. 
If there are multiple instances of an item in the Garage, you only output it once.
        
Example Output:
Item_1_Name Item_1_Manufacturer
Item_2_Name Item_2_Manufacturer
Item_3_Name Item_3_Manufacturer
**/
template<typename ItemType>
void Garage<ItemType>::display() const
{
  for (int i = 0; i < spaces_occupied_; i += items_[i].getSpaces())
  {
    cout << items_[i].getName() << " " << items_[i].getManufacturer() << endl;
  }
}

/** implements Set Union over the caller and a_garage. The union of two sets A and B is the set of elements which are in A, in B, or in both A and B.  
@param a_garage to be combined with the contents of this (the calling) garage
@post adds as many items from a_garage as space allows    
*/
template<typename ItemType>
void Garage<ItemType>::operator+=(const Garage<ItemType> &a_garage)
{
  vector<ItemType> addgarage = a_garage.toVector();
  for (int i = 0; i < a_garage.getCurrentSize(); i ++)
  {
    add(addgarage[i]);
  }
}

/** implements Set Difference over the caller and a_garage. The difference between two sets A and B is the set that consists of the elements of A which are not elements of B 
@param a_garage to be subtracted from this (the calling) garage
@post removes all data from items_ that are also found in a_garage
*/
template<typename ItemType>
void Garage<ItemType>::operator-=(const Garage<ItemType> &a_garage)
{
  vector<ItemType> addgarage = a_garage.toVector();
  for (int i = 0; i < capacity_; i ++)
  {
    remove(addgarage[i]);
  }
}


/** implements Set Intersection over the caller and a_garage. The intersection of two sets A and B is the set that consists of the elements that are in both A and B 
@param a_garage to be intersected with this (the calling) garage
@post items_ no longer contains data that is not found in a_garage    
*/
template<typename ItemType>
void Garage<ItemType>::operator/=(const Garage<ItemType> &a_garage)
{
  vector<ItemType> newvect = a_garage.toVector();
  int x = 0;
  for (int x = 0; x < newvect.size(); x++)
  {
    if (contains(newvect[x]) == 0)
    {
      newvect.erase (newvect.begin()+x);
    }
  }
  clear();
  for (int x = 0; x < newvect.size(); x++)
  {
    add(newvect[x]);
  }
  
}
