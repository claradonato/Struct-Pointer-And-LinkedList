#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedListStructs.h"

int main(void) {

    List *myList = createList();
    add(30, myList);
    add(20, myList);
    add(10, myList);

    List *mySecondList = createList();
    add(30, mySecondList);
    add(20, mySecondList);
    add(10, mySecondList);

    List *myThirdList = createList();
    add(40, myThirdList);
    add(50, myThirdList);
    add(60, myThirdList);

    int arr[] = {0, -10, -20};

    // //Question 1
    // printf("Size: %d\n", countElements(myList));

    // //Question 2
    // searchElement(myList, 20);

    // //Question 3
    // copyFromArray(myList, arr, 3);
    // printList(myList);

    //Question 4
    // int outputArr[6];
    // exportToArray(myList, outputArr);
    // printf("Array contents:\n");
    // for (int i = 0; i < 6; i++) {
    //     printf("%d ", outputArr[i]);
    // }
    // printf("\n");

    // //Question 5
    // Node *newHead = createCopyOfList(mySecondList->head);
    // while(newHead != 0){
    //     printf("%d ", newHead->value);
    //     newHead = newHead->next;
    // }
    // printf("\n");

    // //Question 6
    // concatLists(mySecondList, myThirdList);
    // printList(mySecondList);

    // //Question 7
    // invertList(myList);
    // printList(myList);

    // //Question 8
    // equalLists(myList, mySecondList);
    // printList(mySecondList);

    printList(myThirdList);
    int newNum = 65;
    insElementAscd(newNum, myThirdList);
    printList(myThirdList);

    free(myList);
    free(mySecondList);
    free(myThirdList);
}