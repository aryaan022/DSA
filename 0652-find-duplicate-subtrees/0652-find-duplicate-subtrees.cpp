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
    string solve(TreeNode *root, unordered_map<string,int> &m, vector<TreeNode*> &ans){
        if(root == NULL){
            return "N";
        }

        string leftAns = solve(root -> left, m , ans);
        string rightAns = solve(root -> right, m , ans);

        string encode = to_string(root -> val) + "," + leftAns + "," + rightAns;

        if(m.find(encode) != m.end() && m[encode] == 1){ // take for 1st time only
            ans.push_back(root);
        }

        m[encode]++;

        return encode;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> m;
        solve(root,m,ans);
        return ans;
    }
};