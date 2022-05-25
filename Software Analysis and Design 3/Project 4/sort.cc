/**
 * @sort.cc
 * @Shourov Saha (shourov.saha85@myhunter.cuny.edu)
 * @Implementation of the functions declared by the sort.h
 * @version 0.1
 * @04-29-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sort.h"
#include <iostream>
#include <utility> // for std::swap(), etc.
using namespace std;

template <typename Comparable>
void selection_sort(Comparable arr[], int asize)
{
	// sort all the info in arr (total size: asize) from smallest to largest.
	int nsort = 0; // size of the sorted section.

	while (nsort < asize)
	{
		int spos = findsmallest(arr, nsort, asize - 1);
		swap(arr, spos, nsort); // interchange the 2 values.
		++nsort;
	}
}

template <typename Comparable>
void insertion_sort(Comparable arr[], int asize)
{
	int nsort = 0; // size of the sorted section.

	while (nsort < asize)
	{
		Comparable copy = std::move(arr[nsort]);
		int pos = findpos(arr, copy, nsort);
		// pos is the position for copy.
		// nsort is size of sorted values.

		moveup1(arr, pos, nsort - 1);
  		// move data from pos to nsort-1 inclusive.  

		arr[pos] = std::move(copy);
		++nsort;
	}
}

// 'a' is an array of 'Items' whose valid elements are between 'start' and 'end', inclusively.
// 'mid' is the position in 'a' in which to divide the array.
template <typename Comparable>
void merge_sort(Comparable a[], int start, int end, int mid)
{

	if (start >= end) // the array is either   empty or contains a single element.
		return;		  // sorting problem already solved. Nothing to do.

	// sort the left portion of the array.
	merge_sort(a, start, mid, (start + mid) / 2);

	// sort the right portion of the array
	merge_sort(a, mid + 1, end, (mid + 1 + end) / 2);

	// combined the two sorted array portions in a single sorted array.
	merge(a, start, end, mid);
}

// Returns the position of the smallest Comparable in arr from start to end inclusive
// @pre start <= end
template <typename Comparable>
int findsmallest(const Comparable arr[], int start, int end)
{
	int position = start;
  for (int i = start; i <= end; i++) {
    if (arr[i] < arr[position])
      position = i;
  }
  return position;
}

// Swaps the element at position pos1 with the element at position pos2 in arr.
template <typename Comparable>
void swap(Comparable arr[], int pos1, int pos2)
{
  // temporary variable to hold arr[pos1]
  Comparable temp = arr[pos1];
  arr[pos1] = arr[pos2];
  // replace arr data at pos2 with temp
  arr[pos2] = temp;
}

// Returns the position, between 0 and size, in arr to insert the target value in insertion sort.
// Linear time
template <typename Comparable>
int findpos(const Comparable arr[], Comparable target, int size)
{
  // Loop through the bounds 0,size and check if data at position is greater than target.
	for (int i = 0; i < size; i++) {
    if (arr[i] > target) 
      return i;
  }
}

// Moves up all data in arr from start to end inclusive one space.
// Linear complexity
template <typename Comparable>
void moveup1(Comparable arr[], int start, int end)
{
  int index = start;
  // temp comparable array to store the data
  Comparable tempArr[end-start+2];
  // places the contents of arr within the bounds into new arr, incrementing downwards
  for (int i = 1; i < end-start+2; i++) {
    tempArr[i] = arr[index];
    index++;
  }
  // replaces all the contents within the bounds with contents of tempArr.
  index = 0;
  for (int i = start; i <= end + 1; i++) {
    arr[i] = tempArr[index];
    index++;
  }
}

// Combines two sorted sub-arrays of arr (i.e., the inclusive intervals [left, pivot] and [pivot+1, right])
// to a single sorted array.  
template <typename Comparable>
void merge(Comparable arr[], int left, int right, int pivot) {
  // First and last of the first sub-array
  int first1 = left;
  int last1 = pivot;
  
  // First and last of the second sub-array
  int first2 = pivot + 1;
  int last2 = right;
  
  // Array and its index
  size_t tempIndex = 0;
  Comparable tempArr[right-left+1];
  
  // Orders arr from first1 to last2 first1;
  while ((first1 <= last1) && (first2 <= last2))
  {
    if (arr[first1] < arr[first2]) // Place data from first sub-array into the tempArr and increment the indexes
    {
      tempArr[tempIndex] = arr[first1];
      first1++;
      tempIndex++;
    }
    else // Place data from second sub-array into the tempArr and increment the indexes
    {
      tempArr[tempIndex] = arr[first2];
      first2++;
      tempIndex++;
    }
  }
  
  // Fills in the remainder of first1 or first 2 in case one is larger than the other
  while (first1 <= last1)
  {
    tempArr[tempIndex] = arr[first1];
    first1++;
    tempIndex++;
  }
  while (first2 <= last2)
  {
    tempArr[tempIndex] = arr[first2];
    first2++;
    tempIndex++;
  }
  
  // Remove the unordered items in arr and replace them with the ordered items in temp arr.
  tempIndex = 0;
  for (int index = left; index <= right; index++)
  {
    arr[index] = tempArr[tempIndex];
    tempIndex++;
  }
}

// Template instantiations. Only ints are supported for now. Do not change these but add more instantiations
// for other types if you like.
template void selection_sort<int>(int[], int);
template int findsmallest<int>(const int[], int, int);
template void insertion_sort<int>(int[], int);
template void merge_sort<int>(int[], int, int, int);
