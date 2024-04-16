/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private: void inOrder ( TreeNode* node, int &counter, int k, int &kSmallest ){
    if(!node || counter >=k) return;
    inOrder(node->left,counter,k,kSmallest);
    counter++;
    if(counter == k){
        kSmallest = node->val;
        return;
    }
    inOrder(node->right,counter, k, kSmallest);
}


public:
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest = INT_MIN;
        int counter = 0;

        inOrder(root,counter,k,kSmallest);
        return kSmallest;
    }
};