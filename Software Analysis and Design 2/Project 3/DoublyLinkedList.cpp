/*
Title          : DoublyLinkedList.cpp
Qualifications : King of C++, Ruler of the Public Functions, and Protector of the Private.
Author         : First of his name, Shourov Saha.
Description    : Implementation file of DoublyLinkedList class as a Linked List ADT using class DoubleNode.
*/
#ifndef DOUBLYLINKEDLISTCPP_
#define DOUBLYLINKEDLISTCPP_

#include "DoubleNode.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/** Default Constructor **/
template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() {
  size = 0;
  HeadPtr = nullptr;
}

/** Copy Constructor **/
template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList& Hold) {
  HeadPtr = Hold.HeadPtr;
  size = Hold.size;
}

/** Destructor **/
template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList() {
  clear();
}

/** Inserts item at position in caller list **/
template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position) {
  if (position < 1 or position > size + 1) {
    return false;
  }
  else 
  {
    DoubleNode<ItemType>* node = new DoubleNode<ItemType>(item);
    if (position == 1) 
    {
      if (HeadPtr == nullptr) 
      {
      HeadPtr = node;
      }
      else 
      {
        node->setNext(HeadPtr);
        HeadPtr->setPrev(node);
        HeadPtr = node;
      }
    }
    else 
    {
      DoubleNode<ItemType>* iterator = HeadPtr;
      for (int i = 2; i < position; i++) {
        iterator = iterator->getNext();
      }
      if (iterator->getNext() != nullptr) {
        iterator->getNext()->setPrev(node);
        node->setNext(iterator->getNext());
      }
      iterator->setNext(node);
      node->setPrev(iterator);
    }
    size++;
    return true;
  }
}

/** Removes the node at position **/
template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position) {
  if (position < 1 or position > size) {
    return false;
  }
  else {
    DoubleNode<ItemType>* holder;
    if (position == 1) {
      holder = HeadPtr;
      HeadPtr = HeadPtr->getNext();
      if (HeadPtr != nullptr) {
        HeadPtr->setPrev(nullptr);
      }
      delete holder;
    }
    else {
      DoubleNode<ItemType>* iterator = HeadPtr;
      for (int i = 1; i < position-1; i++) 
      {
        iterator = iterator->getNext();
      }
      holder = iterator->getNext();
      if (iterator->getNext()->getNext() != nullptr) 
      {
        iterator->getNext()->getNext()->setPrev(iterator);
        iterator->setNext(iterator->getNext()->getNext());
      }
      else {
        iterator->setNext(nullptr);
      }
        delete holder;
    }
  }
  size--;
  return true;
}

/** Returns the number of the nodes in the calling list **/
template <typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const {
  return size;
}

/** Returns a copy of the HeadPtr **/
template <typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const {
  return HeadPtr;
}

/** Returns a pointer to the node located at pos. **/
template <typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const {
  if (pos < 1 or pos > size)
  {
    return nullptr;
  }
  else
  {
    DoubleNode<ItemType>* iterator = HeadPtr;
    for (int i = 1; i < pos; i++)
    {
      iterator = iterator->getNext();
    }
    return iterator;
  }
}

/** Returns whether the calling list is empty **/
template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const {
  return (size == 0);
}

/** Clears the list. **/
template <typename ItemType>
void DoublyLinkedList<ItemType>::clear() {
  DoubleNode<ItemType>* holder = HeadPtr;
  while (size != 0)
  {
   HeadPtr = HeadPtr->getNext();
   delete holder;
   holder = HeadPtr;
   size--;
  }
}

/** Prints the contents of the calling list in order  **/
template <typename ItemType>
void DoublyLinkedList<ItemType>::display() const {
  DoubleNode<ItemType>* iterator = HeadPtr;
  for (int i = 1; i <= size; i++)
  {
    cout << iterator->getItem();
    if (i != size)
    {
      cout << " ";
    }
    iterator = iterator->getNext();
  }
  cout << endl;
}

/** Prints the contents of the calling list in reverse order **/
template <typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {
  DoubleNode<ItemType>* iterator = getAtPos(size);
  for (int i = 1; i <= size; i++)
  {
    cout << iterator->getItem();
    if (i != size)
    {
      cout << " ";
    }
    iterator = iterator->getPrev();
  }
  cout << endl; 
}

/** Returns the interleaved list of the calling and parameter lists **/
template <typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list) {
  DoubleNode<ItemType>* iterator1 = this->HeadPtr;
  DoubleNode<ItemType>* iterator2 = a_list.HeadPtr;
  DoublyLinkedList<ItemType>* finallist = new DoublyLinkedList();
  int x = size;
  int y = a_list.size;
  int position = 1;
  while (iterator1 != nullptr or iterator2 != nullptr)
  {
    if (iterator1 != nullptr)
    {
      finallist->insert(iterator1->getItem(), position);
      position ++;
      iterator1 = iterator1->getNext();
    }
    if (iterator2 != nullptr)
    {
      finallist->insert(iterator2->getItem(), position);
      position ++;
      iterator2 = iterator2->getNext();
    }
  }
  return *finallist;
}

#endif
