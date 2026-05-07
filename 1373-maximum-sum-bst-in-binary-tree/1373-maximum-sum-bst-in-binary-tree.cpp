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
class Info {
public:
    bool isBST;
    int mini;
    int maxi;
    int sum;

    Info(bool isBST, int mini, int maxi, int sum) {
        this->isBST = isBST;
        this->mini = mini;
        this->maxi = maxi;
        this->sum = sum;
    }
};

class Solution {
public:
    int msum =0;
    Info* SBST(TreeNode* root){
        if(root==NULL){
            return new Info(true,INT_MAX,INT_MIN,0);
        }
        Info* leftinfo=SBST(root->left);
        Info* rightinfo=SBST(root->right);

        int currmin = min(root->val ,min(leftinfo->mini,rightinfo->mini));
        int currmax= max(root->val ,max(leftinfo->maxi,rightinfo->maxi));

        int currsum = leftinfo->sum+rightinfo->sum+root->val;


        if(leftinfo->isBST && rightinfo->isBST && root->val>leftinfo->maxi && root->val<rightinfo->mini){
            msum=max(currsum,msum);
            return new Info(true,currmin,currmax,currsum);
        }

        return new Info(false,currmin,currmax,currsum);
    }

    int maxSumBST(TreeNode* root) {
        SBST(root);
        return msum;
    }
};