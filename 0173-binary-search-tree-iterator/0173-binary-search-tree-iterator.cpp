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
class BSTIterator {
public:
    vector<int>temp;
    int curr;
    BSTIterator(TreeNode* root) {
        curr=0;
        inorder(root, temp);
    }
    void inorder(TreeNode * root, vector<int> & temp){
        if(!root){
            return;
        }
        inorder(root->left, temp);

        temp.push_back(root->val);

        inorder(root->right, temp);
    }

    int next() {
        if(curr<temp.size()){
            return temp[curr++];
        }
        return -1;
    }

    bool hasNext() {
        if(curr<temp.size()){
            return true;
        }        
        else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */