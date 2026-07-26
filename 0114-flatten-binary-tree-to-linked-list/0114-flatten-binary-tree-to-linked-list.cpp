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
public:
    void pre(TreeNode* root,vector<TreeNode *>&node){
        if(!root){
            return;
        }

        node.push_back(root);
        pre(root->left,node);
        pre(root->right,node);
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        vector<TreeNode*>node;
        pre(root,node);
        for(int i=0;i<node.size()-1;i++){
            node[i]->left=nullptr;
            node[i]->right=node[i+1];
        }
    }
};