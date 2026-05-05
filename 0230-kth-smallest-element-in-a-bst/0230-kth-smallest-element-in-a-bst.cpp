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
    vector<int> Inorder(TreeNode* root){
        vector<int>arr;
        if(!root){
            return arr;
        }
        vector<int> left = Inorder(root->left);
        arr.insert(arr.end(), left.begin(), left.end());

        arr.push_back(root->val);

       vector<int> right = Inorder(root->right);
       arr.insert(arr.end(), right.begin(), right.end());

        return arr;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr = Inorder(root);

        return arr[k-1];
    }
};