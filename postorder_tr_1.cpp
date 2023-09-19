class Solution {
public:
    void dfs(TreeNode* root, vector<int> &result) {
        if (root == NULL) {
            return;
        }
        dfs(root->left, result);
        dfs(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postOrderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};

