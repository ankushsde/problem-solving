 //Brute force : 
 //Approach , Initially validate if it is BST, if yes, then start with the root and recursively explore left and right subtrees, updating the maximum sum along the way.
 //TC:O(N) for validating a BST and O(N) for traversal, overall TC will be O(N^2)
 //SC: auxiliary stack space

class Solution {
public:

    bool validateBST(TreeNode* root, long long minVal, long long maxVal){
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return validateBST(root->left,minVal,root->val) && validateBST(root->right, root->val, maxVal);
        
    };

    bool isBST(TreeNode* root){
        return validateBST(root, LLONG_MIN, LLONG_MAX);
    }

    int sumTree(TreeNode* root){
        if(root==NULL) return 0;
        return root->val + sumTree(root->left) + sumTree(root->right);
    }

    int maxi = 0; 

    int maxSumBST(TreeNode* root) {
       if(root == NULL) return 0;
       if(isBST(root)){
        maxi = max(maxi,sumTree(root));
       }
        maxSumBST(root->left);
        maxSumBST(root->right);
        return maxi;
    }
};

 

// Better: 
// Approach & BST brush up: 
// In a Binary Search Tree (BST), smaller nodes are typically on the left, larger nodes on the right.
// We can validate a BST by ensuring the root lies between the smallest node on the right and the largest node on the left.
// To find the maximum sum of a BST:
// Traverse the tree in a post-order manner (left, right, root).
// Consider both left and right subtrees to compute the maximum sum.
// We track three main variables:
// minNode: Minimum node value encountered.
// maxNode: Maximum node value encountered.
// maxSize: Size of the largest BST encountered so far.
// TC: O(N) SC: O(1)

class NodeValue{

    public: 
    int minNode, maxNode, maxSize;
    NodeValue (int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize; 
    }
};

class Solution {
private:
  
  NodeValue largestBSTHelper(TreeNode* root){
    if(!root){ 
        return NodeValue(INT_MAX,INT_MIN,0);
        }
  
    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);

    if(left.maxNode < root->val && root->val < right.minNode){
        return NodeValue(min(root->val,left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1 );
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
  
  };


 public:
  int maxSumBST(TreeNode* root) {
    return largestBSTHelper(root).maxSize;
  } 
};