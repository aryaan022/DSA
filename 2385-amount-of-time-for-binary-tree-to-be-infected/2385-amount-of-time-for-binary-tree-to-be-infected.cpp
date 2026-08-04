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
    unordered_map<int,vector<int>>g;
    void GraphCon(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        if(root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
        GraphCon(root->left);
        GraphCon(root->right);
    }
    int amountOfTime(TreeNode* root, int s) {
        GraphCon(root);
        int c=-1;
        unordered_set<int>vis;
        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int s=q.size();
            c++;
            for(int i=0;i<s;i++){
                int curr=q.front();
                vis.insert(curr);
                q.pop();
                //exploring all the neighbours here and pushing them into the queue
                for(auto ne:g[curr]){
                    if(!vis.count(ne)){
                        q.push(ne);
                    }
                }
            }

        }
        return c;

    }
};