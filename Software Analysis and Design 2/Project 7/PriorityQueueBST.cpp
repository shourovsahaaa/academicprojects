/*
Title          : PriorityQueueBST.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract class PriotityQueueBST which uses BinaryPriorityNode(s) with priority values to dictate order and works similar to a BST. 

Grader Note    : This is basically the same as my Priorty Que from Project 6 but i changed enque to fit BinaryPriorityNode. I didn't start early enough and didnt test but hopefully it gets me over 27/80.
*/
#ifndef PRIORITYQUEBSTCPP_
#define PRIORITYQUEBSTCPP_
#include "PriorityQueueBST.hpp"
#include "BinaryPriorityNode.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

template<typename ItemType>
PriorityQueueBST<ItemType>::PriorityQueueBST()
{
  front_ = nullptr;
  item_count = 0;
}

template<typename ItemType>
PriorityQueueBST<ItemType>::PriorityQueueBST(const PriorityQueueBST<ItemType>& a_priority_queue)
{
  front_ = a_priority_queue.front_;
  item_count = a_priority_queue.item_count;
}

template<typename ItemType>
PriorityQueueBST<ItemType>::~PriorityQueueBST()
{
  BinaryPriorityNode<ItemType>* holder = front_;
  while (item_count != 0)
  {
   front_ = front_->getNext();
   delete holder;
   holder = front_;
   item_count--;
  }
}

template<typename ItemType>
void PriorityQueueBST<ItemType>::enqueue(const ItemType& new_entry, int priority) //adds by priority
{
  if (item_count == 0) //if the queue is empty, put the item in the first node.
  {
    BinaryPriorityNode<ItemType>* node = new BinaryPriorityNode<ItemType>(new_entry, priority);
    front_= node;
  }
  else
  {
    BinaryPriorityNode<ItemType>* iterator = front_;
    if (priority < iterator->getPriority()) //priority of the new_entry is less than front_, would put it in front_.
    {
      BinaryPriorityNode<ItemType>* node = new BinaryPriorityNode<ItemType>(new_entry, priority, front_, nullptr);
      front_ = node;
    }
    else
    {
      if (item_count == 1)
      {
        BinaryPriorityNode<ItemType>* node = new BinaryPriorityNode<ItemType>(new_entry, priority);
        front_->setNext(node);
      }
      else
      {
        while ((priority >= iterator->getNext()->getPriority() || priority >= iterator->getNext2()->getPriority()) && iterator->getNext() != nullptr && iterator->getNext2()!= nullptr) //pri (>= or >) itr->getPri()
        {
          iterator = iterator->getNext(); //checks if the priority of new_entry is less
        }                                 //than the next one. If it is, get the next one until its at the last one.
        if (priority < iterator->getNext2()->getPriority())
        {
          BinaryPriorityNode<ItemType>* node = new BinaryPriorityNode<ItemType>(new_entry, priority, iterator->getNext2(), nullptr);
          iterator->setNext2(node);
        }//branch generator
        BinaryPriorityNode<ItemType>* node = new BinaryPriorityNode<ItemType>(new_entry, priority, iterator->getNext(), nullptr);
        iterator->setNext(node);          //iterator-> getnext would be the one after the itr      ^^^^^^^^ new node inserted.
      }
    }
  }
  item_count++;
}

template<typename ItemType>
void PriorityQueueBST<ItemType>::dequeue() // removes element from front of the queue
{
  if (item_count > 0)
  {
    BinaryPriorityNode<ItemType>* holder = front_;
    front_ = front_->getNext();
    delete holder;
    item_count--;
  }
}

template<typename ItemType>
ItemType PriorityQueueBST<ItemType>::front() const // returns a copy of the front element
{
  ItemType frontItem = front_->getItem();
  return frontItem;
}

template<typename ItemType>
BinaryPriorityNode<ItemType>* PriorityQueueBST<ItemType>::getFrontPtr() const //returns front_ pointer
{
  return front_;
}

template<typename ItemType>
int PriorityQueueBST<ItemType>::size() const // returns the number of elements in the queue
{
  return item_count;
}

template<typename ItemType>
bool PriorityQueueBST<ItemType>::isEmpty() const // returns true if no elements in the queue
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