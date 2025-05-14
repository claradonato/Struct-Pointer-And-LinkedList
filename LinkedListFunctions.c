#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

List *createList(){
    List *newList = (List*)malloc(sizeof(List));
    newList->size = 0;
    newList->head = NULL;
}

Node *packValue(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(List *list){
    if(list->size == 0){
        printf("Empty list.\n");
        return;
    }

    Node *pointer = list->head;
    while(pointer != NULL){
        printf("%d - ", pointer->value);
        pointer = pointer->next;
    }
    printf("\n");
}

void add(List *list, int value){
    Node *new = packValue(value);
    if (list->size == 0){
        list->head = new;
        new->next = NULL;
    } else {
        Node *ptr = list->head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = NULL;
    }
    list->size++;
}

void addpos(List *list, int pos, int value){
    if(pos < 0){ //verifica se é uma posicao negativa
        printf("Posicao invalida\n");
        return;
    }

    Node *new = packValue(value);
    if(pos > (list->size + 1)){ //verifica se a posição é dois números maior ou mais do tamanho da lista
        printf("Posicao nao existente\n");
        return;
    }
    if(pos == 0){ //se tenho que adicionar no head
        new->next = list->head;
        list->head = new;
        return;
    }

    Node *ptr = list->head; //se a posição for maior do que zero
    int i = 0;
    while(i != pos-1){
        ptr = ptr->next;
        i++;
    }
    new->next = ptr->next; //se foi adicionado na ultima posicao, o next é NULL
    ptr->next = new; 
}

//copy array to list
void catl(List *list, int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        Node *new = packValue(array[i]);
        if(list->size == 0){
            list->head = new;
        } else {
            Node *ptr = list->head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = new;
        }
        list->size++;
    }
}

void explist(List *list, int *array, int array_size){
    if(list->size == 0){ //se lista estiver vazia
        return;
    }

    Node *ptr = list->head;
    for(int i = 0; i < list->size; i++){
        array[array_size] = ptr->value;
        ptr = ptr->next;
        array_size++;
    }
}
