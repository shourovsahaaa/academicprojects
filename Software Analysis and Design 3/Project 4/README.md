 [![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7753307&assignment_repo_type=AssignmentRepo)
# Assignment 4

This assignment contains C++ code implementing selection sort, insertion sort, and merge sort algorithms. The functions can be used to sort arrays holding any comparable data type. 

The sort functions are listed below:
  1. void selection_sort(Comparable arr[], int asize)
  2. void insertion_sort(Comparable arr[], int asize)
  3. void merge_sort(Comparable a[], int start, int end, int mid)

The code also includes a few other helper functions listed below:
  1. int findsmallest(const Comparable arr[], int start, int end)
  2. void swap(Comparable arr[], int pos1, int pos2)
  3. void moveup1(Comparable arr[], int start, int end)
  4. void merge(Comparable arr[], int left, int right, int pivot)
  

Instructions on how to compile and run the code are listed below.

## To Compile

The command:

```bash
make
```

will produce the library file `sort.o` and executable `sort_driver`.


## To Run

```bash
./sort_driver
```
