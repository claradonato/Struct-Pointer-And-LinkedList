#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedListStructs.h"

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


//questão 1
int countElements(List *list) {
    Node *current = list->head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//questão 2
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

//questao 3
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

//questao 4
void exportToArray(List *list, int *array) {
    Node *current = list->head;
    int index = 0;
    while (current != NULL) {
        array[index++] = current->value;
        current = current->next;
    }
    printf("Exported to array\n");
}

//questao 5
Node *createCopyOfList(Node *head){
    if(head == NULL){
        return head;
    }

    Node *current = head;
    Node *newHead = NULL;
    Node *newTail = NULL;

    while(current != NULL){
        // Create a new node with the same data
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        if (newNode == NULL) {
            return NULL;
        }

        newNode->value = current->value;
        newNode->next = NULL;

        if (newHead == NULL) {
            // If the new list is empty, set the new node as the head
            newHead = newNode;
            newTail = newNode;
        } else {
            // Otherwise, add the new node to the end of the list
            newTail->next = newNode;
            newTail = newNode;
        }
        // Move to the next node in the original list
        current = current->next;
    }
    return newHead;
}

//questao 6
void concatLists(List *list1, List *list2){
    if(list1->head == NULL){
        printf("List 1 is empty\n");
        return;
    }

    if(list2->head == NULL){
        printf("List 2 is empty\n");
        return;
    }

    list1->tail->next = list2->head;
    list1->tail = list2->tail;
}

//questao 7
List *invertList(List *list){
    if (list == NULL || list->size < 2) return list;

    Node *current = list->head;
    Node *temp = NULL;

    // Inverte os ponteiros de cada nó
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // agora prev aponta para o próximo
    }

    // Troca head e tail
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

    return list;
}

//questao 8
void equalLists(List *list1, List *list2){
    if(list1->size != list2->size){
        printf("Not equal\n");
        return;
    }

    Node *ptrList1 = list1->head;
    Node *ptrList2 = list2->head;

    while(ptrList1 != NULL){
        if(ptrList1->value != ptrList2->value){
            printf("Not equal\n");
            return;
        }
        ptrList1 = ptrList1->next;
        ptrList2 = ptrList2->next;
    }

    printf("Equal!\n");

}

