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
    void dfs(TreeNode* root,int m,int &count){
        if(!root){
            return;
        }
        if(root->val>=m){
            count++;
        }
        m=max(m,root->val);
        
        dfs(root->left,m,count);
        dfs(root->right,m,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        dfs(root,root->val,count);
        return count;
    }
};