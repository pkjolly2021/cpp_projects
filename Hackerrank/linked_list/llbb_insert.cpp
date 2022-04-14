/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class ddllnode
{
    public:
    ddllnode *prev;
    ddllnode *next;
    int data;
    ddllnode(int dat):data(dat)
    {
        prev = nullptr;
        next = nullptr;
    }
};

#if 0
void sortedInsert(struct Node* head_ref, struct Node* newNode)
{
    newNode = 
    struct Node* current;
 
    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newNode;
 
    // if the node is to be inserted at the beginning
    // of the doubly linked list
    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }
 
    else {
        current = *head_ref;
 
        // locate the node after which the new node
        // is to be inserted
        while (current->next != NULL &&
               current->next->data < newNode->data)
            current = current->next;
 
        /* Make the appropriate links */
        newNode->next = current->next;
 
        // if the new node is not inserted
        // at the end of the list
        if (current->next != NULL)
            newNode->next->prev = newNode;
 
        current->next = newNode;
        newNode->prev = current;
    }
}
#endif

void prnit_ll_reverse(ddllnode *curr_node)
{

    while(curr_node->next != nullptr)
    {
     //   curr_node = curr_node->next;
        prnit_ll_reverse(curr_node->next);
    }
    std::cout<<"Data revrse order is: "<< curr_node->data;

}

//returnn head of ll
ddllnode*  inset_sort(ddllnode *node, int dat)
{
    ddllnode *head = node;
    if(node == nullptr)
    {
        ddllnode *new_node {new ddllnode(dat)}; // if no link 
        node = new_node;
        return(node);
    }
    // insert before head
    else if(node->data > dat)
    {
        ddllnode *new_node {new ddllnode(dat)};
        new_node->next = node;
        new_node->next->prev = new_node;
        return(new_node);
    }
    //else inser in between
    else
    {
        ddllnode *new_node {new ddllnode(dat)};
        while((node->next != nullptr) &&(node->next->data < dat))
        {
            node = node->next;
        }
        new_node->next = node->next;

         if (new_node->next != nullptr)
         {
             node->next->prev = new_node;
         }
         node->next = new_node;
         new_node->prev = node;
     
         return head;
         
    }

}

void print(ddllnode *node)
{
    while(node !=nullptr)
    {
        std::cout<<"\r\n Data is: "<<node->data;
        node = node->next;
    }
}

int main()
{
    ddllnode *head = nullptr;

    head = inset_sort(nullptr, 7);
    head = inset_sort(head, 2);
    //head = inset_sort(head, 1);

     head = inset_sort(head, 4);
            head = inset_sort(head, 3);
       head = inset_sort(head, 1);
      //  head = inset_sort(head, 0);
          head = inset_sort(head, 5);
     head = inset_sort(head,6);

    print(head);

    prnit_ll_reverse(head);
    

    return 0;
}
