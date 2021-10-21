#ifndef PriorityQueueBST_H_
#define PriorityQueueBST_H_
#include "BinaryPriorityNode.hpp"
template<typename ItemType>
class PriorityQueueBST
{
public:
  PriorityQueueBST();
  PriorityQueueBST(const PriorityQueueBST<ItemType>& a_priority_queue);
  ~PriorityQueueBST();
  void enqueue(const ItemType& new_entry, int priority); //adds by priority
  void dequeue(); // removes element from front of the queue
  ItemType front() const; // returns a copy of the front element
  BinaryPriorityNode<ItemType>* getFrontPtr() const; //returns front_ pointer
  int size() const; // returns the number of elements in the queue
  bool isEmpty() const; // returns true if no elements in the queue
private:
  BinaryPriorityNode<ItemType>* front_; // Pointer to front of the queue
  int item_count;
}; //end PriorityQueueBST
#include "PriorityQueueBST.cpp"
#endif // PriorityQueueBST_H_ 