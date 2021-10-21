/*
Title          : DoubleNode.hpp
Qualifications : King of the Andals and the First Men, Lord of the Six Kingdoms, and Protector of the Realm.
Author         : First of his name, Shourov Saha
Description    : Header/Interface file of DoubleNode class as a Linked List ADT.
*/
#ifndef DOUBLENODE_
#define DOUBLENODE_

template <typename ItemType>
class DoubleNode {
public:
  /** Default Constructor **/
    DoubleNode();

  /** Parameterized Constructor(s)**/
    DoubleNode(ItemType item);
  
  /** Getter Functions **/
    ItemType getItem() const;

    DoubleNode<ItemType>* getNext();

    DoubleNode<ItemType>* getPrev();
    
  /** Setter Functions **/
    bool setNext(DoubleNode* ptr);

    bool setPrev(DoubleNode* ptr);

    bool setItem(ItemType item);
  /** End of Public Functions **/
private:
  /** Item **/
    ItemType Item;

  /** Pointer to Next Node **/
    DoubleNode<ItemType>* Next;

  /** Pointer to Previous Node **/
    DoubleNode<ItemType>* Previous;

  /** End of Private Functions **/
};
#include "DoubleNode.cpp"
#endif
