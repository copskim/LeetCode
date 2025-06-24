class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> tnStack;
        stack<TreeNode*> parStack;
        stack<char> lrStack;
        tnStack.push(root);
        parStack.push(nullptr);
        lrStack.push('U');
        while (!tnStack.empty()) {
            TreeNode* tnptr = tnStack.top(); tnStack.pop();
            TreeNode* parptr = parStack.top(); parStack.pop();
            char lr = lrStack.top(); lrStack.pop();

            if (tnptr->val == key) {
                if (tnptr->left == nullptr && tnptr->right == nullptr) {
                    if (lr == 'U') return nullptr;
                    lr == 'L' ? parptr->left = nullptr : parptr->right = nullptr;
                }
                else if (tnptr->left == nullptr) {
                    if (lr == 'U') return tnptr->right;
                    lr == 'L' ? parptr->left = tnptr->right : parptr->right = tnptr->right;
                }
                else if (tnptr->right == nullptr) {
                    if (lr == 'U') return tnptr->left;
                    lr == 'L' ? parptr->left = tnptr->left : parptr->right = tnptr->left;
                }
                else {
                    TreeNode* rmnode = rightMinNode(tnptr->right);
                    tnptr->val = rmnode->val;
                    tnptr->right = deleteNode(tnptr->right, rmnode->val);
                }
                return root;
            }
            if (tnptr->right) {
                tnStack.push(tnptr->right);
                parStack.push(tnptr);
                lrStack.push('R');
            }
            if (tnptr->left) {
                tnStack.push(tnptr->left);
                parStack.push(tnptr);
                lrStack.push('L');
            }
        }
        return root;
    }
private:
    TreeNode* rightMinNode(TreeNode* h)
    {
        int minval = INT_MAX;
        TreeNode* minnode{};
        while (h != nullptr) {
            if (h->val < minval) {
                minval = h->val;
                minnode = h;
                h = h->left;
            }
        }
        return minnode;
    }
};