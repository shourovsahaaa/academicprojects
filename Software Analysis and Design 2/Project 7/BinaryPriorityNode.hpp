#ifndef BINARY_PRIORITY_NODE_H_ 
#define BINARY_PRIORITY_NODE_H_
template<typename ItemType> class BinaryPriorityNode
{
public:
  BinaryPriorityNode();
  BinaryPriorityNode(const ItemType& an_item);
  BinaryPriorityNode(const ItemType& an_item, int priority);
  BinaryPriorityNode(const ItemType& an_item, int priority, BinaryPriorityNode<ItemType>* child1_node_ptr, BinaryPriorityNode<ItemType>* child2_node_ptr);
  void setItem(const ItemType& an_item);
  void setPriority(const int priority);
  void setNext(BinaryPriorityNode<ItemType>* child_node_ptr);
  void setNext2(BinaryPriorityNode<ItemType>* child_node_ptr);
  ItemType getItem() const;
  int getPriority() const;
  BinaryPriorityNode<ItemType>* getNext() const;
  BinaryPriorityNode<ItemType>* getNext2() const;
  
private:
  ItemType item_; // A data item
  int priority_; // The item's priority
  BinaryPriorityNode<ItemType>* child1_; // Pointer to next node
  BinaryPriorityNode<ItemType>* child2_;
}; // end PriorityNode
#include "BinaryPriorityNode.cpp"
#endif // BINARY_PRIORITY_NODE_H_ 
