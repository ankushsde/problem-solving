// //  Approach, using Level order traversal
// Max width of the tree
// what if we find out the maximum width at each level ? 

// :: // edge cases :  
// :: // approach : last -first + 1
// we'll find the width at each level, using variables like first and last, where first pointing to ind == 0, last = size -1 at each level,
// use a queue to store all teh nodes and the index attched to them. initiallly q.push({root,0}) 
// on every level we'll find the minimum Index to avoid overflow condition, 
// int mmin = q.front().second;
// loop through the queue, and keep updating the ans = max(ans, last-first+1)

// :: // TC & SC :  O(N) + O(N)
// :: // code : 

// revisited once

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
         if(!root) return 0;
         int ans = 0;

         queue<pair<TreeNode*, int>> q;
         q.push({root,0});
         while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
             
            for(int i = 0; i<size; i++){
                int cur_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i == size - 1) last = cur_id;
                if(node->left)
                 q.push({node->left,cur_id*2+1});
                if(node->right)
                 q.push({node->right,cur_id*2+2});
            }
            ans =  max(ans,last-first+1);
         }
         return ans;
    }
 };
 

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
         if(!root) return 0;
         int ans = 0;

         queue<pair<TreeNode*, long long>> q; // Change to long long
         q.push({root,0});
         while(!q.empty()){
            int size = q.size();
            long long mmin = q.front().second; // Change to long long
            long long first, last; // Change to long long
             
            for(int i = 0; i<size; i++){
                long long cur_id = q.front().second-mmin; // Change to long long
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i == size - 1) last = cur_id;
                if(node->left)
                 q.push({node->left,cur_id*2+1});
                if(node->right)
                 q.push({node->right,cur_id*2+2});
            }
            ans =  max(ans,static_cast<int>(last-first+1)); // Ensure ans is of type int
         }
         return ans;
    }
};
