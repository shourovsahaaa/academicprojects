/*
Title          : BinaryPriorityNode.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract class BinaryPriorityNode which is similar to a linked list with priority values dictating order.
*/
#ifndef BinaryPriorityNodeCPP_
#define BinaryPriorityNodeCPP_
#include "BinaryPriorityNode.hpp"


template<typename ItemType>
BinaryPriorityNode<ItemType>::BinaryPriorityNode()
{
  priority_ = 2147483647;
  child1_= child2_ = nullptr;
}

template<typename ItemType>
BinaryPriorityNode<ItemType>::BinaryPriorityNode(const ItemType& an_item)
{
  item_ = an_item;
  child1_= nullptr;
  child2_= nullptr;
}

template<typename ItemType>
BinaryPriorityNode<ItemType>::BinaryPriorityNode(const ItemType& an_item, int priority)
{
  item_ = an_item;
  priority_ = priority;
  child1_ = nullptr;
  child2_ = nullptr;

}

template<typename ItemType>
BinaryPriorityNode<ItemType>::BinaryPriorityNode(const ItemType& an_item, int priority, BinaryPriorityNode<ItemType>* child1_node_ptr, BinaryPriorityNode<ItemType>* child2_node_ptr)
{
  item_ = an_item;
  priority_ = priority;
  child1_ = child1_node_ptr;
  child2_ = child2_node_ptr;
}

template<typename ItemType>
void BinaryPriorityNode<ItemType>::setItem(const ItemType& an_item)
{
  item_= an_item;
}

template<typename ItemType>
void BinaryPriorityNode<ItemType>::setPriority(const int priority)
{
  priority_ = priority;
}

template<typename ItemType>
void BinaryPriorityNode<ItemType>::setNext(BinaryPriorityNode<ItemType>* child_node_ptr)
{
  child1_ = child_node_ptr;
}

template<typename ItemType>
void BinaryPriorityNode<ItemType>::setNext2(BinaryPriorityNode<ItemType>* child_node_ptr)
{
  child2_ = child_node_ptr;
}

template<typename ItemType>
ItemType BinaryPriorityNode<ItemType>::getItem() const
{
  return item_;
}

template<typename ItemType>
int BinaryPriorityNode<ItemType>::getPriority() const
{
  return priority_;
}

template<typename ItemType>
BinaryPriorityNode<ItemType>* BinaryPriorityNode<ItemType>::getNext() const
{
  return child1_;
}

#endif

