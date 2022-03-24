//Recursive Approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(root==NULL)  return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1+max(left,right);
    }
};


//Iterative Approach

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL)
        {
            return 0;
        }
        q.push(root);
        int cnt = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* top = q.front();
                q.pop();
                if(top->left)
                {

                q.push(top->left);
                }
                if(top->right)
                {
                    q.push(top->right);
                }
            }
            cnt++;
        }
        return cnt;
    }
};
