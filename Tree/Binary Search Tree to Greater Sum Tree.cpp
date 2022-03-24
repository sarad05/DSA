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
    private:
    void getSum(TreeNode* root,int &sum)
    {
        if(root==NULL)  return;
        getSum(root->right,sum);
        sum+=root->val;
        root->val = sum;
        getSum(root->left,sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        int sum = 0;
        getSum(root,sum);
        return root;
    }
};