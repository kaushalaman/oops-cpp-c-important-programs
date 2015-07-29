#include<stdio.h>
#include<limits.h>
 
/* A tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
// A utility function that prints all nodes on the path from root to target_leaf
bool printPath (struct node *root, struct node *target_leaf)
{
    // base case
    if (root == NULL)
        return false;
 
    // return true if this node is the target_leaf or target leaf is present in
    // one of its descendants
    if (root == target_leaf || printPath(root->left, target_leaf) ||
            printPath(root->right, target_leaf) )
    {
        printf("%d ", root->data);
        return true;
    }
 
    return false;
}
 
// This function Sets the target_leaf_ref to refer the leaf node of the maximum 
// path sum.  Also, returns the max_sum using max_sum_ref
void getTargetLeaf (struct node *node, int *max_sum_ref, int curr_sum,
                   struct node **target_leaf_ref)
{
    if (node == NULL)
        return;
 
    // Update current sum to hold sum of nodes on path from root to this node
    curr_sum = curr_sum + node->data;
 
    // If this is a leaf node and path to this node has maximum sum so far,
    // then make this node target_leaf
    if (node->left == NULL && node->right == NULL)
    {
        if (curr_sum > *max_sum_ref)
        {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = node;
        }
    }
 
    // If this is not a leaf node, then recur down to find the target_leaf
    getTargetLeaf (node->left, max_sum_ref, curr_sum, target_leaf_ref);
    getTargetLeaf (node->right, max_sum_ref, curr_sum, target_leaf_ref);
}
 
// Returns the maximum sum and prints the nodes on max sum path
int maxSumPath (struct node *node)
{
    // base case
    if (node == NULL)
        return 0;
 
    struct node *target_leaf;
    int max_sum = INT_MIN;
 
    // find the target leaf and maximum sum
    getTargetLeaf (node, &max_sum, 0, &target_leaf);
 
    // print the path from root to the target leaf
    printPath (node, target_leaf);
 
    return max_sum;  // return maximum sum
}
 
/* Utility function to create a new Binary Tree node */
struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* Driver function to test above functions */
int main()
{
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);
 
    getchar();
    return 0;
}