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
    int c=0;
    int s=-1;
    void cal(TreeNode* root,int k){
        if(!root){
            return;
        }
        cal(root->left,k);
        c++;
        if(c==k){
            s=root->val;
            return;
        }
        cal(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cal(root,k);
        return s;
    }
};