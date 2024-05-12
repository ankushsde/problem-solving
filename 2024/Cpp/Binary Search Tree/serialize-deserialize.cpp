/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Apprach : Using Level order traversal
    // TC: O(N),SC:O(N)
    // Encodes a tree to a single string.
    // this function takes root and return string 
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = '';
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode == NULL) s.append("#,");
            else s.append(to_string(curNode->val) +"," )
            if(curNode != Null){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() ==  NULL) return NULL;
        stringStream s(data);
         string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")node->left=NULL;
            else{
                TreeNode* leftn=new TreeNode(stoi(str));
                node->left=leftn;
                q.push(leftn);
            }

            getline(s,str,',');
            if(str=="#")node->right=NULL;
            else{
                TreeNode* rightn=new TreeNode(stoi(str));
                node->right=rightn;
                q.push(rightn);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));