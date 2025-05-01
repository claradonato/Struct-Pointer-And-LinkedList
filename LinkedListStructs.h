#ifndef LINKEDLISTSTRUCTS_H
#define LINKEDLISTSTRUCTS_H

typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    int size;
    Node *head;
    Node *tail;
} List;

// Creates and returns a new empty list
List *createList();

// Prints the elements of the list
void printList(List *list);

// Adds a new value at the end of the list
void add(int value, List *list);

// Adds a new value at a specific position in the list
void addAt(int value, int position, List *list);

// Creates a sublist from index start to end (inclusive) and stores it in destination
List *sliceList(int startIndex, int endIndex, List *source, List *destination);

// Sorts the list using bubble sort algorithm
void bubbleSort(List *list);

// Counts and returns the number of elements in the list
int countElements(List *list);

// Searches for a value in the list and prints if it belongs or not
void searchElement(List *list, int value);

// Copies values from an integer array into the list
void copyFromArray(List *list, int *array, int size);

// Exports values from the list into an integer array
void exportToArray(List *list, int *array);

#endif
