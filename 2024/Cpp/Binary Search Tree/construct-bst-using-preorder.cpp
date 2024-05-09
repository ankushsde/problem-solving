// brute force:
//approach : 
// use preorder property and create the Binary tree, i.e root, left, right
// TC: O(N*N) SC:O(N)

//better
//approach : 
// from the preorder array that is given to us, we'll generate a inorder 
// to generate inorder from existing preorder, just simply sort, we get left,root,right
// and we can construct a unique binary tree using preorder and inorder

// TC: O(nlogn)--> for sorting + O(n)
// SC: O(n), we'll be storing inorder traversal

//optimal 
//approach: 
// we'll use the approach of cheking if a BT is BST
// before visiting every node, a range is assigned to it. Upper bound of the range is passed as parameters to the function. 
// set it to be INT_MAX. 
// keep checking on the left and right
// on left we'll be updating upper bound to be the root val

// TC: O(3N), it will be near about O(N), since we are visting every node three time, root,left,right
// No extra space is used, the SC : O(1) 

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; 
        return build(preorder,i ,INT_MAX);
    }
    TreeNode* build(vector<int>& A, int &i, int bound){
        if(i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A,i,root->val);
        root->right = build(A,i,bound);
        return root;
    }
};