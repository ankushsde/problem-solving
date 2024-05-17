 

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return checker(root, target);
    }

private:
    TreeNode* checker(TreeNode* root, int target) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* l = checker(root->left, target);
        TreeNode* r = checker(root->right, target);
        if (root->val == target && l == nullptr && r == nullptr) {
            return nullptr;
        } else if (root->val == target && l == nullptr) {
            return new TreeNode(root->val, nullptr, r);
        } else if (root->val == target && r == nullptr) {
            return new TreeNode(root->val, l, nullptr);
        } else {
            return new TreeNode(root->val, l, r);
        }
    }
};
