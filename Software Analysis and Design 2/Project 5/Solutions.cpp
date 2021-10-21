/*
Title          : Solutions.cpp
Author         : Shourov Saha
Description    : Defines bubbleSort, insertionSort, and mergeSort using their respective algorithms to order a list.
*/
#include "DoublyLinkedList.hpp"
#include <string>

namespace solutions
{
    /* Bubblesort */
    template <typename Comparable, typename Comparator>
    void bubbleSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
      bool swapped = true;
      int pass;
      int size = a_list.getSize();
      while (swapped && (pass < size))
      {
        swapped = false;
        for (int index = 1; index < size - pass; index ++)
        {
          if (comp (a_list.getAtPos(index + 1)->getItem(), a_list.getAtPos(index)->getItem()))
          {
            a_list.swap(index, index + 1);
            swapped = true;
          }
        }
        pass++;
      }
    }
  

    /* Insertionsort */
    template <typename Comparable, typename Comparator>
    void insertionSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
      bool sorted = false;
      int pass;
      int size = a_list.getSize();
      for (int unsorted = 1; unsorted <= size; unsorted ++)
      {
        int current = unsorted;
        while ((current > 1) && comp (a_list.getAtPos(current)->getItem(), a_list.getAtPos(current - 1)->getItem()) )
        {
          a_list.swap(current, current - 1);
          current--;          
        }
      }
    }

    /* Merge */
    template <typename Comparable, typename Comparator>
    void merge(DoublyLinkedList<Comparable> &a_list, int left_index, int middle_index, int right_index, const Comparator &comp)
    {
      int first1 = left_index;
      int last1 = middle_index;
      int first2 = middle_index + 1;
      int last2 = right_index;

      int tempListIndex = 1;
      DoublyLinkedList<Comparable> temp_list;
      //Orders temp_list from first1 to temp_list.getSize() + first1;
      while ((first1 <= last1) && (first2 <= last2))
      {
        if (comp (a_list.getAtPos(first1)->getItem(), a_list.getAtPos(first2)->getItem()))
        {
          temp_list.insert(a_list.getAtPos(first1)->getItem(), tempListIndex);
          first1++;
          tempListIndex++;
        }
        else
        {
          temp_list.insert(a_list.getAtPos(first2)->getItem(),tempListIndex);
          first2++;
          tempListIndex++;
        }
      }
      //Fills in the remainder of first1 in case one is larger than the other
      while (first1 <= last1)
      {
        temp_list.insert(a_list.getAtPos(first1)->getItem(),tempListIndex);
        first1++;
        tempListIndex++;
      }
      while (first2 <= last2)
      {
        temp_list.insert(a_list.getAtPos(first2)->getItem(),tempListIndex);
        first2++;
        tempListIndex++;
      }      
      //remove the unordered items in a_list and replace them with the ordered items.
      int i = 1;
      for (int index = left_index; index <= right_index; index++)
      {
        a_list.remove(index);
        a_list.insert(temp_list.getAtPos(i)->getItem(), index);
        i++;
      }
    }

    /* Mergesort */
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index, const Comparator &comp)
    {
      if (left_index < right_index)
      {
        int middle_index = left_index + (right_index - left_index) / 2;
        mergeSort(a_list, left_index, middle_index, comp);
        mergeSort(a_list, middle_index + 1, right_index, comp);
        merge(a_list, left_index, middle_index, right_index, comp);
      }
    }

    /* Mergesort Wrapper */
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
      int size = a_list.getSize();
      if (size > 1)
      {
        int left_index = 1;
        mergeSort(a_list, left_index, size, comp);
      }
    }
 }; // namespace solutions

/* DO NOT USE THESE: 
    * Shellsort *
    template <typename Comparable, typename Comparator>
    void shellSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
    }
    * Quicksort *
    template <typename Comparable, typename Comparator>
    void quicksort(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index, const Comparator &comp)
    {
    }
    * Quicksort Wrapper *
    template <typename Comparable, typename Comparator>
    void quickSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
    }
*/
