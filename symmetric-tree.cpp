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
    bool check(TreeNode *rl,TreeNode *rr)
    {
        if(!rr && !rl)
            return true;
        else if(rr && rl)
        {
            if(rr->val!=rl->val)
                return false;
            
            return check(rl->left,rr->right) && check(rl->right,rr->left);
        }
        else
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};
