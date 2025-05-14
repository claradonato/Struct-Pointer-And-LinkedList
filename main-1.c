#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
    List *newList = createList();
    add(newList, 1);
    add(newList, 2);
    printList(newList);
    int array[10] = {3, 4, 5}; //ação futura: adicionar um realloc() na função para nao pré-determinar o tamanho do array
    explist(newList, array, 3);
    for(int i = 0; i < 3 + newList->size; i++){
        printf("%d ", array[i]);
    }

    free(newList);
    return 0;
}