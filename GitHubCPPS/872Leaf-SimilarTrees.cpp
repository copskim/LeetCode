class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        stack<TreeNode*> tnStack;
        vector<int> leafs1, leafs2;
        tnStack.push(root1);
        while (!tnStack.empty()) {
            TreeNode* tnptr = tnStack.top(); tnStack.pop();
            if (tnptr->right) tnStack.push(tnptr->right);
            if (tnptr->left) tnStack.push(tnptr->left);
            if (!tnptr->right && !tnptr->left) leafs1.push_back(tnptr->val);
        }
        tnStack.push(root2);
        while (!tnStack.empty()) {
            TreeNode* tnptr = tnStack.top(); tnStack.pop();
            if (tnptr->right) tnStack.push(tnptr->right);
            if (tnptr->left) tnStack.push(tnptr->left);
            if (!tnptr->right && !tnptr->left) leafs2.push_back(tnptr->val);
        }
        auto it1 = leafs1.begin(), it2 = leafs2.begin();
        for (; it1 != leafs1.end() && it2 != leafs2.end() && *it1 == *it2; it1++, it2++) {
        }
        if (it1 == leafs1.end() && it2 == leafs2.end()) return true;
        return false;
    }
};