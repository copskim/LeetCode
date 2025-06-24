class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> tq;
        tq.push(root);
        int depth = 0;
        while (!tq.empty()) {
            int levelents = tq.size();
            depth++;
            for (int i = 0; i < levelents; i++) {
                TreeNode* tnptr = tq.front(); tq.pop();
                if (tnptr->left) tq.push(tnptr->left);
                if (tnptr->right) tq.push(tnptr->right);
            }
        }
        return depth;
    }
};