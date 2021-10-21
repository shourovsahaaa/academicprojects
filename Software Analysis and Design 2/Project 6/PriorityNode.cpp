/*
Title          : PriorityNode.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract class PriorityNode which is similar to a linked list with priority values dictating order.
*/
#ifndef PRIORITYNODECPP_
#define PRIORITYNODECPP_
#include "PriorityNode.hpp"


template<typename ItemType>
PriorityNode<ItemType>::PriorityNode()
{
  priority_ = 2147483647;
  next_= nullptr;
}

template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item)
{
  item_ = an_item;
  next_= nullptr;
}

template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item, int priority)
{
  item_ = an_item;
  priority_ = priority;
  next_ = nullptr;
}

template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item, int priority, PriorityNode<ItemType>* next_node_ptr)
{
  item_ = an_item;
  priority_ = priority;
  next_ = next_node_ptr;
}

template<typename ItemType>
void PriorityNode<ItemType>::setItem(const ItemType& an_item)
{
  item_= an_item;
}

template<typename ItemType>
void PriorityNode<ItemType>::setPriority(const int priority)
{
  priority_ = priority;
}

template<typename ItemType>
void PriorityNode<ItemType>::setNext(PriorityNode<ItemType>* next_node_ptr)
{
  next_ = next_node_ptr;
}

template<typename ItemType>
ItemType PriorityNode<ItemType>::getItem() const
{
  return item_;
}

template<typename ItemType>
int PriorityNode<ItemType>::getPriority() const
{
  return priority_;
}

template<typename ItemType>
PriorityNode<ItemType>* PriorityNode<ItemType>::getNext() const
{
  return next_;
}

#endif

