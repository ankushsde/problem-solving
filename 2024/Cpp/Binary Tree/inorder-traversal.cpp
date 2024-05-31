// revisited : once 

class Solution {
public:
  
    void inOrder(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
    }

    vector<int> inorderTraversal(TreeNode* root) {
      vector <int> arr;
      inOrder(root,arr);
      return arr;
     
    }
};

// TC: O(N), SC:O(N)
// these are kinda similars, just remeber this :

//inorder- left root right
//preorder - root left right
//post order - left right root 

// play around these three: inOrder(root->left,arr);
//         arr.push_back(root->val);
//         inOrder(root->right,arr);