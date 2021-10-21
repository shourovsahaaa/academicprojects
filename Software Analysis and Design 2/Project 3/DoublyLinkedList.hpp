/*
Title          : DoublyLinkedList.hpp
Qualifications : King of C++, Lord of the Public Functions, and Protector of the Private.
Author         : First of his name, Shourov Saha.
Description    : Header/Interface file of DoublyLinkedList class as a Linked List ADT using class DoubleNode.
*/

#ifndef DOUBLYLINKEDLIST_
#define DOUBLYLINKEDLIST_

#include "DoubleNode.hpp"
template <typename ItemType>
class DoublyLinkedList {
public:
  /** Default Constructor **/
    DoublyLinkedList();

  /** Copy Constructor **/
    DoublyLinkedList(const DoublyLinkedList& hold);
  
  /** Destructor **/
    ~DoublyLinkedList();

  /** Inserts item at position in caller list **/
    bool insert(const ItemType &item, const int &position);

  /** Removes the node at position **/
    bool remove(const int &position);

  /** Returns the number of the nodes in the calling list **/
    int getSize() const;

  /** Returns a copy of the HeadPtr **/
    DoubleNode<ItemType>* getHeadPtr() const;

  /** Returns a pointer to the node located at pos. **/
    DoubleNode<ItemType>* getAtPos(const int &pos) const;

  /** Returns whether the calling list is empty **/
    bool isEmpty() const;

  /** Clears the list. **/
    void clear();

  /** Prints the contents of the calling list in order  **/
    void display() const;

  /** Prints the contents of the calling list in reverse order **/
    void displayBackwards() const;

  /** Returns the interleaved list of the calling and parameter lists **/
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list);

  /** End of Public Functions **/
protected:
  /** Head of Pointer Chain of DoubleNode(s) **/
    DoubleNode<ItemType>* HeadPtr;

  /** Total Spaces in list **/
    size_t size;

  /** End of Private Functions **/
};
#include "DoublyLinkedList.cpp"
#endif