// C program to find maximum and minimum in a Bianry Tree
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A tree node
struct node
{
    int data;
    struct node* left, *right;
};

// A utility function to create a new node
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
    // Base case
    if (root == NULL)
      return INT_MIN;

    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}

// Driver program
int main(void)
{
    struct node*NewRoot=NULL;
    struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);

    printf ("Maximum element is %d \n", findMax(root));

    return 0;
}