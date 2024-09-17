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
 
    void inOrder(TreeNode* root, vector<int> &temp){
         if(root){
            inOrder(root->left, temp);
            temp.push_back(root->val);
            inOrder(root->right, temp);
        }
    }

 
    TreeNode* buildTree(int s,int e, vector<int> &temp){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(temp[mid]);
        root->left = buildTree(s,mid-1, temp);
        root->right = buildTree(mid+1,e,temp);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> temp;
        inOrder(root,temp);
        return buildTree(0, temp.size()-1, temp);
    }
};