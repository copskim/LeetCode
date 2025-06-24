class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        stack<pair<long long, long long>> b;
        s.push(root);
        b.push({ -1e11, 1e11 });

        while (!s.empty()) {
            TreeNode* r = s.top(); s.pop();
            auto [lb, rb] = b.top(); b.pop();
            if (r->val <= lb) {
                return false;
            }
            if (r->val >= rb) {
                return false;
            }

            if (r->right) {
                if (r->val >= r->right->val) return false;
                s.push(r->right);
                b.push({ r->val,rb });
            }
            if (r->left) {
                if (r->val <= r->left->val) return false;
                s.push(r->left);
                b.push({ lb,r->val });
            }
        }
        return true;
    }
};