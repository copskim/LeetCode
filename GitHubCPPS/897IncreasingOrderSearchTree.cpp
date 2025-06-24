class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* result{}, * t{};
        TreeNode* r = root;
        while (r || !s.empty()) {
            while (r) {
                s.push(r);
                r = r->left;
            }
            r = s.top(); s.pop();
            if (!result) { result = new TreeNode(); t = result; }
            else { t->right = new TreeNode(); t = t->right; }
            t->val = r->val;
            r = r->right;
        }
        return result;
    }
};