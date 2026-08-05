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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        int r= preorder[0];
        TreeNode* root=new TreeNode(r);
        int indx=-1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==r){
                indx=i;
            }
        }
        vector<int> leftIn, rightIn;

        for(int i=0;i<indx;i++){
            leftIn.push_back(inorder[i]);
        }

        for(int j=indx+1;j<inorder.size();j++){
            rightIn.push_back(inorder[j]);
        }
        vector<int> leftPre, rightPre;

        for(int i = 1; i <= leftIn.size(); i++){
            leftPre.push_back(preorder[i]);
        }

        for(int i =leftIn.size()+1; i < preorder.size(); i++){
            rightPre.push_back(preorder[i]);
        }
        root->left=buildTree(leftPre,leftIn);
        root->right=buildTree(rightPre,rightIn);
        return root;
        
    }
};