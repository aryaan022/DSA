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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int s=q.size();
            vector<int>temp(s);
            for(int i =0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                int idx=i;
                if(lvl%2!=0){
                    idx=s-i-1;
                    temp[idx]=curr->val;
                }
                else{
                    temp[idx]=curr->val;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
            lvl++;
        }
        return ans;
    }
};