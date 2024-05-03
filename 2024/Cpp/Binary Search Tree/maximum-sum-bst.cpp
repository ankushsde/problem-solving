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

    //1.
    struct MyNode{

        int maxNode, minNode, maxSum;

        MyNode(int maxNode, int minNode, int maxSum){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSum = maxSum;
        }
    };

    //2.
    int MAX_SUM = INT_MIN;

    //3.
    MyNode getMaxSum(TreeNode* root) {
        
        if(!root) return MyNode(INT_MIN, INT_MAX, 0); // if it is null node always BST

        MyNode myLeftNode = getMaxSum(root->left);
        MyNode myRightNode = getMaxSum(root->right);

        if(myLeftNode.maxNode < root->val && root->val < myRightNode.minNode){ // if it is BST
 
            MAX_SUM = max(MAX_SUM, myLeftNode.maxSum + myRightNode.maxSum + root->val);
            
            return MyNode(
                    max(root->val, myRightNode.maxNode), 
                    min(root->val, myLeftNode.minNode),
                    myLeftNode.maxSum + myRightNode.maxSum + root->val
                );
        }

        return MyNode(INT_MAX, INT_MIN, 0); // if it is not BST
    }

public:
    int maxSumBST(TreeNode* root) {
        MyNode node = getMaxSum(root);
        return (MAX_SUM < 0)? 0 : MAX_SUM;
    }
};