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
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        deque<TreeNode*>dq;
        dq.push_back(root);
        int c=1;
        while(!dq.empty()){
            int s=dq.size();
            vector<int>ans;
            for(int i=0;i<s;i++){
                if(c%2!=0){
                    TreeNode* curr = dq.front();
                    dq.pop_front();
                    ans.push_back(curr->val);
                    if(curr->left){
                        dq.push_back(curr->left);
                    }
                    if(curr->right){
                        dq.push_back(curr->right);
                    }
                }
                else{
                    TreeNode* curr =dq.back();
                    dq.pop_back();
                    ans.push_back(curr->val);
                    if(curr->right){
                        dq.push_front(curr->right);
                    }
                    if(curr->left){
                        dq.push_front(curr->left);
                    }
                }

            }
            res.push_back(ans);
            c++;
        }
        return res;
    }
};