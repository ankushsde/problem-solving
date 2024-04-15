 
class Solution {

 void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;

        // Traverse right subtree
        reverseInorder(node->right, counter, k, kLargest);

        // Increment counter after
        // visiting right subtree
        counter++;

        // Check if current node
        // is the Kth largest
        if (counter == k) {
            kLargest = node->val;
            return;
        }

        // Traverse left subtree if
        // Kth largest is not found yet
        reverseInorder(node->left, counter, k, kLargest);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int kLargest = INT_MIN;
        int counter = 0;

        reverseInorder(root,counter,k,kLargest);
        return kLargest;
    }
};