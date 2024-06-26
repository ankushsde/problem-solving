// revisited once 
// logic is simple we'll pick a range as we know
// left<root<right
// validate(root,minVal,maxVal)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
         return validate(root, LLONG_MIN, LLONG_MAX);
    }

    bool validate(TreeNode* node, long long minVal, long long maxVal){
        if (node == nullptr) return true; // Base case: empty tree is a valid BST
        if (node->val <= minVal || node->val >= maxVal) return false; // Check if current node violates BST property
        
        // Recursively validate left and right subtrees
        return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
    }
};