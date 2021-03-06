/*******************************************************************************************
* File Name          : assign1skeleton.c
* Description        : Prog8130 - Assignment 1: Linked Lists
*                      This program uses linked lists to hold and print a list of words
*                      organized by order number assosciated with each word. Each word can
*                      consist of maximum 30 characters.
*
* Author:              Gaurav Kalia
* Date:                6th Febuary, 2021
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_DATA_ITEMS   10                               // the number of data items to be used in list
                                                                // should be less than or equal 10

// structure/typedef used for holding data
typedef struct {
    char name[30];
    int  order;
} inputData;

// definition of linked list data nodes
typedef struct LinkedListNode {
    char                            NameData[30];           // the name to be stored
    int                             order;                  // the order to be stored
    struct LinkedListNode           *ptrNextNode;           // pointer to next node in list (NULL if the end)
} LinkedListNodeDef;

// prototypes
LinkedListNodeDef *AddToLinkedList(LinkedListNodeDef *ptrHead, char *NameData, int DataOrder);
LinkedListNodeDef* RemoveFromLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder);
void PrintLinkedList(LinkedListNodeDef *ptrHead);

// data used for test
// start iData
inputData iData[10] = {
    { "kiwi", 1 },
    { "water", 3 },
    { "carrot", 3 },
    { "pickels", 7 },
    { "chocolate", 5 },
    { "fish", 4 },
    { "candy", 7 },
    { "orange", 4 },
    { "airplane", 9 },
    { "butter", 5 }
};
// end iData
// end of data for assignment

// Correct order after inserting into list is:
// kiwi,1
// water,3
// carrot,3 -- will be removed
// orange,4
// fish,4
// butter,5
// chocolate,5
// pickels,7
// candy,7
// airplane,9

// Final output (care for the format! one word each line! and there should be no other output)
// kiwi,1
// water,3
// orange,4
// fish,4
// butter,5
// chocolate,5
// pickels,7
// candy,7
// airplane,9

void main(void) {
    int i;

    // define linked list head
    struct LinkedListNode *ptrHead = NULL;

    // Print out the input data
    printf("Data before Linked List is:\n");
    for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++) {
        printf("%s , %d\n", iData[i].name, iData[i].order);
    }

    // insert the data into Linked List
    for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++) {
        ptrHead = AddToLinkedList(ptrHead, iData[i].name, iData[i].order);
    }

    ptrHead = RemoveFromLinkedList(ptrHead, iData[2].name, iData[2].order);

    // now print out the list in order it is stored starting at head
    printf("Final Output after Data inserted to Linked List is:\n");
    PrintLinkedList(ptrHead);
}

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an order and 
//                 places them in a linked list organized by priority of order number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead   - variable to store address of ptrHead
//                 char *NameData               - Array of Characters with data 
//                 int DataOrder                - Order of the item
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef *AddToLinkedList(LinkedListNodeDef *ptrHead, char *NameData, int DataOrder) {
    // put code in here to add the item(s) to the linked list

    LinkedListNodeDef* newnode = (LinkedListNodeDef*)malloc(sizeof(LinkedListNodeDef));       //Dynamic Allocation of node
    
    newnode->order = DataOrder;
    strcpy(newnode->NameData,NameData);
    newnode->ptrNextNode =NULL;
    if (ptrHead == NULL)
      {
        /* code */
        return newnode;
      }
    struct LinkedListNode* head = ptrHead;                    // Sorting of the Data
    LinkedListNodeDef* ptrpreNode = head;
    while(head->ptrNextNode != NULL)
    {
      if(head->order == DataOrder)                           // Comparing the present node with Data Order
      {
        ptrpreNode->ptrNextNode =newnode;
        newnode->ptrNextNode = head;
        return ptrHead;
      }
      else if(head->order == DataOrder)                     // Comparing the present node with Data Order
      {
        LinkedListNodeDef* var = head->ptrNextNode;
        head->ptrNextNode = var;
        return ptrHead;
      }
      else{
          ptrpreNode = head;
          head = head->ptrNextNode;
      }
    }
    if (head->order >DataOrder )                            
    {
        /* code */
        ptrpreNode->ptrNextNode = newnode;
        newnode->ptrNextNode =head;
        return ptrHead;
    }
    head->ptrNextNode =newnode;
    return ptrHead;
}


// FUNCTION      : RemoveFromLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an order and 
//                 places them in a linked list organized by priority of order number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead   - variable to store address of ptrHead
//                 char *NameData               - Array of Characters with data 
//                 int DataOrder                - Order of the item
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef* RemoveFromLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder) {
    // put code in here to add the item(s) to the linked list
    
    struct LinkedListNode* head = ptrHead;
    LinkedListNodeDef* ptrpreNode = head;
    while(head->ptrNextNode != NULL)
    {
      if ((head->order == DataOrder) & (strcmp(head->NameData,NameData) == 0))                //Comparing the Data order and Name Data
      {
          ptrpreNode->ptrNextNode = head->ptrNextNode;
          free(head);
          return ptrHead;
      }
      ptrpreNode = head;
      head = head->ptrNextNode;
    }
    return ptrHead;
}

// FUNCTION      : PrintLinkedList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//                 and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void PrintLinkedList(LinkedListNodeDef *ptrHead) {
    // put code in here to print the linked list out

     struct LinkedListNode *temp;
    temp = ptrHead;
    while(temp != NULL)
    {
      printf("%s,%d\n",temp->NameData,temp->order);
      temp = temp->ptrNextNode;
    }
}
