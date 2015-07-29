/* C++ program to convert left-right to down-right representation
   of binary tree */
#include <iostream>
#include <queue>
using namespace std;
 
// A Binary Tree Node
struct node
{
    int key;
    struct node *left, *right;
};
 
// An Iterative level order traversal based function to convert
// left-right to down-right representation.
void convert(node *root)
{
    // Base Case
    if (root == NULL)  return;
    queue<node *> q;
    q.push(root);
    node *firstnode = root;
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
        node *prev = NULL;  // Stores link of previously dequeued node.
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            // Dequeue a node and enqueue its children for next
            // iteration of outer loop
            node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
 
            // If prev exists, then connect this node as right
            // sibling of prev.
            if (prev)
            {
                prev->right = node;
 
             // Since prev is not NULL, this is not the first node
             // of its level, so make the down (or left) pointer NULL
                node->left = NULL;
            }
 
            // If previous doesn't exist then link this node as down to
            // first node of previous level. And set the firstnode
            else
            {
                firstnode->left = node;
                firstnode = node;
            }
 
            // Update prev and nodecount
            prev = node;
            nodeCount--;
        }
        prev->right = NULL; // For last node in current level
    }
}
 
//A utility function to traverse a tree stored in down-right form.
void downRightTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        downRightTraversal(root->right);
        downRightTraversal(root->left);
    }
}
 
// Utility function to create a new tree node
node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
 
    convert(root);
 
    cout << "Traversal of the tree converted to down-right form\n";
    downRightTraversal(root);
 
    return 0;
}