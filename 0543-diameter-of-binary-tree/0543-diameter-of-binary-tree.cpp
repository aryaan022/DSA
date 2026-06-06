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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int lefth=height(root->left);
        int righth=height(root->right);
        int currh=max(lefth,righth)+1;
        return currh;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int currd = height(root->left)+height(root->right);
        int leftd = diameterOfBinaryTree(root->left);
        int rightd =diameterOfBinaryTree(root->right);
        return max(currd,max(leftd,rightd));
    }
};