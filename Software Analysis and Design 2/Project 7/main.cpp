/*
Title          : main.cpp
Author         : Shourov Saha
Description    : Testing BST implementation.
*/
#include <iostream>
#include "BinaryPriorityNode.hpp"
#include "PriorityQueueBST.hpp"

int main() {
  PriorityQueueBST<int> Test;
  Test.enqueue(15, 10);
  Test.enqueue(5, 100);
  Test.enqueue(25, 100);
  Test.enqueue(155, 10);
  Test.enqueue(20, 330);
  Test.enqueue(55, 1000);
  Test.enqueue(1995, 1008383);

  for(int i = 0; i < Test.size(); i++)
  {
    cout << Test.front();
    Test.dequeue();
  }
  
}
