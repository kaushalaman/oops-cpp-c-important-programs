/* Program to remove duplicates in an unsorted array */
 
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
 int data;
 struct node *next;
};
 
/* Function to remove duplicates from a unsorted linked list */
void removeDuplicates(struct node *start)
{
  struct node *ptr1, *ptr2, *dup;
  ptr1 = start;
 
  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
 
     /* Compare the picked element with rest of the elements */
     while(ptr2->next != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1->data == ptr2->next->data)
       {
          /* sequence of steps is important here */
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          free(dup);
       }
       else /* This is tricky */
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct node** head_ref, int new_data);
 
/* Function to print nodes in a given linked list */
void printList(struct node *node);
 
/* Druver program to test above function */
int main()
{
  struct node *start = NULL;
 
  /* The constructed linked list is:
   10->12->11->11->12->11->10*/
  push(&start, 10);
  push(&start, 11);
  push(&start, 12);
  push(&start, 11);
  push(&start, 11);
  push(&start, 12);
  push(&start, 10);
 
  printf("\n Linked list before removing duplicates ");
  printList(start);
 
  removeDuplicates(start);
 
  printf("\n Linked list after removing duplicates ");
  printList(start);
 
  getchar();
}
 
/* Function to push a node */
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