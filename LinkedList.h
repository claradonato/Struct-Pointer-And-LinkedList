#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct List{
    int size;
    Node *head;
} List;

List *createList();
Node *packValue(int value);
void printList(List *list);
void add(List *list, int value);
void addpos(List *list, int pos, int value);
void catl(List *list, int *array, int array_size);
void explist(List *list, int *array, int array_size);

#endif