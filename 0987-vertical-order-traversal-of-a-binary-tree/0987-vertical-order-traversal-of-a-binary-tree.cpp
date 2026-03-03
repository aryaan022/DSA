/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };[]
 */
class Solution {
public:
    map<int,map<int,vector<int>>> m;
    void dfs(TreeNode* root,int row,int col){
        if(root==NULL){
            return;
        }
        m[col][row].push_back(root->val);
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>result;
        for(auto &p: m){
            vector<int> temp;
            for(auto &q: p.second){
                sort(q.second.begin(),q.second.end());
                for (auto val : q.second) {
                    temp.push_back(val);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};