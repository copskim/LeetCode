class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> tnStack;
        tnStack.push(root);
        while (!tnStack.empty()) {
            TreeNode* tnptr = tnStack.top(); tnStack.pop();
            if (tnptr->val == val) return tnptr;
            if (tnptr->right) {
                tnStack.push(tnptr->right);
            }
            if (tnptr->left) {
                tnStack.push(tnptr->left);
            }
        }
        return nullptr;
    }
};