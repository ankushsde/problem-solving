class Solution{
    
   vector<int> rightSideView( TreeNode* root){
	vector<int> res;
	recursion(root,0,res);
	return res;
}


// TC: O(N)
// SC: O(H)


    public: 
    void recursion (TreeNode* root, int level, vector<int> res){	
	if(root == NULL ) return;
	if(res.size() == level) res.push_back(root->val);
	recursion(root->right, level+1,res);
	recursion(root->left,level+1,res);
}
}