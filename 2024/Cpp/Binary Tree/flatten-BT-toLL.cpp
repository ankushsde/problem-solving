//Approach 1: Recurssion 
//observe the result, we can play around the left and right node, 
//you'll find we need to move nodes, right, left,root, which we can say reverse postorder.
//take a reference variable (say prev) to store the previous node( initialized to NULL).
//whenever we visit a node, we set the right child to the prev and left child to NULL. 
//next we assign this current node to prev.
//perform the above two operations on all the nodes in the traversal.
//TC: O(N), SC:O(N)

class Solution {
    TreeNode* prev = NULL; 
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Approach 2 : Iterative way using a stack
//TC and SC will be similar to recusrion approach
// take a stack and push the root node to it.
// set a while loop till the stack is non-empty.
// In every iteration, take the node at the top of the stack( say cur) and pop the stack.
// If cur has a right child, push it to the stack.
// If cur has a left child, push it to the stack.
// set the right child of cur to node at stack’s top.
// set the left child of cur as NULL.



// Approach 3 : Using Morris traversal technique, SC:O(1), TC:O(N)
// At a node(say cur) if there exists a left child, we will find the rightmost node in the left subtree(say prev).
// We will set prev’s right child to cur’s right child,
// We will then set cur’s right child to it’s left child.
// We will then move cur to the next node by assigning cur it to its right child
// We will stop the execution when cur points to NULL.
