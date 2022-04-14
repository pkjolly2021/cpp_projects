/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//revers a string using recursion


//reverse and print a linked list in c.
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//using namespace std;

//Hello

//olleH


typedef struct link
{
    int data;
    struct link *next;
}llist;

llist *head = NULL;

void add_node(int data)
{
    if(head == NULL)
    {
       head = (llist*)malloc(sizeof(llist));    
       head->data = data;
       head->next = NULL;
    }
    else
    {
        llist *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        llist *new_node = (llist*)malloc(sizeof(llist));
        new_node->data = data;
        temp->next = new_node;
        new_node->next = NULL;
    }
}

void print(void)
{
    
    llist *temp = head;
    while (temp->next  != NULL)
    {
        printf("data is: %d",temp->data );
                printf("\n" );
        temp = temp->next;
    }
      printf("data is: %d",temp->data );
}

void print_rev(llist *node)
{
   if(node->next  != NULL)
   {
       print_rev(node->next);
     //printf("%d", node->data);
   }
    printf("rev data = %d \n", node->data);
}

int main()
{
    printf("%s", "INSIDE MAIN");
    add_node(10);
    add_node(20);
    add_node(30);
    add_node(40);
   // print();
   print_rev(head);
    return 0;
}
