
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return -1;
        int maxLevel = -1;
        queue<TreeNode*> tnQ{};
        tnQ.push(root);
        queue<int> lvlQ{};
        int curLevel = 1;
        int curlvlSum = 0;
        int lvlSumMax = INT_MIN;
        lvlQ.push(curLevel);
        while (!tnQ.empty()) {
            TreeNode* tnptr = tnQ.front(); tnQ.pop();
            int cl = lvlQ.front(); lvlQ.pop();
            //            cout << tnptr->val << " " << cl << " " << curLevel << endl;
            if (cl > curLevel) {
                if (curlvlSum > lvlSumMax) {
                    lvlSumMax = curlvlSum;
                    maxLevel = curLevel;
                }
                curlvlSum = tnptr->val;
                curLevel++;
            }
            else curlvlSum += tnptr->val;
            if (tnptr->left) {
                tnQ.push(tnptr->left);
                lvlQ.push(cl + 1);
            }
            if (tnptr->right) {
                tnQ.push(tnptr->right);
                lvlQ.push(cl + 1);
            }
        }
        if (curlvlSum > lvlSumMax) {
            lvlSumMax = curlvlSum;
            maxLevel = curLevel;
        }
        return maxLevel;
    }
};