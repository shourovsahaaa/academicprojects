/*
Title          : DoubleNode.cpp
Qualifications : King of C++, Lord of the Public Functions, and Protector of the Private.
Author         : First of his name, Shourov Saha.
Description    : Implementation file of DoubleNode class as a Linked List ADT.
*/
#ifndef DOUBLENODECPP_
#define DOUBLENODECPP_

#include "DoubleNode.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/** Default Constructor **/
template <typename ItemType>
DoubleNode<ItemType>::DoubleNode() {
  Item = 0;
  Next = nullptr;
  Previous = nullptr;
}

/** Parameterized Constructor(s)**/
template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType item) {
  Item = item;
  Next = nullptr;
  Previous = nullptr;
}

/** Getter Function **/
template <typename ItemType>
ItemType DoubleNode<ItemType>::getItem() const {
  return Item;
}

template <typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() {
   return Next;
}

template <typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() {
  return Previous;
}

/** Setter Functions **/
template <typename ItemType>
bool DoubleNode<ItemType>::setNext(DoubleNode* next) {
  this->Next = next;
  return true;
}

template <typename ItemType>
bool DoubleNode<ItemType>::setItem(ItemType item) {
  this->Item = item;
  return true;
}

template <typename ItemType>
bool DoubleNode<ItemType>::setPrev(DoubleNode* prev) {
  this->Previous = prev;
  return true;
}
#endif