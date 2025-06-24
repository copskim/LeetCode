class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>{};

        vector<int> rsNodes{};
        queue<TreeNode*> tnQ;
        tnQ.push(root);
        queue<int> lvlQ;
        int curLevel = 1;
        int rsvSoFar = root->val;
        lvlQ.push(curLevel);
        while (!tnQ.empty()) {
            TreeNode* tnptr = tnQ.front(); tnQ.pop();
            int cl = lvlQ.front(); lvlQ.pop();
            if (cl > curLevel) {
                rsNodes.push_back(rsvSoFar); curLevel++;
            }
            rsvSoFar = tnptr->val;
            if (tnptr->left) {
                tnQ.push(tnptr->left);
                lvlQ.push(cl + 1);
            }
            if (tnptr->right) {
                tnQ.push(tnptr->right);
                lvlQ.push(cl + 1);
            }
        }
        rsNodes.push_back(rsvSoFar);
        return rsNodes;
    }
};