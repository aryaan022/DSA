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
    int maxPathSum(TreeNode* root) {
        int result = root->val;
        dfs(root,result);
        return result;

    }
    int dfs(TreeNode* node , int &result){
        if(!node){
            return 0;
        }

        //left max and right max

        int lm= max(0,dfs(node->left,result));
        int rm = max(0,dfs(node->right,result));

        //cacullating result
        result = max(result,lm+rm+node->val);
        return max(lm,rm)+node->val;
    }

};