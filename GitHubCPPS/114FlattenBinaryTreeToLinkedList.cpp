class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* r = root;
        stack<TreeNode*> s;
        while (r) {
            s.push(r);
            r = r->right;
        }
        while (!s.empty()) {
            r = s.top(); s.pop();
            if (!r->left) continue;
            moveLNs(r);
        }
    }
private:
    void moveLNs(TreeNode* root) {
        stack<TreeNode*> s;
        stack<TreeNode*> t;
        s.push(root->left);
        while (!s.empty()) {
            TreeNode* r = s.top(); s.pop();
            t.push(r);
            if (r->right) s.push(r->right);
            if (r->left) s.push(r->left);
        }
        while (!t.empty()) {
            TreeNode* r = t.top(); t.pop();
            TreeNode* rsave = root->right;
            root->right = r;
            r->right = rsave;
            r->left = nullptr;
            root->left = nullptr;
        }
    }
};