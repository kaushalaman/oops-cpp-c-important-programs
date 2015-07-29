/* This program swaps the nodes of linked list rather than swapping the
field from the nodes.
Imagine a case where a node contains many fields, there will be plenty
of unnecessary swap calls. */
 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to pairwise swap elements of a linked list */
void pairWiseSwap(struct node **head)
{
    // If linked list is empty or there is only one node in list
    if (*head == NULL || (*head)->next == NULL)
        return;
 
    // Initialize previous and current pointers
    struct node *prev = *head;
    struct node *curr = (*head)->next;
 
    *head = curr;  // Change head before proceeeding
 
    // Traverse the list
    while (true)
    {
        struct node *next = curr->next;
        curr->next = prev; // Change next of current as previous node
 
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
 
        // Change next of previous to next next
        prev->next = next->next;
 
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
}
 
/* Function to add a node at the begining of Linked List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
 
    pairWiseSwap(&start);
 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
 
    getchar();
    return 0;
}