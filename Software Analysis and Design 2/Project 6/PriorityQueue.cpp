/*
Title          : PriorityQueue.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract class PriotityQueue which uses PriorityNode(s) with priority values to dictate order.
*/
#ifndef PRIORITYQUECPP_
#define PRIORITYQUECPP_
#include "PriorityQueue.hpp"
#include "PriorityNode.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
  front_ = nullptr;
  back_ = nullptr;
  item_count = 0;
}

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& a_priority_queue)
{
  front_ = a_priority_queue.front_;
  back_ = a_priority_queue.back_;
  item_count = a_priority_queue.item_count;
}

template<typename ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
  PriorityNode<ItemType>* holder = front_;
  while (item_count != 0)
  {
   front_ = front_->getNext();
   delete holder;
   holder = front_;
   item_count--;
  }
}

template<typename ItemType>
void PriorityQueue<ItemType>::enqueue(const ItemType& new_entry, int priority) //adds by priority
{
  if (item_count == 0) //if the queue is empty, put the item in the first node.
  {
    PriorityNode<ItemType>* node = new PriorityNode<ItemType>(new_entry, priority);
    front_= node;
    back_ = node;  //since theres only 1, it would also be the back.
  }
  else
  {
    PriorityNode<ItemType>* iterator = front_;
    if (priority < iterator->getPriority()) //priority of the new_entry is less than front_, would put it in front_.
    {
      PriorityNode<ItemType>* node = new PriorityNode<ItemType>(new_entry, priority, front_);
      front_ = node;
    }
    else
    {
      if (item_count == 1)
      {
        PriorityNode<ItemType>* node = new PriorityNode<ItemType>(new_entry, priority);
        front_->setNext(node);
        back_ = node;
      }
      else
      {
        while (priority >= iterator->getNext()->getPriority() && iterator->getNext() != nullptr) //pri (>= or >) itr->getPri()
        {
          iterator = iterator->getNext(); //checks if the priority of new_entry is less
        }                                 //than the next one. If it is, get the next one until its at the last one.
        PriorityNode<ItemType>* node = new PriorityNode<ItemType>(new_entry, priority, iterator->getNext());
        iterator->setNext(node);          //iterator-> getnext would be the one after the itr ^^^^^^^^ new node inserted.
        if (node->getNext() == nullptr)//if the node has a next value of nullptr, then its the back.
        {
          back_ = node;
        }
      }
    }
  }
  item_count++;
}

template<typename ItemType>
void PriorityQueue<ItemType>::dequeue() // removes element from front of the queue
{
  if (item_count > 0)
  {
    PriorityNode<ItemType>* holder = front_;
    front_ = front_->getNext();
    delete holder;
    item_count--;
  }
}

template<typename ItemType>
ItemType PriorityQueue<ItemType>::front() const // returns a copy of the front element
{
  ItemType frontItem = front_->getItem();
  return frontItem;
}

template<typename ItemType>
PriorityNode<ItemType>* PriorityQueue<ItemType>::getFrontPtr() const //returns front_ pointer
{
  return front_;
}

template<typename ItemType>
int PriorityQueue<ItemType>::size() const // returns the number of elements in the queue
{
  return item_count;
}

template<typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const // returns true if no elements in the queue
{
  if (item_count == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

#endif