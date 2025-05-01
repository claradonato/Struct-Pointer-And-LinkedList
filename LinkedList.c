#include <stdio.h>
#include <stdlib.h>
#include "LinkedListStructs.h"

List *createList() {
    List *newList = (List *)malloc(sizeof(List));
    newList->size = 0;
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void add(int value, List *list) {
    Node *newNode = createNode(value);
    if (list->size < 0) return;

    if (list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

void addAt(int value, int position, List *list) {
    Node *newNode = createNode(value);
    if (position < 0 || position > list->size || list->size == 0) return;

    if (position == 0) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else {
        Node *aux = list->head;
        for (int i = 0; i < list->size; i++) {
            if (i == position - 1) {
                newNode->next = aux->next;
                newNode->prev = aux;
                if (aux->next != NULL) {
                    aux->next->prev = newNode;
                }
                aux->next = newNode;
                break;
            }
            aux = aux->next;
        }
    }
    list->size++;
}

List *sliceList(int startIndex, int endIndex, List *source, List *destination) {
    Node *current = source->head;

    if (endIndex > source->size || startIndex < 0 || startIndex > endIndex) {
        printf("Invalid range!\n");
        return NULL;
    }

    for (int i = 0; i < startIndex; i++) {
        current = current->next;
    }

    for (int i = startIndex; i <= endIndex; i++) {
        add(current->value, destination);
        current = current->next;
    }

    printf("Cloned list:\n");
    printList(destination);

    return destination;
}

void bubbleSort(List *list) {
    if (list->size < 2) return;

    int swapped;
    Node *ptr;
    Node *last = NULL;

    do {
        swapped = 0;
        ptr = list->head;

        while (ptr->next != last) {
            if (ptr->value > ptr->next->value) {
                int temp = ptr->value;
                ptr->value = ptr->next->value;
                ptr->next->value = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;

        printf("After one bubble sort iteration:\n");
        printList(list);

    } while (swapped);
}

int countElements(List *list) {
    Node *current = list->head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void searchElement(List *list, int value) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->value == value) {
            printf("Found\n");
            return;
        }
        current = current->next;
    }
    printf("Not found\n");
}

void copyFromArray(List *list, int *array, int size) {
    for (int i = 0; i < size; i++) {
        Node *newNode = createNode(array[i]);
        if (list->size == 0) {
            list->head = newNode;
            list->tail = newNode;
        } else {
            list->tail->next = newNode;
            newNode->prev = list->tail;
            list->tail = newNode;
        }
        list->size++;
    }
    printf("Copied from array\n");
}

void exportToArray(List *list, int *array) {
    Node *current = list->head;
    int index = 0;
    while (current != NULL) {
        array[index++] = current->value;
        current = current->next;
    }
    printf("Exported to array\n");
}

int main(void) {
    //Question 1
    List *myList = createList();
    add(30, myList);
    add(20, myList);
    add(10, myList);
    printList(myList);

    //Question 2
    printf("Size: %d\n", countElements(myList));
    searchElement(myList, 20);

    //Question 3
    int arr[] = {0, -10, -20};
    copyFromArray(myList, arr, 3);
    printList(myList);

    //Question 4
    int outputArr[6];
    exportToArray(myList, outputArr);
    printf("Array contents:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", outputArr[i]);
    }
    printf("\n");

    free(myList);
}