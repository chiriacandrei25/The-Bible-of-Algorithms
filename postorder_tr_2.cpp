class Solution {
public:
    vector<int> postOrderTraversal(TreeNode* root) {
        const int LEFT_CALL = 0;
        const int RIGHT_CALL = 1;
        const int APPEND_TO_TRAVERSAL = 2;
        vector<int> traversal;
        stack<pair<TreeNode *, int>> stack;
        stack.push({root, LEFT_CALL});
        
        while (!stack.empty()) {
            auto [node, step] = stack.top();
            
            if (node == NULL || step > APPEND_TO_TRAVERSAL) {
                stack.pop();
                continue;
            }
            
            stack.top() = {node, step + 1};

            if (step == LEFT_CALL) {
                stack.push({node->left, LEFT_CALL});
            } else if (step == RIGHT_CALL) {
                stack.push({node->right, LEFT_CALL});
            } else if (step == APPEND_TO_TRAVERSAL) {
                traversal.push_back(node->val);
            }
        }
        
        return traversal;
    }
};


